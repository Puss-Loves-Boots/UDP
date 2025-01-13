#include <stdio.h>
#include "stdafx.h"
#include "1729api.h"

//#pragma comment(lib, "C:/WinDriver/lib/amd64/wdapi1021.lib")
//#define WINDRIVER_LICENSE "6C3CC2CFE89E7AD0424A070D434A6F6DC495401F.embrace" //WinDriver10.21 license

int Test1729api::Qworks_OpenDevice(uint DeviceID, uint VendorID, struct QWorksHandle1007** handles, uint *DevNums)
{
    uint i;
    *DevNums = 0;
    /****Open WinDriver****/
    uint ret;
    ret = WDC_DriverOpen(WDC_DRV_OPEN_DEFAULT, "6C3CC2CFE89E7AD0424A070D434A6F6DC495401F.embrace");
    if (!((ret != WD_STATUS_SUCCESS) || (ret !=WD_OPERATION_ALREADY_DONE))) {
        return Err_DriverOpen;
    }

    WDC_PCI_SCAN_RESULT scanResult;
    /****Scan pci or pci-e Devices****/
    BZERO(scanResult);
    if (WDC_PciScanDevices(VendorID, DeviceID, &scanResult) != WD_STATUS_SUCCESS) {
        return Err_ScanDevices;
    }
    if (scanResult.dwNumDevices == 0) {
        return Err_ScanDevices;
    }

    struct QWorksHandle1007* hs = (struct QWorksHandle1007*)malloc(sizeof(struct QWorksHandle1007) * scanResult.dwNumDevices);

    *handles = hs;

//    WD_PCI_CARD_INFO deviceInfo[MaxDevsSum];
    WD_PCI_CARD_INFO deviceInfo[1];//就1块卡，申请那么大的空间干嘛用
    memset(deviceInfo, 0, sizeof(deviceInfo));
    for (i=0;i<scanResult.dwNumDevices;i++) {
        deviceInfo[i].pciSlot = scanResult.deviceSlot[i];
        /****Get Device Infomation****/
        if (WDC_PciGetDeviceInfo(&deviceInfo[i]) != WD_STATUS_SUCCESS) {
            continue;
        }
        /****Device Open Get Handle****/
        if(WDC_PciDeviceOpen(&hs[*DevNums].DeviceHandle, &deviceInfo[i], NULL, NULL, NULL,
                             NULL) != WD_STATUS_SUCCESS) {
            continue;
        }
        *DevNums += 1;
    }
    if (*DevNums == 0) {
        return Err_DeviceOpen;
    }
    return Err_Success;
}


void Test1729api::Qworks_Sleep(double waittime)
{
    LARGE_INTEGER litmp;
    LONGLONG QPart1, QPart2;

    double dfMinus, dfFreq, dfTim;

    QueryPerformanceFrequency(&litmp);
    dfFreq = (double)litmp.QuadPart;

    QueryPerformanceCounter(&litmp);
    QPart1 = litmp.QuadPart;

    do {
        QueryPerformanceCounter(&litmp);
        QPart2 = litmp.QuadPart;
        dfMinus = (double)(QPart2 - QPart1);
        dfTim = dfMinus / dfFreq;
    } while (dfTim < waittime);
}

int Test1729api::Qworks_PciWriteReg32(DeviceHandle Devs, uint AddrSpace, uint OffSet,
                         uint Val)
{
	int ret = WDC_WriteAddr32(Devs, AddrSpace, OffSet, Val);
	if (ret != WD_STATUS_SUCCESS) {
		puts("WDC_WriteAddr32 Failed");
		return Err_Error;
	}
    return Err_Success;
}

int Test1729api::Qworks_PCIWrite32(struct QWorksHandle1007* h, uint AddrSpace, uint OffSet, uint Val)
{
	int ret = Qworks_PciWriteReg32(h->DeviceHandle, AddrSpace, OffSet, Val);
	return ret;
}

