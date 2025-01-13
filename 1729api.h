// #include "windriver/windrvr.h"
// #include "windriver/wdc_lib.h"
// #include "windriver/wdc_defs.h"



#define Time1us         0.000001f
#define Time10us        0.00001
#define Time1ms         0.001
#define Time10ms        0.01

typedef void* DeviceHandle;

#define MaxDevsSum  256
#define RAM_BUF_SIZE 8192

typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long long ulonglong;
typedef long long int64;

enum EnumError{
    Err_Success         =  0,
    Err_Error           = -1,
    Err_DriverOpen      = -2,
    Err_ScanDevices     = -3,
    Err_GetDeviceInfo   = -4,
    Err_DeviceOpen      = -5,
    Err_DmaBufLock      = -6,
    Err_PortNoFunc      = -7,
    Err_Port            = -8,
    Err_Switch          = -9,
    Err_ParaRange       = -10,
    Err_CmdRange        = -11,
    Err_DevNum          = -12,
    Err_Interrupt       = -13,
    Err_BitState        = -14,
    Err_BitF0F1Link     = -15,
    Err_HQNFBusy        = -16,
    Err_HQNFFree        = -17,
    Err_SocketInit      = -18,
    Err_SocketBind      = -19,
    Err_SocketConnect   = -20,
    Err_SocketSend      = -21,
    Err_SocketRecv      = -22,
    Err_Busy            = -23,
    Err_HQNFControl     = -24,
    Err_TimeOut         = -25,
    Err_Mutex           = -26,
    Err_NotConf         = -27,
    Err_MsgFrame        = -28,
    Err_Ready           = -29,
    Err_Malloc          = -30,
    Err_OpenFile        = -31,
    Err_NotExist        = -32,
    Err_Match           = -33,
    Err_DMA             = -34,
	Err_Again           = -35,
	Err_PacketLoss      = -36,
	Err_Check           = -37
};

typedef struct QWorksHandle1007 {
    DeviceHandle DeviceHandle;                    ///< device handle
    uint  BaseAddr;                                ///< switch baseaddr
    int   DevicePort;                              ///< board type
    int   DevsStatus;
    int   DeviceSwitch;
    int   DeviceProg;
    int   TCP_idle_time;
    int   BusAddr;                                 ///< slot addr(pcie)
    char  BusName[32];                             ///< slot name
    char  Name[256];                               ///< board name
    uchar SercNum;                                 ///< Serial port handle
	int dev_id;
    int timeout;
    char  TempBuf[8192];

    WD_DMA *DmaHandle;
    void *DmaBuf;
	WD_DMA *DmaHandle2;
	void *DmaBuf2;
    HANDLE mutex;
}QWorksHandle1007;


#ifndef QICDE_TYPECONST_H
#define QICDE_TYPECONST_H

#define FRAME_HEAD_ICDE (0x5A5A5A5A)
#define FRAME_END_ICDE  (0xA5A5A5A5)

typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned long long ulonglong;
typedef long long int64;

typedef enum {
    ID_CtrlCmd             = 0x0000,        ///<控制指令
    ID_ReturnReadCmd       = 0x0A03,        ///<回读指令
    ID_ArraySysPara        = 0x0F00,        ///<系统参数
    ID_FrqListSend         = 0x0F01,        ///<捷变频频率列表传输
    ID_Ch1ExactPara        = 0x0F10,        ///<通道一精控单元
    ID_Ch2ExactPara        = 0x0F11,        ///<通道二精控单元
    ID_Ch3ExactPara        = 0x0F12,        ///<通道三精控单元
    ID_Ch4ExactPara        = 0x0F13,        ///<通道四精控单元
    ID_Ch5ExactPara        = 0x0F14,        ///<通道五精控单元
    ID_Ch6ExactPara        = 0x0F15,        ///<通道六精控单元
    ID_Ch7ExactPara        = 0x0F16,        ///<通道七精控单元
    ID_Ch8ExactPara        = 0x0F17,        ///<通道八精控单元
    ID_Ch9ExactPara        = 0x0F18,        ///<通道九精控单元
    ID_Ch10ExactPara       = 0x0F19,        ///<通道十精控单元
    ID_Ch11ExactPara       = 0x0F1A,        ///<通道十一精控单元
    ID_Ch12ExactPara       = 0x0F1B,        ///<通道十二精控单元
    ID_Ch13ExactPara       = 0x0F1C,        ///<通道十三精控单元
    ID_Ch14ExactPara       = 0x0F1D,        ///<通道十四精控单元
    ID_Ch15ExactPara       = 0x0F1E,        ///<通道十五精控单元
    ID_RawPara             = 0x0F20,        ///<粗控单元
    ID_WireEnCtrl          = 0x0F30,        ///<天线使能控制单元
    ID_TestFrqCodeData     = 0x0F50,        ///<测频码数据
}HqArrayCmdID;


/**
 * @brief The CtrlCmd typedef enum 控制命令枚举值
 */
typedef enum {
    CmdRestore = 0,                         ///<复位指令
    CmdStart,                               ///<开始指令
    CmdFree,                                ///<空闲指令
    CmdStop,                                ///<停止指令
}ArrayCtrlCmd;

/**
* @brief 工作模式枚举
*/
typedef enum {
    WorkModeTest = 0,                       ///<测试模式
    WorkModeWork,                           ///<工作模式
}ArrayWorkMode;

