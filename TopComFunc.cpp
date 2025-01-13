// TopComFunc.cpp: implementation of the TopComFunc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TopComFunc.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
QWorksHandle  mQWorksHandle;//PCIE句柄
extern HANDLE hwd;
extern ControlData *pCTLData_Oper;

UINT m_AttControl[MAX_CH][192];//每个通道最大有64组数
//移相器数据
UINT m_PhaseControl[MAX_CH][192];//每个通道最大有64组数

//开关数据
UINT m_SwitchCode[MAX_CH][3];
UINT m_SwitchON_OFF[MAX_CH][3];//1为打开,0为关闭
//RFMHANDLE rh ;

bool TopComFunc::Init1007CFiberCard()
{
	uint devNums = 0xFFFF;
	DWORD m_DeviceID = 0x6014; 
	DWORD m_VendorID = 0x10ee;
	m_1007api.Qworks_OpenDevice(m_DeviceID,m_VendorID,&handle,&devNums);
	if(devNums == 0)
	{
		return false;
	}
	if(m_1007api.Qworks_DMAInit(handle,8192) != 0)
	{
		return false;
	}
	return true;
}

void TopComFunc::ZHENLIE1007CTL(int m_FreqShift)
{
	int frqGroup_Ka;//频点组数单位为组，例如10组
	int frqSpace_Ka;//频率间隔单位为MHz，例如400MHz
	int frqStart_Ka;//起始频率单位为MHz，例如33000MHz

	int frqGroup_2to18;//频点组数单位为组， 40组
	int frqSpace_2to18;//频率间隔单位为MHz，例如400MHz
	int frqStart_2to18;//起始频率单位为MHz，例如2000MHz
	
	frqStart_2to18 = pCTLData_Oper->FreqShift_FreqStart[0];//frqStart_2to18 + frqSpace_2to18 / 4
	frqSpace_2to18 = pCTLData_Oper->FreqShift_PointDist[0] * pCTLData_Oper->FreqShift_DistUnit[0];
	frqGroup_2to18 = pCTLData_Oper->FreqShift_PointNum[0];
	frqStart_Ka = pCTLData_Oper->FreqShift_FreqStart[1] - 4000;//虽然是Ka中频从6G开始，与2-18对齐还是从2G开始设置频率列表，信号源起始频率设置应为：frqStart_Ka + frqSpace_Ka / 4
	frqSpace_Ka = pCTLData_Oper->FreqShift_PointDist[1] * pCTLData_Oper->FreqShift_DistUnit[1];
	frqGroup_Ka = pCTLData_Oper->FreqShift_PointNum[1];

	//这个pCTLData_Oper就是设置频率起始点和间隔之类的参数，通过这个参数设置频率列表，然后通过Qworks_SetVariFrqList设置到PCIE卡上。////////////////////
	//貌似这个就是传入的频率列表参数???

	typedef enum _Ch{Ch1=0,Ch2,Ch3,Ch4,Ch5,Ch6,Ch7,Ch8,Ch9,Ch10,Ch11,Ch12,D_ChNum}Ch;  //总通道
	memset(&sysPara,0,sizeof(sysPara));
//	memset(&variFrqListPara,0,sizeof(variFrqListPara));
	memset(&variFrqListPara_Ka,0,sizeof(variFrqListPara_Ka));
	memset(&variFrqListPara_2to18,0,sizeof(variFrqListPara_2to18));
	memset(&rawPara,255,sizeof(rawPara));
	memset(&wireEnPara,0,sizeof(wireEnPara));
	for(int i=0;i<12;i++)
	{
		memset(&exactPara[i],0,sizeof(exactPara[i]));
	}
	if(m_FreqShift == 0)//捷变频模式
	{
		for(int i = 0; i < 112; i++)//20220406到112
		{
			variFrqListPara_Ka.frqNum=frqGroup_Ka;
			variFrqListPara_Ka.frqNum=frqGroup_Ka * 2;//20220402
//			if(i<frqGroup_Ka)
			if(i<frqGroup_Ka * 2)//20220402修改
			{
//				variFrqListPara_Ka.frequency[i]=frqStart_Ka+frqSpace_Ka*i;
				variFrqListPara_Ka.frequency[i]=frqStart_Ka+frqSpace_Ka / 2 * i + 27000 + 4000;//27000为本振频率
			}
			else
			{
//				variFrqListPara_Ka.frequency[i]=frqStart_Ka+frqSpace_Ka*(frqGroup_Ka-1);
				variFrqListPara_Ka.frequency[i]=frqStart_Ka+frqSpace_Ka*(frqGroup_Ka * 2 - 1) / 2 + 27000 + 4000;
			}
		}
//		variFrqListPara_Ka.frequency[0] = (40 << 16) | variFrqListPara_Ka.frequency[0];//Ka的第一个频点高16位，置为起始点编号，高16位相当于本振频率点数，下位机受到测频点数后，会先减去本振频率点数，然后再乘以频率间隔
		variFrqListPara_Ka.frequency[0] = (27000 << 16) | variFrqListPara_Ka.frequency[0];//Ka的第一个频点高16位，置为起始点编号，高16位相当于本振频率点数，下位机受到测频点数后，会先减去本振频率点数，然后再乘以频率间隔
	}
	else//非捷变频模式
	{
		variFrqListPara_Ka.frqNum=1;
		for(int i=0;i<112;i++)//20220406到112
		{
			variFrqListPara_Ka.frequency[i]=frqStart_Ka;
		}
	}

	//2-18捷变频参数
//	if(frqMode_2to18)//捷变频模式
	if(m_FreqShift == 0)//捷变频模式
	{
		for(int i = 0; i < 112; i++)//20220406到112
		{
//			variFrqListPara_2to18.frqNum=frqGroup_2to18;
			variFrqListPara_2to18.frqNum=frqGroup_2to18 * 2;//20220402
//			if(i<frqGroup_2to18)
			if(i<frqGroup_2to18 * 2)//20220402修改
			{
//				variFrqListPara_2to18.frequency[i]=frqStart_2to18+frqSpace_2to18*i;
				variFrqListPara_2to18.frequency[i]=frqStart_2to18+frqSpace_2to18 / 2 * i;//20220402修改
			}
			else
			{
//				variFrqListPara_2to18.frequency[i]=frqStart_2to18+frqSpace_2to18*(frqGroup_2to18-1);
				variFrqListPara_2to18.frequency[i]=frqStart_2to18+frqSpace_2to18*(frqGroup_2to18 * 2 - 1) / 2;
			}
		}
	}
	else//非捷变频模式
	{
		variFrqListPara_2to18.frqNum=1;
		for(int i=0;i<112;i++)//20220406到112
		{
			variFrqListPara_2to18.frequency[i]=frqStart_2to18;
		}
	}

	//以上是捷变频和非捷变频模式下KA和2-18的频率列表设置，KA多了个在非捷变频模式下的移位，目前还不是很清楚.........///////////////////////////////
	//设置的分别是频率点数和每一个通道具体的频率值(12个通道，每个通道112个频点)

	//这个m_TDData就是设置测试数据参数，通过这个参数设置测试数据，然后通过Qworks_SetTestPara设置到PCIE卡上。也是外部传入的参数/////////////////////////
	//当FPGA硬件接到信号时启动外部同步否则均为内部，各通道状态均为独立配置,延迟控制只有在捷变频模式下起作用
	unsigned int FreqSel = m_TDData.FreqSel;//测频码传输选择，毫米波设置9-12通道，2-18GHz设置1-8通道,12位由低到高每一位代表一个通道；0选择低位7位暂时对应模拟器2，1选择高7位暂时对应模拟器1, 例如：0xF00
	unsigned int totalDelay = m_TDData.totalDelay;//总延时，单位为10us
	unsigned int Ch1Delay = m_TDData.Ch1Delay;//通道1延时时戳，单位为10us
	unsigned int Ch1Period = m_TDData.Ch1Period;//通道1脉冲周期，脉冲周期为0时不启动，单位为10us
	unsigned int Ch2Delay = m_TDData.Ch2Delay;//通道2延时时戳
	unsigned int Ch2Period = m_TDData.Ch2Period;//通道2脉冲周期，脉冲周期为0时不启动
	unsigned int Ch3Delay = m_TDData.Ch3Delay;//通道3延时时戳
	unsigned int Ch3Period = m_TDData.Ch3Period;//通道3脉冲周期，脉冲周期为0时不启动
	unsigned int Ch4Delay = m_TDData.Ch4Delay;//通道4延时时戳
	unsigned int Ch4Period = m_TDData.Ch4Period;//通道4脉冲周期，脉冲周期为0时不启动
	unsigned int Ch5Delay = m_TDData.Ch5Delay;//通道5延时时戳
	unsigned int Ch5Period = m_TDData.Ch5Period;//通道5脉冲周期，脉冲周期为0时不启动
	unsigned int Ch6Delay = m_TDData.Ch6Delay;//通道6延时时戳
	unsigned int Ch6Period = m_TDData.Ch6Period;//通道6脉冲周期，脉冲周期为0时不启动
	unsigned int Ch7Delay = m_TDData.Ch7Delay;//通道7延时时戳
	unsigned int Ch7Period = m_TDData.Ch7Period;//通道7脉冲周期，脉冲周期为0时不启动
	unsigned int Ch8Delay = m_TDData.Ch8Delay;//通道8延时时戳
	unsigned int Ch8Period = m_TDData.Ch8Period;//通道8脉冲周期，脉冲周期为0时不启动
	unsigned int Ch9Delay = m_TDData.Ch9Delay;//通道9延时时戳
	unsigned int Ch9Period = m_TDData.Ch9Period;//通道9脉冲周期，脉冲周期为0时不启动
	unsigned int Ch10Delay = m_TDData.Ch10Delay;//通道10延时时戳
	unsigned int Ch10Period = m_TDData.Ch10Period;//通道10脉冲周期，脉冲周期为0时不启动
	unsigned int Ch11Delay = m_TDData.Ch11Delay;//通道11延时时戳
	unsigned int Ch11Period = m_TDData.Ch11Period;//通道11脉冲周期，脉冲周期为0时不启动
	unsigned int Ch12Delay = m_TDData.Ch12Delay;//通道12延时时戳
	unsigned int Ch12Period = m_TDData.Ch12Period;//通道12脉冲周期，脉冲周期为0时不启动

	sysPara.chWorkFrq[0] = 0;//通道工作频率一共15个位置，实际使用12个位置，最后1个位置写总延时数据
	sysPara.chWorkFrq[12]=FreqSel;//测频码传输选择，毫米波设置9-12通道，2-18GHz设置1-8通道,12位由低到高每一位代表一个通道；0选择低位7位暂时对应模拟器2，1选择高7位暂时对应模拟器1
	sysPara.chWorkFrq[14]=totalDelay;//通道工作频率一共15个位置，实际使用12个位置，最后1个位置写总延时数据

	//延时时戳和脉冲周期（频点一共128个位置，实际使用100个位置，后12个位置写延时时戳和脉冲周期数据）
    variFrqListPara_2to18.frequency[116]=Ch1Period<<16|Ch1Delay;//延时时戳在低16位,脉冲周期在高16位
	variFrqListPara_2to18.frequency[117]=Ch2Period<<16|Ch2Delay;
	variFrqListPara_2to18.frequency[118]=Ch3Period<<16|Ch3Delay;
	variFrqListPara_2to18.frequency[119]=Ch4Period<<16|Ch4Delay;
	variFrqListPara_2to18.frequency[120]=Ch5Period<<16|Ch5Delay;
	variFrqListPara_2to18.frequency[121]=Ch6Period<<16|Ch6Delay;
	variFrqListPara_2to18.frequency[122]=Ch7Period<<16|Ch7Delay;
	variFrqListPara_2to18.frequency[123]=Ch8Period<<16|Ch8Delay;
	variFrqListPara_2to18.frequency[124]=Ch9Period<<16|Ch9Delay;
	variFrqListPara_2to18.frequency[125]=Ch10Period<<16|Ch10Delay;
	variFrqListPara_2to18.frequency[126]=Ch11Period<<16|Ch11Delay;
	variFrqListPara_2to18.frequency[127]=Ch12Period<<16|Ch12Delay;

	//工作模式
//	sysPara.workMode=WorkModeWork;//在非捷变频状态下，工作模式与测试模式相同，一般直接设置为工作模式兼顾捷变频与非捷变频
	sysPara.workMode=WorkModeTest;
//	sysPara.oscPara.outputFrq = 20;
	//通道使能

	//工作频率
//	sysPara.chWorkFrq[ch]=GetDlgItemInt(IDC_CHFREQ);//暂时先不设置20210204
	int i, k;
	uint ch;
	short Mid_Short1, Mid_Short2;
	DWORD Mid_Dword;
	union     // Declare union type
	{
		unsigned char CMD[4];
		DWORD  d;
	} myvar;

	if(m_FreqShift == 1)//非捷变频模式
	{
		sysPara.frqMode = FrqModeInvari;
		sysPara.chEn= 0xFFFF;//毫米波设置9-12通道，2-18GHz设置1-8通道,16位由低到高每一位代表一个通道，0为所有衰减器衰减，1为所有衰减器接收上位机命令
 		for(i = 0; i < 12; i++)
		{
			ch = i;

			myvar.d = m_SwitchCode[i][0];
			//A支路
			//粗控控制
			rawPara.rawUnit[ch].switch1st_A= myvar.CMD[0];
			rawPara.rawUnit[ch].switch2nd_A= myvar.CMD[1];
			rawPara.rawUnit[ch].switch3rd_A= myvar.CMD[2];
			//精控控制
			Mid_Dword = m_AttControl[i][0];
			Mid_Short1 = Mid_Dword & 0x7ff;
			Mid_Short2 = (Mid_Dword & 0x800) >> 11;
			exactPara[ch].exactUnit_A[0].attenuation1=Mid_Short1;
			exactPara[ch].exactUnit_A[0].attenuation2=Mid_Short2;
			exactPara[ch].exactUnit_A[0].phase=m_PhaseControl[i][0];

			myvar.d = m_SwitchCode[i][1];
			//B支路
			//粗控控制
			rawPara.rawUnit[ch].switch1st_B=myvar.CMD[0];
			rawPara.rawUnit[ch].switch2nd_B=myvar.CMD[1];
			rawPara.rawUnit[ch].switch3rd_B=myvar.CMD[2];
			//精控控制
			Mid_Dword = m_AttControl[i][1];
			Mid_Short1 = Mid_Dword & 0x7ff;
			Mid_Short2 = (Mid_Dword & 0x800) >> 11;
			exactPara[ch].exactUnit_B[0].attenuation1=Mid_Short1;
			exactPara[ch].exactUnit_B[0].attenuation2=Mid_Short2;
			exactPara[ch].exactUnit_B[0].phase=m_PhaseControl[i][1];

			myvar.d = m_SwitchCode[i][2];
			//C支路
			//粗控控制
			rawPara.rawUnit[ch].switch1st_C=myvar.CMD[0];
			rawPara.rawUnit[ch].switch2nd_C=myvar.CMD[1];
			rawPara.rawUnit[ch].switch3rd_C=myvar.CMD[2];
			//精控控制
			Mid_Dword = m_AttControl[i][2];
			Mid_Short1 = Mid_Dword & 0x7ff;
			Mid_Short2 = (Mid_Dword & 0x800) >> 11;
			exactPara[ch].exactUnit_C[0].attenuation1=Mid_Short1;
			exactPara[ch].exactUnit_C[0].attenuation2=Mid_Short2;
			exactPara[ch].exactUnit_C[0].phase=m_PhaseControl[i][2];
		}	
	}
	if(m_FreqShift == 0)//捷变频模式
	{
		sysPara.frqMode = FrqModeVari;
		sysPara.chEn= 0xFFFF;//毫米波设置9-12通道，2-18GHz设置1-8通道,16位由低到高每一位代表一个通道，0为所有衰减器衰减，1为所有衰减器接收上位机命令
		for(i = 0; i < 8; i++)
		{
			ch = i;
			for(k = 0; k < 64; k++)
			{
				if(k <= frqGroup_2to18)
				{
					myvar.d = m_SwitchCode[i][0];
					//A支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_A= myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_A= myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_A= myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][0 + 3 * (k + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_A[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k].phase=m_PhaseControl[i][0 + 3 * (k + 1)];//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].phase=m_PhaseControl[i][0 + 3 * (k + 1)];//20220402

					myvar.d = m_SwitchCode[i][1];
					//B支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_B=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_B=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_B=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][1 + 3 * (k + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_B[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k].phase=m_PhaseControl[i][1 + 3 * (k + 1)];//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].phase=m_PhaseControl[i][1 + 3 * (k + 1)];//20220402

					myvar.d = m_SwitchCode[i][2];
					//C支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_C=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_C=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_C=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][2 + 3 * (k + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_C[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k].phase=m_PhaseControl[i][2 + 3 * (k + 1)];//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].phase=m_PhaseControl[i][2 + 3 * (k + 1)];//20220402
				}
				else
				{
					myvar.d = m_SwitchCode[i][0];
					//粗控控制
					rawPara.rawUnit[ch].switch1st_A= myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_A= myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_A= myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][0 + 3 * (frqGroup_2to18 + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_A[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k].phase=m_PhaseControl[i][0 + 3 * (frqGroup_2to18 + 1)];//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].phase=m_PhaseControl[i][0 + 3 * (frqGroup_2to18 + 1)];//20220402

					myvar.d = m_SwitchCode[i][1];
					//B支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_B=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_B=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_B=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][1 + 3 * (frqGroup_2to18 + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_B[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k].phase=m_PhaseControl[i][1 + 3 * (frqGroup_2to18 + 1)];//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].phase=m_PhaseControl[i][1 + 3 * (frqGroup_2to18 + 1)];//20220402

					myvar.d = m_SwitchCode[i][2];
					//C支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_C=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_C=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_C=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][2 + 3 * (frqGroup_2to18 + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_C[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k].phase=m_PhaseControl[i][2 + 3 * (frqGroup_2to18 + 1)];//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].phase=m_PhaseControl[i][2 + 3 * (frqGroup_2to18 + 1)];//20220402
				}
			}
		}
 		for(i = 8; i < 12; i++)
		{
			ch = i;
			for(k = 0; k < 64; k++)
			{
				if(k <= frqGroup_Ka)
				{
					myvar.d = m_SwitchCode[i][0];
					//A支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_A= myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_A= myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_A= myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][0 + 3 * (k + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_A[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k].phase=m_PhaseControl[i][0 + 3 * (k + 1)];//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].phase=m_PhaseControl[i][0 + 3 * (k + 1)];//20220402

					myvar.d = m_SwitchCode[i][1];
					//B支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_B=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_B=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_B=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][1 + 3 * (k + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_B[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k].phase=m_PhaseControl[i][1 + 3 * (k + 1)];//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].phase=m_PhaseControl[i][1 + 3 * (k + 1)];//20220402

					myvar.d = m_SwitchCode[i][2];
					//C支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_C=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_C=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_C=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][2 + 3 * (k + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_C[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k].phase=m_PhaseControl[i][2 + 3 * (k + 1)];//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].phase=m_PhaseControl[i][2 + 3 * (k + 1)];//20220402
				}
				else
				{
					myvar.d = m_SwitchCode[i][0];
					//A支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_A= myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_A= myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_A= myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][0 + 3 * (frqGroup_Ka + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_A[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k].phase=m_PhaseControl[i][0 + 3 * (frqGroup_Ka + 1)];//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_A[2 * k + 1].phase=m_PhaseControl[i][0 + 3 * (frqGroup_Ka + 1)];//20220402

					myvar.d = m_SwitchCode[i][1];
					//B支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_B=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_B=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_B=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][1 + 3 * (frqGroup_Ka + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_B[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k].phase=m_PhaseControl[i][1 + 3 * (frqGroup_Ka + 1)];//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_B[2 * k + 1].phase=m_PhaseControl[i][1 + 3 * (frqGroup_Ka + 1)];//20220402

					myvar.d = m_SwitchCode[i][2];
					//C支路
					//粗控控制
					rawPara.rawUnit[ch].switch1st_C=myvar.CMD[0];
					rawPara.rawUnit[ch].switch2nd_C=myvar.CMD[1];
					rawPara.rawUnit[ch].switch3rd_C=myvar.CMD[2];
					//精控控制
					Mid_Dword = m_AttControl[i][2 + 3 * (frqGroup_Ka + 1)];
					Mid_Short1 = Mid_Dword & 0x7ff;
					Mid_Short2 = (Mid_Dword & 0x800) >> 11;
					exactPara[ch].exactUnit_C[2 * k].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k].phase=m_PhaseControl[i][2 + 3 * (frqGroup_Ka + 1)];//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation1=Mid_Short1;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].attenuation2=Mid_Short2;//20220402
					exactPara[ch].exactUnit_C[2 * k + 1].phase=m_PhaseControl[i][2 + 3 * (frqGroup_Ka + 1)];//20220402
				}
			}
		}
	}

	//通过QICDe协议下发数据
	m_1007api.Qworks_Sleep(0.00005);
	m_1007api.Qworks_PCIWrite32(handle,0,0x30,0x10001);

	m_1007api.loadParaCmd(handle,sysPara,variFrqListPara_2to18,exactPara[Ch1],exactPara[Ch2]);
	m_1007api.loadExact2ParaCmd(handle,exactPara[Ch3],exactPara[Ch4]);
	m_1007api.loadExact3ParaCmd(handle,exactPara[Ch5],exactPara[Ch6]);
	m_1007api.loadExafct4ParaCmd(handle,exactPara[Ch7],exactPara[Ch8]);
	m_1007api.loadExact5ParaCmd(handle,exactPara[Ch9],exactPara[Ch10]);
	m_1007api.loadExact6ParaCmd(handle,exactPara[Ch11],exactPara[Ch12]);
	m_1007api.loadRawParaCmd(handle,rawPara,wireEnPara,true);

	m_1007api.Qworks_Sleep(0.00005);
	m_1007api.Qworks_PCIWrite32(handle,0,0x30,0x10002);
	m_1007api.loadParaCmd(handle,sysPara,variFrqListPara_2to18,exactPara[Ch1],exactPara[Ch2]);
	m_1007api.loadExact2ParaCmd(handle,exactPara[Ch3],exactPara[Ch4]);
	m_1007api.loadExact3ParaCmd(handle,exactPara[Ch5],exactPara[Ch6]);
	m_1007api.loadExact4ParaCmd(handle,exactPara[Ch7],exactPara[Ch8]);
	m_1007api.loadExact5ParaCmd(handle,exactPara[Ch9],exactPara[Ch10]);
	m_1007api.loadExact6ParaCmd(handle,exactPara[Ch11],exactPara[Ch12]);
	m_1007api.loadRawParaCmd(handle,rawPara,wireEnPara,true);

	m_1007api.Qworks_Sleep(0.00005);
	m_1007api.Qworks_PCIWrite32(handle,0,0x30,0x10004);
	m_1007api.loadParaCmd(handle,sysPara,variFrqListPara_Ka,exactPara[Ch1],exactPara[Ch2]);
	m_1007api.loadExact2ParaCmd(handle,exactPara[Ch3],exactPara[Ch4]);
	m_1007api.loadExact3ParaCmd(handle,exactPara[Ch5],exactPara[Ch6]);
	m_1007api.loadExact4ParaCmd(handle,exactPara[Ch7],exactPara[Ch8]);
	m_1007api.loadExact5ParaCmd(handle,exactPara[Ch9],exactPara[Ch10]);
	m_1007api.loadExact6ParaCmd(handle,exactPara[Ch11],exactPara[Ch12]);
	m_1007api.loadRawParaCmd(handle,rawPara,wireEnPara,true);
}