int Test1729api::Qworks_DMAInit(struct QWorksHandle1007* h, size_t size)
{
    int Ret;
    Ret = WDC_DMAContigBufLock(h->DeviceHandle, &h->DmaBuf,
                               DMA_ALLOW_CACHE | DMA_TO_FROM_DEVICE,
							   size + 8192, &h->DmaHandle);
    if (Ret == WD_STATUS_SUCCESS) {
        Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x08, (uint)h->DmaHandle->Page[0].pPhysicalAddr);
        Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x0c, size / 4);
        Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x1c, (uint)h->DmaHandle->Page[0].pPhysicalAddr);
        Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x20, size / 4);
	}
	else{
		return Err_Error;
	}
    return Err_Success;
}

int Test1729api::Qworks_PciReadReg32(DeviceHandle Devs, uint AddrSpace, uint OffSet, uint *Val)
{
    int ret = WDC_ReadAddr32(Devs, AddrSpace, OffSet, Val);
	if (ret != WD_STATUS_SUCCESS) {
		puts("WDC_ReadAddr32 Failed");
		return Err_Error;
	}
    return Err_Success;
}

int Test1729api::Qworks_PCIRead32(struct QWorksHandle1007* h, uint AddrSpace, uint OffSet, uint *Val)
{
	int ret = Err_Success;
	ret = Qworks_PciReadReg32(h->DeviceHandle, AddrSpace, OffSet, Val);
	return ret;
}

int Test1729api::Qworks_DMARead(struct QWorksHandle1007* h, char *pData, uint Bytes, double TimeOut)
{
	int port = h->DevicePort;
	int ret = Err_Success;
	int flag = Err_Success;
	double time = 0;

	memset(pData, 0, Bytes);
	memset(h->DmaBuf, 0, Bytes + 8);
	Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x0, 0x1);
	Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x0, 0x0);
	Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x4, 0x1);
	while (0x78563412 != *((uint*)(h->DmaBuf) + Bytes / 4)){
		Qworks_Sleep(Time1us);
		time += Time1us;
		if (time > TimeOut) {
			return Err_TimeOut;
		}
	}
	memcpy(pData, h->DmaBuf, Bytes);

	return ret;
}

int Test1729api::Qworks_DMAWrite(struct QWorksHandle1007* h, char *pData, uint Bytes, double TimeOut)
{
	double time = 0;
	int flag = Err_Success;
	int ret = Err_Success;

	memset(h->DmaBuf, 0, Bytes + 8);
	memcpy(h->DmaBuf, pData, Bytes);
	Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x0, 0x1);
	Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x0, 0x0);
	Qworks_PciWriteReg32(h->DeviceHandle, 0, 0x4, 0x10000);
	while (0x78563412 != *((uint*)(h->DmaBuf) + Bytes / 4)){
		Qworks_Sleep(Time1us);
	}
	return ret;
}