/**
* @brief 变频模式枚举
*/
typedef enum {
    FrqModeInvari = 0,                      ///<定频模式
    FrqModeVari,                            ///<捷变频模式
}ArrayFrqMode;

/**
* @brief 干扰参数结构
*/
typedef struct{
    short disturbEn;                        ///<干扰使能
    char switch1st;                         ///<开关1
    char switch2nd;                         ///<开关2
}ArrayDisturbPara;

/**
* @brief 接收参数结构
*/
typedef struct{
    short receiveEn;                        ///<接收使能
    char switch1st;                         ///<开关1
    char switch2nd;                         ///<开关2
}ArrayReceivePara;

/**
* @brief 本振参数结构
*/
typedef struct{
    short refMode;                          ///<参考模式
    short outRefFrq;                        ///<外参考频率
    int outputFrq;                          ///<本振输出功率
}ArrayOscPara;

/**
* @brief 系统参数结构
*/
typedef struct{
    ArrayWorkMode workMode;                 ///<工作模式
    ArrayFrqMode frqMode;                   ///<频率捷变模式
    int chNum;                              ///<通道数量
    int chEn;                               ///<通道使能
    ArrayDisturbPara disturbPara;           ///<干扰参数
    ArrayReceivePara receivePara;           ///<接收参数
    ArrayOscPara oscPara;                   ///<本振参数
    int chWorkFrq[15];                      ///<通道工作频率
}ArraySysPara;

/**
* @brief 捷变频频率列表传输指令参数结构
*/
typedef struct{
    int frqNum;                             ///<频率点数
    int frequency[128];                     ///<频率
}ArrayVariFrqListPara;

/**
* @brief 粗控单元结构
*/
typedef struct{
    char switch1st_A;                       ///<A支路一级开关
    char switch2nd_A;                       ///<A支路二级开关
    char switch3rd_A;                       ///<A支路三级开关
    char null_A;                            ///<为了凑足32bit
    char switch1st_B;                       ///<B支路一级开关
    char switch2nd_B;                       ///<B支路二级开关
    char switch3rd_B;                       ///<B支路三级开关
    char null_B;                            ///<为了凑足32bit
    char switch1st_C;                       ///<C支路一级开关
    char switch2nd_C;                       ///<C支路二级开关
    char switch3rd_C;                       ///<C支路三级开关
    char null_C;                            ///<为了凑足32bit
}ArrayRawUnit;

/**
* @brief 粗控参数结构
*/
typedef struct{
    ArrayRawUnit rawUnit[15];             ///<15个通道
}ArrayRawPara;

/**
* @brief 天线使能参数结构
*/
typedef struct{
    int wireEn[64];                         ///<每个天线占1bit,最多2048个天线
    int fillZero;                           ///补零
}ArrayWireEnPara;

/**
* @brief 精控单元结构
*/
typedef struct{
    int phase;                              ///<移相器
    short attenuation1;                     ///<衰减器1
    short attenuation2;                     ///<衰减器2
}ArrayExactUnit;

/**
* @brief 精控参数结构
*/
typedef struct{
    ArrayExactUnit exactUnit_A[128];        ///<A支路128个频点
    ArrayExactUnit exactUnit_B[128];        ///<B支路128个频点
    ArrayExactUnit exactUnit_C[128];        ///<C支路128个频点
    int fillZero;                           ///补零
}ArrayExactPara;

#endif // QICDE_TYPECONST_H

#define BZERO(buf) memset(&(buf), 0, sizeof(buf))
class Test1729api
{
// 构造
public:
	int test();
	int Qworks_OpenDevice(uint DeviceID, uint VendorID, struct QWorksHandle1007** handles, uint *DevNums);
	void Qworks_Sleep(double waittime);
	int Qworks_PciWriteReg32(DeviceHandle Devs, uint AddrSpace, uint OffSet, uint Val);
	int Qworks_PCIWrite32(struct QWorksHandle1007* h, uint AddrSpace, uint OffSet, uint Val);
	int Qworks_DMAInit(struct QWorksHandle1007* h, size_t size);
	int Qworks_PciReadReg32(DeviceHandle Devs, uint AddrSpace, uint OffSet, uint *Val);
	int Qworks_PCIRead32(struct QWorksHandle1007* h, uint AddrSpace, uint OffSet, uint *Val);
	int Qworks_DMARead(struct QWorksHandle1007* h, char *pData, uint Bytes, double TimeOut);
	int Qworks_DMAWrite(struct QWorksHandle1007* h, char *pData, uint Bytes, double TimeOut);


	EnumError loadParaCmd(QWorksHandle1007* handle,ArraySysPara sysPara,ArrayVariFrqListPara variFrqListPara,
                            ArrayExactPara ch1ExactPara, ArrayExactPara ch2ExactPara);
	EnumError loadRawParaCmd(QWorksHandle1007* handle,ArrayRawPara rawPara,ArrayWireEnPara wireEnPara,bool readReturnFlag);
	EnumError loadExact2ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch3ExactPara, ArrayExactPara ch4ExactPara);
	EnumError loadExact3ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch5ExactPara, ArrayExactPara ch6ExactPara);
	EnumError loadExact4ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch7ExactPara, ArrayExactPara ch8ExactPara);
	EnumError loadExact5ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch9ExactPara, ArrayExactPara ch10ExactPara);
	EnumError loadExact6ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch11ExactPara, ArrayExactPara ch12ExactPara);
	EnumError loadExact7ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch13ExactPara, ArrayExactPara ch14ExactPara);
	EnumError loadExact8ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch15ExactPara);
// 实现
private:


};