EnumError Test1729api::loadParaCmd(QWorksHandle1007* handle,ArraySysPara sysPara,ArrayVariFrqListPara variFrqListPara,
                            ArrayExactPara ch1ExactPara, ArrayExactPara ch2ExactPara)
{

    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    //状态控制（开始）指令帧
    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayCtrlCmd Cmd;
        int FrameEnd;
    }CmdFrame;

    CmdFrame.FrameHead = FRAME_HEAD_ICDE;
    CmdFrame.CmdId     = ID_CtrlCmd;
    CmdFrame.CmdLength = sizeof(ArrayCtrlCmd)/sizeof(int);
    CmdFrame.Cmd       = CmdStart;
    CmdFrame.FrameEnd  = FRAME_END_ICDE;

    memcpy(qworksBuffer, &CmdFrame, sizeof(CmdFrame));

    //系统参数指令帧
    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;         
        ArraySysPara sysPara;
        int FrameEnd;
    }SysParaFrame;
    SysParaFrame.FrameHead = FRAME_HEAD_ICDE;
    SysParaFrame.CmdId = ID_ArraySysPara;
    SysParaFrame.CmdLength = sizeof(ArraySysPara)/sizeof(int);
    SysParaFrame.FrameEnd = FRAME_END_ICDE;
    memcpy(&(SysParaFrame.sysPara), &sysPara, sizeof(sysPara));

    memcpy(qworksBuffer+sizeof(CmdFrame), &SysParaFrame, sizeof(SysParaFrame));

    //捷变频频率列表传输指令帧
    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayVariFrqListPara variFrqListPara;
        int FrameEnd;
    }VariFrqParaFrame;
    VariFrqParaFrame.FrameHead = FRAME_HEAD_ICDE;
    VariFrqParaFrame.CmdId = ID_FrqListSend;
    VariFrqParaFrame.CmdLength = sizeof(ArrayVariFrqListPara)/sizeof(int);
    VariFrqParaFrame.FrameEnd = FRAME_END_ICDE;
    memcpy(&(VariFrqParaFrame.variFrqListPara), &variFrqListPara, sizeof(variFrqListPara));

    memcpy(qworksBuffer+sizeof(CmdFrame)+sizeof(SysParaFrame), &VariFrqParaFrame, sizeof(VariFrqParaFrame));

    //通道一的精控单元控制指令帧
    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch1ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch1ExactPara, sizeof(ch1ExactPara));

    memcpy(qworksBuffer+sizeof(CmdFrame)+sizeof(SysParaFrame)+sizeof(VariFrqParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    //通道二的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch2ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch2ExactPara, sizeof(ch2ExactPara));

    memcpy(qworksBuffer+sizeof(CmdFrame)+sizeof(SysParaFrame)+sizeof(VariFrqParaFrame)+sizeof(ExactParaFrame),
           &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadRawParaCmd(QWorksHandle1007* handle,ArrayRawPara rawPara,ArrayWireEnPara wireEnPara,bool readReturnFlag)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    //粗控单元控制指令帧
    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayRawPara rawPara;
        int FrameEnd;
    }RawParaFrame;

    RawParaFrame.FrameHead = FRAME_HEAD_ICDE;
    RawParaFrame.CmdId     = ID_RawPara;
    RawParaFrame.CmdLength = sizeof(ArrayRawPara)/sizeof(int);
    RawParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(RawParaFrame.rawPara), &rawPara, sizeof(rawPara));

    memcpy(qworksBuffer, &RawParaFrame, sizeof(RawParaFrame));

    //天线使能控制指令帧
    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayWireEnPara wireEnPara;
        int FrameEnd;
    }WireEnParaFrame;

    WireEnParaFrame.FrameHead = FRAME_HEAD_ICDE;
    WireEnParaFrame.CmdId     = ID_WireEnCtrl;
    WireEnParaFrame.CmdLength = sizeof(ArrayWireEnPara)/sizeof(int);
    WireEnParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(WireEnParaFrame.wireEnPara), &wireEnPara, sizeof(wireEnPara));

    memcpy(qworksBuffer+sizeof(RawParaFrame), &WireEnParaFrame, sizeof(WireEnParaFrame));

    if(readReturnFlag)
    {
        //回读指令帧
        struct{
            int FrameHead;
            short CmdLength;
            short CmdId;
            int FillZero;
            int FrameEnd;
        }ReturnReadFrame;

        ReturnReadFrame.FrameHead = FRAME_HEAD_ICDE;
        ReturnReadFrame.CmdId     = ID_ReturnReadCmd;
        ReturnReadFrame.CmdLength = 1;
        ReturnReadFrame.FillZero  = 0;
        ReturnReadFrame.FrameEnd  = FRAME_END_ICDE;

        memcpy(qworksBuffer+sizeof(RawParaFrame)+sizeof(WireEnParaFrame), &ReturnReadFrame, sizeof(ReturnReadFrame));

        //状态控制（停止）指令帧
        struct{
            int FrameHead;
            short CmdLength;
            short CmdId;
            ArrayCtrlCmd Cmd;
            int FrameEnd;
        }CmdFrame;

        CmdFrame.FrameHead = FRAME_HEAD_ICDE;
        CmdFrame.CmdId     = ID_CtrlCmd;
        CmdFrame.CmdLength = sizeof(ArrayCtrlCmd)/sizeof(int);
        CmdFrame.Cmd       = CmdStop;
        CmdFrame.FrameEnd  = FRAME_END_ICDE;

        memcpy(qworksBuffer+sizeof(RawParaFrame)+sizeof(WireEnParaFrame)+sizeof(ReturnReadFrame), &CmdFrame, sizeof(CmdFrame));
    }
    else
    {
        //状态控制（停止）指令帧
        struct{
            int FrameHead;
            short CmdLength;
            short CmdId;
            ArrayCtrlCmd Cmd;
            int FrameEnd;
        }CmdFrame;

        CmdFrame.FrameHead = FRAME_HEAD_ICDE;
        CmdFrame.CmdId     = ID_CtrlCmd;
        CmdFrame.CmdLength = sizeof(ArrayCtrlCmd)/sizeof(int);
        CmdFrame.Cmd       = CmdStop;
        CmdFrame.FrameEnd  = FRAME_END_ICDE;

        memcpy(qworksBuffer+sizeof(RawParaFrame)+sizeof(WireEnParaFrame), &CmdFrame, sizeof(CmdFrame));
    }

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact2ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch3ExactPara, ArrayExactPara ch4ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道三的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch3ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch3ExactPara, sizeof(ch3ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    //通道四的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch4ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch4ExactPara, sizeof(ch4ExactPara));

    memcpy(qworksBuffer+sizeof(ExactParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact3ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch5ExactPara, ArrayExactPara ch6ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道五的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch5ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch5ExactPara, sizeof(ch5ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    //通道六的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch6ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch6ExactPara, sizeof(ch6ExactPara));

    memcpy(qworksBuffer+sizeof(ExactParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact4ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch7ExactPara, ArrayExactPara ch8ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道七的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch7ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch7ExactPara, sizeof(ch7ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    //通道八的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch8ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch8ExactPara, sizeof(ch8ExactPara));

    memcpy(qworksBuffer+sizeof(ExactParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact5ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch9ExactPara, ArrayExactPara ch10ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道九的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch9ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch9ExactPara, sizeof(ch9ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    //通道十的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch10ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch10ExactPara, sizeof(ch10ExactPara));

    memcpy(qworksBuffer+sizeof(ExactParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact6ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch11ExactPara, ArrayExactPara ch12ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道十一的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch11ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch11ExactPara, sizeof(ch11ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    //通道十二的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch12ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch12ExactPara, sizeof(ch12ExactPara));

    memcpy(qworksBuffer+sizeof(ExactParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact7ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch13ExactPara, ArrayExactPara ch14ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道十三的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch13ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch13ExactPara, sizeof(ch13ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    //通道十四的精控单元控制指令帧
    ExactParaFrame.CmdId     = ID_Ch14ExactPara;
    memcpy(&(ExactParaFrame.exactPara), &ch14ExactPara, sizeof(ch14ExactPara));

    memcpy(qworksBuffer+sizeof(ExactParaFrame), &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}

EnumError Test1729api::loadExact8ParaCmd(QWorksHandle1007* handle, ArrayExactPara ch15ExactPara)
{
    char qworksBuffer[RAM_BUF_SIZE];
    memset(qworksBuffer, 0, RAM_BUF_SIZE);

    struct{
        int FrameHead;
        short CmdLength;
        short CmdId;
        ArrayExactPara exactPara;
        int FrameEnd;
    }ExactParaFrame;

    //通道十五的精控单元控制指令帧
    ExactParaFrame.FrameHead = FRAME_HEAD_ICDE;
    ExactParaFrame.CmdId     = ID_Ch15ExactPara;
    ExactParaFrame.CmdLength = sizeof(ArrayExactPara)/sizeof(int);
    ExactParaFrame.FrameEnd  = FRAME_END_ICDE;
    memcpy(&(ExactParaFrame.exactPara), &ch15ExactPara, sizeof(ch15ExactPara));

    memcpy(qworksBuffer, &ExactParaFrame, sizeof(ExactParaFrame));

    double timeout=0;
    return (EnumError)Qworks_DMAWrite(handle,qworksBuffer,RAM_BUF_SIZE,timeout);
}