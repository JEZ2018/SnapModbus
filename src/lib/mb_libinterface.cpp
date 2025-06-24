/*=============================================================================|
|  PROJECT SnapModbus                                                    1.0.1 |
|==============================================================================|
|  Copyright (C) 2023, 2025 Davide Nardella                                    |
|  All rights reserved.                                                        |
|==============================================================================|
|  SnapModbus is free software: you can redistribute it and/or modify          |
|  it under the terms of the Lesser GNU General Public License as published by |
|  the Free Software Foundation, either version 3 of the License, or           |
|  (at your option) any later version.                                         |
|                                                                              |
|  It means that you can distribute your commercial software linked with       |
|  SnapModbus without the requirement to distribute the source code of your    |
|  application and without the requirement that your application be itself     |
|  distributed under LGPL.                                                     |
|                                                                              |
|  SnapModbus is distributed in the hope that it will be useful,               |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of              |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
|  Lesser GNU General Public License for more details.                         |
|                                                                              |
|  You should have received a copy of the GNU General Public License and a     |
|  copy of Lesser GNU General Public License along with Snap7.                 |
|  If not, see  http://www.gnu.org/licenses/                                   |
|=============================================================================*/
#include "mb_libinterface.h"
//------------------------------------------------------------------------------

inline int SetError(int Error)
{
    return errLibrary | errCategoryLibrary | Error;
}
//==============================================================================
// ETHERNET CONTROLLER                    
//==============================================================================
SNAP_Object fldctr_Create()
{
    return SNAP_Object(new TMBFieldController());
}
//------------------------------------------------------------------------------
inline void fldctr_Destroy(SNAP_Object& Controller)
{
    if (Controller)
    try
    {
        delete PMBFieldController(Controller);
        Controller = 0;
    }
    catch (...) {}
}
//------------------------------------------------------------------------------
inline int fldctr_SetLocalParam(SNAP_Object Controller, byte LocalID, int ParamIndex, int Value)
{
    return PMBFieldController(Controller)->SetLocalParam(LocalID, ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int fldctr_SetRemoteDeviceParam(SNAP_Object Controller, byte DeviceID, int ParamIndex, int Value)
{
    return PMBFieldController(Controller)->SetRemoteDeviceParam(DeviceID, ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int fldctr_Disconnect(SNAP_Object Controller)
{
    PMBFieldController(Controller)->Disconnect();
    return 0;
}
//------------------------------------------------------------------------------
inline int fldctr_Connect(SNAP_Object Controller)
{
    return PMBFieldController(Controller)->Connect();
}
//------------------------------------------------------------------------------
inline int fldctr_GetIOBufferPtr(SNAP_Object Controller, byte DeviceID, int BufferKind, pbyte& Data)
{
    return PMBFieldController(Controller)->GetIOBufferPtr(DeviceID, BufferKind, Data);
}
//------------------------------------------------------------------------------
inline int fldctr_GetIOBuffer(SNAP_Object Controller, byte DeviceID, int BufferKind, pbyte Data)
{
    return PMBFieldController(Controller)->GetIOBuffer(DeviceID, BufferKind, Data);
}
//------------------------------------------------------------------------------
inline int fldctr_GetDeviceStatus(SNAP_Object Controller, byte DeviceID, TDeviceStatus& DeviceStatus)
{
    return PMBFieldController(Controller)->GetDeviceStatus(DeviceID, DeviceStatus);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadHoldingRegisters(SNAP_Object Controller, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBFieldController(Controller)->ReadHoldingRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_WriteMultipleRegisters(SNAP_Object Controller, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBFieldController(Controller)->WriteMultipleRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadCoils(SNAP_Object Controller, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBFieldController(Controller)->ReadCoils(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadDiscreteInputs(SNAP_Object Controller, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBFieldController(Controller)->ReadDiscreteInputs(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadInputRegisters(SNAP_Object Controller, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBFieldController(Controller)->ReadInputRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_WriteSingleCoil(SNAP_Object Controller, byte DeviceID, word Address, word Value)
{
    return PMBFieldController(Controller)->WriteSingleCoil(DeviceID, Address, Value);
}
//------------------------------------------------------------------------------
inline int fldctr_WriteSingleRegister(SNAP_Object Controller, byte DeviceID, word Address, word Value)
{
    return PMBFieldController(Controller)->WriteSingleRegister(DeviceID, Address, Value);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadWriteMultipleRegisters(SNAP_Object Controller, byte DeviceID, word RDAddress, word RDAmount, word WRAddress, word WRAmount, void* pRDUsrData, void* pWRUsrData)
{
    return PMBFieldController(Controller)->ReadWriteMultipleRegisters(DeviceID, RDAddress, RDAmount, WRAddress, WRAmount, pRDUsrData, pWRUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_WriteMultipleCoils(SNAP_Object Controller, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBFieldController(Controller)->WriteMultipleCoils(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int fldctr_MaskWriteRegister(SNAP_Object Controller, byte DeviceID, word Address, word AND_Mask, word OR_Mask)
{
    return PMBFieldController(Controller)->MaskWriteRegister(DeviceID, Address, AND_Mask, OR_Mask);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadFileRecord(SNAP_Object Controller, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    return PMBFieldController(Controller)->ReadFileRecord(DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
}
//------------------------------------------------------------------------------
inline int fldctr_WriteFileRecord(SNAP_Object Controller, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    return PMBFieldController(Controller)->WriteFileRecord(DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadFIFOQueue(SNAP_Object Controller, byte DeviceID, word Address, word& FifoCount, void* FIFO)
{
    return PMBFieldController(Controller)->ReadFIFOQueue(DeviceID, Address, FifoCount, FIFO);
}
//------------------------------------------------------------------------------
inline int fldctr_ReadExceptionStatus(SNAP_Object Controller, byte DeviceID, byte& Data)
{
    return PMBFieldController(Controller)->ReadExceptionStatus(DeviceID, Data);
}
//------------------------------------------------------------------------------
inline int fldctr_Diagnostics(SNAP_Object Controller, byte DeviceID, word SubFunction, void* pSendData, void* pRecvData, word ItemsToSend, word& ItemsReceived)
{
    return PMBFieldController(Controller)->Diagnostics(DeviceID, SubFunction, pSendData, pRecvData, ItemsToSend, ItemsReceived);
}
//------------------------------------------------------------------------------
inline int fldctr_GetCommEventCounter(SNAP_Object Controller, byte DeviceID, word& Status, word& EventCount)
{
    return PMBFieldController(Controller)->GetCommEventCounter(DeviceID, Status, EventCount);
}
//------------------------------------------------------------------------------
inline int fldctr_GetCommEventLog(SNAP_Object Controller, byte DeviceID, word& Status, word& EventCount, word& MessageCount, word& NumItems, void* Events)
{
    return PMBFieldController(Controller)->GetCommEventLog(DeviceID, Status, EventCount, MessageCount, NumItems, Events);
}
//------------------------------------------------------------------------------
inline int fldctr_ReportServerID(SNAP_Object Controller, byte DeviceID, void* pUsrData, int& DataSize)
{
    return PMBFieldController(Controller)->ReportServerID(DeviceID, pUsrData, DataSize);
}
//------------------------------------------------------------------------------
inline int fldctr_ExecuteMEIFunction(SNAP_Object Controller, byte DeviceID, byte MEI_Type, void* pWRUsrData, word WRSize, void* pRDUsrData, word& RDSize)
{
    return PMBFieldController(Controller)->ExecuteMEIFunction(DeviceID, MEI_Type, pWRUsrData, WRSize, pRDUsrData, RDSize);
}
//------------------------------------------------------------------------------
inline int fldctr_CustomFunctionRequest(SNAP_Object Controller, byte DeviceID, byte UsrFunction, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    return PMBFieldController(Controller)->CustomFunctionRequest(DeviceID, UsrFunction, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
}
//------------------------------------------------------------------------------
inline int fldctr_RawRequest(SNAP_Object Controller, byte DeviceID, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    return PMBFieldController(Controller)->RawRequest(DeviceID, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
}
//==============================================================================
// ETHERNET CLIENT                    
//==============================================================================
SNAP_Object ethcli_Create(int Proto, const char* IP, int Port)
{
    return SNAP_Object(new TMBEthernetClient(Proto, IP, Port));
}
//------------------------------------------------------------------------------
inline void ethcli_Destroy(SNAP_Object& Client)
{
    if (Client)
    try
    {
        delete PMBEthernetClient(Client);
        Client = 0;
    }
    catch (...) {}
}
//------------------------------------------------------------------------------
inline int ethcli_SetLocalParam(SNAP_Object Client, byte LocalID, int ParamIndex, int Value)
{
    return PMBEthernetClient(Client)->SetLocalParam(ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int ethcli_SetRemoteDeviceParam(SNAP_Object Client, byte DeviceID, int ParamIndex, int Value)
{
    return PMBEthernetClient(Client)->SetRemoteDeviceParam(DeviceID, ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int ethcli_Connect(SNAP_Object Client)
{
    return PMBEthernetClient(Client)->Connect();
}
//------------------------------------------------------------------------------
inline int ethcli_AddClient(SNAP_Object Client, byte DeviceID, const char* IP, int Port, int Proto)
{
    return SetError(errObjectInvalidMethod);
}
//------------------------------------------------------------------------------
inline int ethcli_Disconnect(SNAP_Object Client)
{
    PMBEthernetClient(Client)->Disconnect();
    return 0;
}
//------------------------------------------------------------------------------
inline int ethcli_GetIOBufferPtr(SNAP_Object Client, byte DeviceID, int BufferKind, pbyte &Data)
{
    return PMBEthernetClient(Client)->GetIOBufferPtr(BufferKind, Data);
}
//------------------------------------------------------------------------------
inline int ethcli_GetIOBuffer(SNAP_Object Client, byte DeviceID, int BufferKind, pbyte Data)
{
    return PMBEthernetClient(Client)->GetIOBuffer(BufferKind, Data);
}
//------------------------------------------------------------------------------
inline int ethcli_GetDeviceStatus(SNAP_Object Client, byte DeviceID, TDeviceStatus& DeviceStatus)
{
    return PMBEthernetClient(Client)->GetDeviceStatus(DeviceID, DeviceStatus);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadHoldingRegisters(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBEthernetClient(Client)->ReadHoldingRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_WriteMultipleRegisters(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBEthernetClient(Client)->WriteMultipleRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadCoils(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBEthernetClient(Client)->ReadCoils(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadDiscreteInputs(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBEthernetClient(Client)->ReadDiscreteInputs(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadInputRegisters(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBEthernetClient(Client)->ReadInputRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_WriteSingleCoil(SNAP_Object Client, byte DeviceID, word Address, word Value)
{
    return PMBEthernetClient(Client)->WriteSingleCoil(DeviceID, Address, Value);
}
//------------------------------------------------------------------------------
inline int ethcli_WriteSingleRegister(SNAP_Object Client, byte DeviceID, word Address, word Value)
{
    return PMBEthernetClient(Client)->WriteSingleRegister(DeviceID, Address, Value);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadWriteMultipleRegisters(SNAP_Object Client, byte DeviceID, word RDAddress, word RDAmount, word WRAddress, word WRAmount, void* pRDUsrData, void* pWRUsrData)
{
    return PMBEthernetClient(Client)->ReadWriteMultipleRegisters(DeviceID, RDAddress, RDAmount, WRAddress, WRAmount, pRDUsrData, pWRUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_WriteMultipleCoils(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBEthernetClient(Client)->WriteMultipleCoils(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int ethcli_MaskWriteRegister(SNAP_Object Client, byte DeviceID, word Address, word AND_Mask, word OR_Mask)
{
    return PMBEthernetClient(Client)->MaskWriteRegister(DeviceID, Address, AND_Mask, OR_Mask);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadFileRecord(SNAP_Object Client, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    return PMBEthernetClient(Client)->ReadFileRecord(DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
}
//------------------------------------------------------------------------------
inline int ethcli_WriteFileRecord(SNAP_Object Client, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    return PMBEthernetClient(Client)->WriteFileRecord(DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadFIFOQueue(SNAP_Object Client, byte DeviceID, word Address, word& FifoCount, void* FIFO)
{
    return PMBEthernetClient(Client)->ReadFIFOQueue(DeviceID, Address, FifoCount, FIFO);
}
//------------------------------------------------------------------------------
inline int ethcli_ReadExceptionStatus(SNAP_Object Client, byte DeviceID, byte& Data)
{
    return PMBEthernetClient(Client)->ReadExceptionStatus(DeviceID, Data);
}
//------------------------------------------------------------------------------
inline int ethcli_Diagnostics(SNAP_Object Client, byte DeviceID, word SubFunction, void* pSendData, void* pRecvData, word ItemsToSend, word& ItemsReceived)
{
    return PMBEthernetClient(Client)->Diagnostics(DeviceID, SubFunction, pSendData, pRecvData, ItemsToSend, ItemsReceived);
}
//------------------------------------------------------------------------------
inline int ethcli_GetCommEventCounter(SNAP_Object Client, byte DeviceID, word& Status, word& EventCount)
{
    return PMBEthernetClient(Client)->GetCommEventCounter(DeviceID, Status, EventCount);
}
//------------------------------------------------------------------------------
inline int ethcli_GetCommEventLog(SNAP_Object Client, byte DeviceID, word& Status, word& EventCount, word& MessageCount, word& NumItems, void* Events)
{
    return PMBEthernetClient(Client)->GetCommEventLog(DeviceID, Status, EventCount, MessageCount, NumItems, Events);
}
//------------------------------------------------------------------------------
inline int ethcli_ReportServerID(SNAP_Object Client, byte DeviceID, void* pUsrData, int& DataSize)
{
    return PMBEthernetClient(Client)->ReportServerID(DeviceID, pUsrData, DataSize);
}
//------------------------------------------------------------------------------
inline int ethcli_ExecuteMEIFunction(SNAP_Object Client, byte DeviceID, byte MEI_Type, void* pWRUsrData, word WRSize, void* pRDUsrData, word& RDSize)
{
    return PMBEthernetClient(Client)->ExecuteMEIFunction(DeviceID, MEI_Type, pWRUsrData, WRSize, pRDUsrData, RDSize);
}
//------------------------------------------------------------------------------
inline int ethcli_CustomFunctionRequest(SNAP_Object Client, byte DeviceID, byte UsrFunction, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    return PMBEthernetClient(Client)->CustomFunctionRequest(DeviceID, UsrFunction, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
}
//------------------------------------------------------------------------------
inline int ethcli_RawRequest(SNAP_Object Client, byte DeviceID, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    return PMBEthernetClient(Client)->RawRequest(DeviceID, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
}
//==============================================================================
// SERIAL CLIENT                    
//==============================================================================
SNAP_Object sercli_Create(int Format, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow)
{
    return SNAP_Object(new TMBSerClient(Format, PortName, BaudRate, Parity, DataBits, Stops, Flow));
}
//------------------------------------------------------------------------------
inline void sercli_Destroy(SNAP_Object& Client)
{
    if (Client)
    try
    {
        delete PMBSerClient(Client);
        Client = 0;
    }
    catch(...){}
}
//------------------------------------------------------------------------------
inline int sercli_SetLocalParam(SNAP_Object Client, byte LocalID, int ParamIndex, int Value)
{
    return PMBSerClient(Client)->SetLocalParam(LocalID, ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int sercli_SetRemoteDeviceParam(SNAP_Object Client, byte DeviceID, int ParamIndex, int Value)
{
    return PMBSerClient(Client)->SetRemoteDeviceParam(DeviceID, ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int sercli_Connect(SNAP_Object Client)
{
    return PMBSerClient(Client)->Connect();
}
//------------------------------------------------------------------------------
inline int sercli_Disconnect(SNAP_Object Client)
{
    PMBSerClient(Client)->Disconnect();
    return 0;
}
//------------------------------------------------------------------------------
inline int sercli_AddClient(SNAP_Object Client, byte DeviceID, const char* IP, int Port, int Proto)
{
    return SetError(errObjectInvalidMethod);
}
//------------------------------------------------------------------------------
inline int sercli_GetIOBufferPtr(SNAP_Object Client, byte DeviceID, int BufferKind, pbyte &Data)
{
    return PMBSerClient(Client)->GetIOBufferPtr(BufferKind, Data);
}
//------------------------------------------------------------------------------
inline int sercli_GetIOBuffer(SNAP_Object Client, byte DeviceID, int BufferKind, pbyte Data)
{
    return PMBSerClient(Client)->GetIOBuffer(BufferKind, Data);
}
//------------------------------------------------------------------------------
inline int sercli_GetDeviceStatus(SNAP_Object Client, byte DeviceID, TDeviceStatus& DeviceStatus)
{
    return PMBSerClient(Client)->GetDeviceStatus(DeviceID, DeviceStatus);
}
//------------------------------------------------------------------------------
inline int sercli_ReadHoldingRegisters(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBSerClient(Client)->ReadHoldingRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_WriteMultipleRegisters(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBSerClient(Client)->WriteMultipleRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_ReadCoils(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBSerClient(Client)->ReadCoils(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_ReadDiscreteInputs(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBSerClient(Client)->ReadDiscreteInputs(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_ReadInputRegisters(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBSerClient(Client)->ReadInputRegisters(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_WriteSingleCoil(SNAP_Object Client, byte DeviceID, word Address, word Value)
{
    return PMBSerClient(Client)->WriteSingleCoil(DeviceID, Address, Value);
}
//------------------------------------------------------------------------------
inline int sercli_WriteSingleRegister(SNAP_Object Client, byte DeviceID, word Address, word Value)
{
    return PMBSerClient(Client)->WriteSingleRegister(DeviceID, Address, Value);
}
//------------------------------------------------------------------------------
inline int sercli_ReadWriteMultipleRegisters(SNAP_Object Client, byte DeviceID, word RDAddress, word RDAmount, word WRAddress, word WRAmount, void* pRDUsrData, void* pWRUsrData)
{
    return PMBSerClient(Client)->ReadWriteMultipleRegisters(DeviceID, RDAddress, RDAmount, WRAddress, WRAmount, pRDUsrData, pWRUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_WriteMultipleCoils(SNAP_Object Client, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    return PMBSerClient(Client)->WriteMultipleCoils(DeviceID, Address, Amount, pUsrData);
}
//------------------------------------------------------------------------------
inline int sercli_MaskWriteRegister(SNAP_Object Client, byte DeviceID, word Address, word AND_Mask, word OR_Mask)
{
    return PMBSerClient(Client)->MaskWriteRegister(DeviceID, Address, AND_Mask, OR_Mask);
}
//------------------------------------------------------------------------------
inline int sercli_ReadFileRecord(SNAP_Object Client, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    return PMBSerClient(Client)->ReadFileRecord(DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
}
//------------------------------------------------------------------------------
inline int sercli_WriteFileRecord(SNAP_Object Client, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    return PMBSerClient(Client)->WriteFileRecord(DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
}
//------------------------------------------------------------------------------
inline int sercli_ReadFIFOQueue(SNAP_Object Client, byte DeviceID, word Address, word& FifoCount, void* FIFO)
{
    return PMBSerClient(Client)->ReadFIFOQueue(DeviceID, Address, FifoCount, FIFO);
}
//------------------------------------------------------------------------------
inline int sercli_ReadExceptionStatus(SNAP_Object Client, byte DeviceID, byte& Data)
{
    return PMBSerClient(Client)->ReadExceptionStatus(DeviceID, Data);
}
//------------------------------------------------------------------------------
inline int sercli_Diagnostics(SNAP_Object Client, byte DeviceID, word SubFunction, void* pSendData, void* pRecvData, word ItemsToSend, word& ItemsReceived)
{
    return PMBSerClient(Client)->Diagnostics(DeviceID, SubFunction, pSendData, pRecvData, ItemsToSend, ItemsReceived);
}
//------------------------------------------------------------------------------
inline int sercli_GetCommEventCounter(SNAP_Object Client, byte DeviceID, word& Status, word& EventCount)
{
    return PMBSerClient(Client)->GetCommEventCounter(DeviceID, Status, EventCount);
}
//------------------------------------------------------------------------------
inline int sercli_GetCommEventLog(SNAP_Object Client, byte DeviceID, word& Status, word& EventCount, word& MessageCount, word& NumItems, void* Events)
{
    return PMBSerClient(Client)->GetCommEventLog(DeviceID, Status, EventCount, MessageCount, NumItems, Events);
}
//------------------------------------------------------------------------------
inline int sercli_ReportServerID(SNAP_Object Client, byte DeviceID, void* pUsrData, int& DataSize)
{
    return PMBSerClient(Client)->ReportServerID(DeviceID, pUsrData, DataSize);
}
//------------------------------------------------------------------------------
inline int sercli_ExecuteMEIFunction(SNAP_Object Client, byte DeviceID, byte MEI_Type, void* pWRUsrData, word WRSize, void* pRDUsrData, word& RDSize)
{
    return PMBSerClient(Client)->ExecuteMEIFunction(DeviceID, MEI_Type, pWRUsrData, WRSize, pRDUsrData, RDSize);
}
//------------------------------------------------------------------------------
inline int sercli_CustomFunctionRequest(SNAP_Object Client, byte DeviceID, byte UsrFunction, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    return PMBSerClient(Client)->CustomFunctionRequest(DeviceID, UsrFunction, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
}
//------------------------------------------------------------------------------
inline int sercli_RawRequest(SNAP_Object Client, byte DeviceID, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    return PMBSerClient(Client)->RawRequest(DeviceID, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
}
//==============================================================================
// TCP DEVICE                           
//==============================================================================
inline void tcpdev_Destroy(SNAP_Object& Device)
{
    if (Device)
    try
    {
        delete PMBTcpDevice(Device);
        Device = 0;
    }
    catch (...) {}
}
//------------------------------------------------------------------------------
inline int tcpdev_SetParam(SNAP_Object Device, int ParamIndex, int Value)
{
    return PMBTcpDevice(Device)->SetParam(ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int tcpdev_SetUserFunction(SNAP_Object Device, byte FunctionID, int Value)
{
    return PMBTcpDevice(Device)->SetUserFunction(FunctionID, Value != 0);
}
//------------------------------------------------------------------------------
inline int tcpdev_Start(SNAP_Object Device)
{
    return PMBTcpDevice(Device)->Start();
}
//------------------------------------------------------------------------------
inline int tcpdev_Stop(SNAP_Object Device)
{
    PMBTcpDevice(Device)->Stop();
    return 0;
}
//------------------------------------------------------------------------------
inline int tcpdev_AddPeer(SNAP_Object Device, const char* Address)
{
    return PMBTcpDevice(Device)->AddPeer(Address);
}
//------------------------------------------------------------------------------
inline int tcpdev_RegisterArea(SNAP_Object Device, int AreaID, void* Data, int Amount)
{
    return PMBTcpDevice(Device)->RegisterArea(AreaID, Data, Amount);
}
//------------------------------------------------------------------------------
inline int tcpdev_LockArea(SNAP_Object Device, int AreaID)
{
    return PMBTcpDevice(Device)->LockArea(AreaID);
}
//------------------------------------------------------------------------------
inline int tcpdev_UnlockArea(SNAP_Object Device, int AreaID)
{
    return PMBTcpDevice(Device)->UnlockArea(AreaID);
}
//------------------------------------------------------------------------------
inline int tcpdev_CopyArea(SNAP_Object Device, int AreaID, word Address, word Amount, void* Data, int CopyMode)
{
    return PMBTcpDevice(Device)->CopyArea(AreaID, Address, Amount, Data, CopyMode);
}
//------------------------------------------------------------------------------
inline int tcpdev_RegisterCallback(SNAP_Object Device, int CallbackID, void* cbRequest, void* UsrPtr)
{
    return PMBTcpDevice(Device)->RegisterCallback(CallbackID, cbRequest, UsrPtr);
}
//------------------------------------------------------------------------------
inline int tcpdev_PickEvent(SNAP_Object Device, void* pEvent)
{
    return PMBTcpDevice(Device)->PickEvent(pEvent);
}
//------------------------------------------------------------------------------
inline int tcpdev_PickEventAsText(SNAP_Object Device, char* Text, int TextSize)
{
    return PMBTcpDevice(Device)->PickEventAsText(Text, TextSize);
}
//------------------------------------------------------------------------------
inline int tcpdev_GetInfo(SNAP_Object Device, TDeviceInfo& DeviceStatus)
{
    return PMBTcpDevice(Device)->GetDeviceInfo(DeviceStatus);
}
//==============================================================================
// UDP DEVICE                           
//==============================================================================
inline void udpdev_Destroy(SNAP_Object& Device)
{
    if (Device)
    try
    {
        delete PMBUdpDevice(Device);
        Device = 0;
    }
    catch (...) {}
}
//------------------------------------------------------------------------------
inline int udpdev_SetParam(SNAP_Object Device, int ParamIndex, int Value)
{
    return PMBUdpDevice(Device)->SetParam(ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int udpdev_SetUserFunction(SNAP_Object Device, byte FunctionID, int Value)
{
    return PMBUdpDevice(Device)->SetUserFunction(FunctionID, Value != 0);
}
//------------------------------------------------------------------------------
inline int udpdev_Start(SNAP_Object Device)
{
    return PMBUdpDevice(Device)->Start();
}
//------------------------------------------------------------------------------
inline int udpdev_Stop(SNAP_Object Device)
{
    PMBUdpDevice(Device)->Stop();
    return 0;
}
//------------------------------------------------------------------------------
inline int udpdev_AddPeer(SNAP_Object Device, const char* Address)
{
    return PMBUdpDevice(Device)->AddPeer(Address);
}
//------------------------------------------------------------------------------
inline int udpdev_RegisterArea(SNAP_Object Device, int AreaID, void* Data, int Amount)
{
    return PMBUdpDevice(Device)->RegisterArea(AreaID, Data, Amount);
}
//------------------------------------------------------------------------------
inline int udpdev_LockArea(SNAP_Object Device, int AreaID)
{
    return PMBUdpDevice(Device)->LockArea(AreaID);
}
//------------------------------------------------------------------------------
inline int udpdev_UnlockArea(SNAP_Object Device, int AreaID)
{
    return PMBUdpDevice(Device)->UnlockArea(AreaID);
}
//------------------------------------------------------------------------------
inline int udpdev_CopyArea(SNAP_Object Device, int AreaID, word Address, word Amount, void* Data, int CopyMode)
{
    return PMBUdpDevice(Device)->CopyArea(AreaID, Address, Amount, Data, CopyMode);
}
//------------------------------------------------------------------------------
inline int udpdev_RegisterCallback(SNAP_Object Device, int CallbackID, void* cbRequest, void* UsrPtr)
{
    return PMBUdpDevice(Device)->RegisterCallback(CallbackID, cbRequest, UsrPtr);
}
//------------------------------------------------------------------------------
inline int udpdev_PickEvent(SNAP_Object Device, void* pEvent)
{
    return PMBUdpDevice(Device)->PickEvent(pEvent);
}
//------------------------------------------------------------------------------
inline int udpdev_PickEventAsText(SNAP_Object Device, char* Text, int TextSize)
{
    return PMBUdpDevice(Device)->PickEventAsText(Text, TextSize);
}
//------------------------------------------------------------------------------
inline int udpdev_GetInfo(SNAP_Object Device, TDeviceInfo& DeviceStatus)
{
    return PMBUdpDevice(Device)->GetDeviceInfo(DeviceStatus);
}
//==============================================================================
// SERIAL DEVICE                           
//==============================================================================
SNAP_Object serdev_Create(int Format, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow)
{
    return SNAP_Object(new TMBSerDevice(Format, DeviceID, PortName, BaudRate, Parity, DataBits, Stops, Flow));
}
//------------------------------------------------------------------------------
inline void serdev_Destroy(SNAP_Object& Device)
{
    if (Device)
    try
    {
        delete PMBSerDevice(Device);
        Device = 0;
    }
    catch (...) {}
}
//------------------------------------------------------------------------------
inline int serdev_AddPeer(SNAP_Object Device, const char* Address)
{
    return SetError(errObjectInvalidMethod);
}
//------------------------------------------------------------------------------
inline int serdev_SetParam(SNAP_Object Device, int ParamIndex, int Value)
{
    return PMBSerDevice(Device)->SetParam(ParamIndex, Value);
}
//------------------------------------------------------------------------------
inline int serdev_SetUserFunction(SNAP_Object Device, byte FunctionID, int Value)
{
    return PMBSerDevice(Device)->SetUserFunction(FunctionID, Value != 0);
}
//------------------------------------------------------------------------------
inline int serdev_Start(SNAP_Object Device)
{
    return PMBSerDevice(Device)->Start();
}
//------------------------------------------------------------------------------
inline int serdev_Stop(SNAP_Object Device)
{
    PMBSerDevice(Device)->Stop();
    return 0;
}
//------------------------------------------------------------------------------
inline int serdev_RegisterArea(SNAP_Object Device, int AreaID, void* Data, int Amount)
{
    return PMBSerDevice(Device)->RegisterArea(AreaID, Data, Amount);
}
//------------------------------------------------------------------------------
inline int serdev_LockArea(SNAP_Object Device, int AreaID)
{
    return PMBSerDevice(Device)->LockArea(AreaID);
}
//------------------------------------------------------------------------------
inline int serdev_UnlockArea(SNAP_Object Device, int AreaID)
{
    return PMBSerDevice(Device)->UnlockArea(AreaID);
}
//------------------------------------------------------------------------------
inline int serdev_CopyArea(SNAP_Object Device, int AreaID, word Address, word Amount, void* Data, int CopyMode)
{
    return PMBSerDevice(Device)->CopyArea(AreaID, Address, Amount, Data, CopyMode);
}
//------------------------------------------------------------------------------
inline int serdev_RegisterCallback(SNAP_Object Device, int CallbackID, void* cbRequest, void* UsrPtr)
{
    return PMBSerDevice(Device)->RegisterCallback(CallbackID, cbRequest, UsrPtr);
}
//------------------------------------------------------------------------------
inline int serdev_PickEvent(SNAP_Object Device, void* pEvent)
{
    return PMBSerDevice(Device)->PickEvent(pEvent);
}
//------------------------------------------------------------------------------
inline int serdev_PickEventAsText(SNAP_Object Device, char* Text, int TextSize)
{
    return PMBSerDevice(Device)->PickEventAsText(Text, TextSize);
}
//------------------------------------------------------------------------------
inline int serdev_GetInfo(SNAP_Object Device, TDeviceInfo& DeviceStatus)
{
    return PMBSerDevice(Device)->GetDeviceInfo(DeviceStatus);
}
//******************************************************************************
// BROKER Lookup Tables for fast calling
//******************************************************************************
pfn_Destroy                     BrkDestroy[3] = { fldctr_Destroy, ethcli_Destroy, sercli_Destroy };
pfn_SetRemoteDeviceParam        BrkSetRemoteDeviceParam[3] = { fldctr_SetRemoteDeviceParam, ethcli_SetRemoteDeviceParam, sercli_SetRemoteDeviceParam};
pfn_SetLocalParam               BrkSetLocalParam[3] = { fldctr_SetLocalParam, ethcli_SetLocalParam, sercli_SetLocalParam };
pfn_Connect                     BrkConnect[3] = { fldctr_Connect, ethcli_Connect, sercli_Connect };
pfn_Disconnect                  BrkDisconnect[3] = { fldctr_Disconnect, ethcli_Disconnect, sercli_Disconnect };
pfn_GetIOBufferPtr              BrkGetIOBufferPtr[3] = { fldctr_GetIOBufferPtr, ethcli_GetIOBufferPtr, sercli_GetIOBufferPtr };
pfn_GetIOBuffer                 BrkGetIOBuffer[3] = { fldctr_GetIOBuffer, ethcli_GetIOBuffer, sercli_GetIOBuffer };
pfn_GetDeviceStatus             BrkGetDeviceStatus[3] = { fldctr_GetDeviceStatus, ethcli_GetDeviceStatus, sercli_GetDeviceStatus };
pfn_ReadHoldingRegisters        BrkReadHoldingRegisters[3] = { fldctr_ReadHoldingRegisters , ethcli_ReadHoldingRegisters, sercli_ReadHoldingRegisters };
pfn_WriteMultipleRegisters      BrkWriteMultipleRegisters[3] = { fldctr_WriteMultipleRegisters, ethcli_WriteMultipleRegisters, sercli_WriteMultipleRegisters };
pfn_ReadCoils                   BrkReadCoils[3] = { fldctr_ReadCoils, ethcli_ReadCoils, sercli_ReadCoils };
pfn_ReadDiscreteInputs          BrkReadDiscreteInputs[3] = { fldctr_ReadDiscreteInputs, ethcli_ReadDiscreteInputs, sercli_ReadDiscreteInputs };
pfn_ReadInputRegisters          BrkReadInputRegisters[3] = { fldctr_ReadInputRegisters, ethcli_ReadInputRegisters, sercli_ReadInputRegisters };
pfn_WriteSingleCoil             BrkWriteSingleCoil[3] = { fldctr_WriteSingleCoil, ethcli_WriteSingleCoil, sercli_WriteSingleCoil };
pfn_WriteSingleRegister         BrkWriteSingleRegister[3] = { fldctr_WriteSingleRegister, ethcli_WriteSingleRegister, sercli_WriteSingleRegister };
pfn_ReadWriteMultipleRegisters  BrkReadWriteMultipleRegisters[3] = { fldctr_ReadWriteMultipleRegisters, ethcli_ReadWriteMultipleRegisters, sercli_ReadWriteMultipleRegisters };
pfn_WriteMultipleCoils          BrkWriteMultipleCoils[3] = { fldctr_WriteMultipleCoils, ethcli_WriteMultipleCoils, sercli_WriteMultipleCoils };
pfn_MaskWriteRegister           BrkMaskWriteRegister[3] = { fldctr_MaskWriteRegister, ethcli_MaskWriteRegister, sercli_MaskWriteRegister };
pfn_ReadFileRecord              BrkReadFileRecord[3] = { fldctr_ReadFileRecord, ethcli_ReadFileRecord, sercli_ReadFileRecord };
pfn_WriteFileRecord             BrkWriteFileRecord[3] = { fldctr_WriteFileRecord, ethcli_WriteFileRecord, sercli_WriteFileRecord };
pfn_ReadFIFOQueue               BrkReadFIFOQueue[3] = { fldctr_ReadFIFOQueue, ethcli_ReadFIFOQueue, sercli_ReadFIFOQueue };
pfn_ReadExceptionStatus         BrkReadExceptionStatus[3] = { fldctr_ReadExceptionStatus, ethcli_ReadExceptionStatus, sercli_ReadExceptionStatus };
pfn_Diagnostics                 BrkDiagnostics[3] = { fldctr_Diagnostics, ethcli_Diagnostics, sercli_Diagnostics };
pfn_GetCommEventCounter         BrkGetCommEventCounter[3] = { fldctr_GetCommEventCounter, ethcli_GetCommEventCounter, sercli_GetCommEventCounter };
pfn_GetCommEventLog             BrkGetCommEventLog[3] = { fldctr_GetCommEventLog, ethcli_GetCommEventLog, sercli_GetCommEventLog };
pfn_ReportServerID              BrkReportServerID[3] = { fldctr_ReportServerID, ethcli_ReportServerID, sercli_ReportServerID };
pfn_ExecuteMEIFunction          BrkExecuteMEIFunction[3] = { fldctr_ExecuteMEIFunction, ethcli_ExecuteMEIFunction, sercli_ExecuteMEIFunction };
pfn_CustomFunctionRequest       BrkCustomFunctionRequest[3] = { fldctr_CustomFunctionRequest, ethcli_CustomFunctionRequest, sercli_CustomFunctionRequest };
pfn_RawRequest                  BrkRawRequest[3] = { fldctr_RawRequest, ethcli_RawRequest, sercli_RawRequest };

//******************************************************************************
// BROKER Entry Points
//******************************************************************************

EXPORTSPEC void SNAP_API broker_CreateFieldController(XOBJECT& Broker)
{
    Broker.Object = fldctr_Create();
    Broker.Selector = _FieldController;
}
//------------------------------------------------------------------------------
EXPORTSPEC void SNAP_API broker_CreateEthernetClient(XOBJECT & Broker, int Proto, const char* Address, int Port)
{
    Broker.Object = ethcli_Create(Proto, Address, Port);
    Broker.Selector = _EthernetClient;
}
//------------------------------------------------------------------------------
EXPORTSPEC void SNAP_API broker_CreateSerialClient(XOBJECT& Broker, int Format, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow)
{
    Broker.Object = sercli_Create(Format, PortName, BaudRate, Parity, DataBits, Stops, Flow);
    Broker.Selector = _SerialClient;
}
//------------------------------------------------------------------------------
EXPORTSPEC void SNAP_API broker_Destroy(XOBJECT& Broker)
{
    if (Broker.Object)
    try
    {
        BrkDestroy[Broker.Selector](Broker.Object);
    }catch(...){}
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_Connect(XOBJECT& Broker)
{
    if (Broker.Object)
        return BrkConnect[Broker.Selector](Broker.Object);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_Disconnect(XOBJECT& Broker)
{
    if (Broker.Object)
        return BrkDisconnect[Broker.Selector](Broker.Object);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_AddControllerNetDevice(XOBJECT& Broker, int Proto, byte DeviceID, const char* Address, int Port)
{
    if (Broker.Object)
    {
        if (Broker.Selector == _FieldController)
            return PMBFieldController(Broker.Object)->AddEthernetDevice(Proto, DeviceID, Address, Port);
        else
            return SetError(errObjectInvalidMethod);
    }
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_AddControllerSerDevice(XOBJECT& Broker, int Format, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow)
{
    if (Broker.Object)
    {
        if (Broker.Selector == _FieldController)
            return PMBFieldController(Broker.Object)->AddSerialDevice(Format, DeviceID, PortName, BaudRate, Parity, DataBits, Stops, Flow);
        else
            return SetError(errObjectInvalidMethod);
    }
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_SetLocalParam(XOBJECT& Broker, byte LocalID, int ParamIndex, int Value)
{
    if (Broker.Object)
        return BrkSetLocalParam[Broker.Selector](Broker.Object, LocalID, ParamIndex, Value);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_SetRemoteDeviceParam(XOBJECT& Broker, byte DeviceID, int ParamIndex, int Value)
{
    if (Broker.Object)
        return BrkSetRemoteDeviceParam[Broker.Selector](Broker.Object, DeviceID, ParamIndex, Value);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_GetIOBufferPtr(XOBJECT& Broker, byte DeviceID, int BufferKind, pbyte &Data)
{
    if (Broker.Object)
        return BrkGetIOBufferPtr[Broker.Selector](Broker.Object, DeviceID, BufferKind, Data);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_GetIOBuffer(XOBJECT& Broker, byte DeviceID, int BufferKind, pbyte Data)
{
    if (Broker.Object)
        return BrkGetIOBuffer[Broker.Selector](Broker.Object, DeviceID, BufferKind, Data);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_GetDeviceStatus(XOBJECT& Broker, byte DeviceID, TDeviceStatus& DeviceStatus)
{
    if (Broker.Object)
        return BrkGetDeviceStatus[Broker.Selector](Broker.Object, DeviceID, DeviceStatus);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadHoldingRegisters(XOBJECT &Broker, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    if (Broker.Object)
        return BrkReadHoldingRegisters[Broker.Selector](Broker.Object, DeviceID, Address, Amount, pUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_WriteMultipleRegisters(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    if (Broker.Object)
        return BrkWriteMultipleRegisters[Broker.Selector](Broker.Object, DeviceID, Address, Amount, pUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadCoils(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    if (Broker.Object)
        return BrkReadCoils[Broker.Selector](Broker.Object, DeviceID, Address, Amount, pUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadDiscreteInputs(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    if (Broker.Object)
        return BrkReadDiscreteInputs[Broker.Selector](Broker.Object, DeviceID, Address, Amount, pUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadInputRegisters(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    if (Broker.Object)
        return BrkReadInputRegisters[Broker.Selector](Broker.Object, DeviceID, Address, Amount, pUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_WriteSingleCoil(XOBJECT& Broker, byte DeviceID, word Address, word Value)
{
    if (Broker.Object)
        return BrkWriteSingleCoil[Broker.Selector](Broker.Object, DeviceID, Address, Value);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_WriteSingleRegister(XOBJECT& Broker, byte DeviceID, word Address, word Value)
{
    if (Broker.Object)
        return BrkWriteSingleRegister[Broker.Selector](Broker.Object, DeviceID, Address, Value);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadWriteMultipleRegisters(XOBJECT& Broker, byte DeviceID, word RDAddress, word RDAmount, word WRAddress, word WRAmount, void* pRDUsrData, void* pWRUsrData)
{
    if (Broker.Object)
        return BrkReadWriteMultipleRegisters[Broker.Selector](Broker.Object, DeviceID, RDAddress, RDAmount, WRAddress, WRAmount, pRDUsrData, pWRUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_WriteMultipleCoils(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData)
{
    if (Broker.Object)
        return BrkWriteMultipleCoils[Broker.Selector](Broker.Object, DeviceID, Address, Amount, pUsrData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_MaskWriteRegister(XOBJECT& Broker, byte DeviceID, word Address, word AND_Mask, word OR_Mask)
{
    if (Broker.Object)
        return BrkMaskWriteRegister[Broker.Selector](Broker.Object, DeviceID, Address, AND_Mask, OR_Mask);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadFileRecord(XOBJECT& Broker, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    if (Broker.Object)
        return BrkReadFileRecord[Broker.Selector](Broker.Object, DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_WriteFileRecord(XOBJECT& Broker, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData)
{
    if (Broker.Object)
        return BrkWriteFileRecord[Broker.Selector](Broker.Object, DeviceID, RefType, FileNumber, RecNumber, RegsAmount, RecData);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadFIFOQueue(XOBJECT& Broker, byte DeviceID, word Address, word& FifoCount, void* FIFO)
{
    if (Broker.Object)
        return BrkReadFIFOQueue[Broker.Selector](Broker.Object, DeviceID, Address, FifoCount, FIFO);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReadExceptionStatus(XOBJECT& Broker, byte DeviceID, byte& Data)
{
    if (Broker.Object)
        return BrkReadExceptionStatus[Broker.Selector](Broker.Object, DeviceID, Data);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_Diagnostics(XOBJECT& Broker, byte DeviceID, word SubFunction, void* pSendData, void* pRecvData, word ItemsToSend, word& ItemsReceived)
{
    if (Broker.Object)
        return BrkDiagnostics[Broker.Selector](Broker.Object, DeviceID, SubFunction, pSendData, pRecvData, ItemsToSend, ItemsReceived);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_GetCommEventCounter(XOBJECT& Broker, byte DeviceID, word& Status, word& EventCount)
{
    if (Broker.Object)
        return BrkGetCommEventCounter[Broker.Selector](Broker.Object, DeviceID, Status, EventCount);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_GetCommEventLog(XOBJECT& Broker, byte DeviceID, word& Status, word& EventCount, word& MessageCount, word& NumItems, void* Events)
{
    if (Broker.Object)
        return BrkGetCommEventLog[Broker.Selector](Broker.Object, DeviceID, Status, EventCount, MessageCount, NumItems, Events);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ReportServerID(XOBJECT& Broker, byte DeviceID, void* pUsrData, int& DataSize)
{
    if (Broker.Object)
        return BrkReportServerID[Broker.Selector](Broker.Object, DeviceID, pUsrData, DataSize);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_ExecuteMEIFunction(XOBJECT& Broker, byte DeviceID, byte MEI_Type, void* pWRUsrData, word WRSize, void* pRDUsrData, word& RDSize)
{
    if (Broker.Object)
        return BrkExecuteMEIFunction[Broker.Selector](Broker.Object, DeviceID, MEI_Type, pWRUsrData, WRSize, pRDUsrData, RDSize);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_CustomFunctionRequest(XOBJECT& Broker, byte DeviceID, byte UsrFunction, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    if (Broker.Object)
        return BrkCustomFunctionRequest[Broker.Selector](Broker.Object, DeviceID, UsrFunction, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API broker_RawRequest(XOBJECT& Broker, byte DeviceID, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected)
{
    if (Broker.Object)
        return BrkRawRequest[Broker.Selector](Broker.Object, DeviceID, pUsrPDUWrite, SizePDUWrite, pUsrPDURead, SizePDURead, SizePDUExpected);
    else
        return SetError(errNullObject);
}
//******************************************************************************
// DEVICE Lookup Tables for fast calling
//******************************************************************************
pfn_DevDestroy                  DevDestroy[3] = { tcpdev_Destroy, udpdev_Destroy, serdev_Destroy };
pfn_DevSetParam                 DevSetParam[3] = { tcpdev_SetParam, udpdev_SetParam, serdev_SetParam };
pfn_SetUserFunction             DevSetUserFunction[3] = { tcpdev_SetUserFunction, udpdev_SetUserFunction, serdev_SetUserFunction };
pfn_Start                       DevStart[3] = { tcpdev_Start, udpdev_Start, serdev_Start };
pfn_Stop                        DevStop[3] = { tcpdev_Stop, udpdev_Stop, serdev_Stop };
pfn_AddPeer                     DevAddPeer[3] = { tcpdev_AddPeer, udpdev_AddPeer, serdev_AddPeer };
pfn_RegisterArea                DevRegisterArea[3] = { tcpdev_RegisterArea, udpdev_RegisterArea, serdev_RegisterArea };
pfn_CopyArea                    DevCopyArea[3] = { tcpdev_CopyArea, udpdev_CopyArea, serdev_CopyArea };
pfn_LockArea                    DevLockArea[3] = { tcpdev_LockArea, udpdev_LockArea, serdev_LockArea };
pfn_UnlockArea                  DevUnlockArea[3] = { tcpdev_UnlockArea, udpdev_UnlockArea, serdev_UnlockArea };
pfn_RegisterCallback            DevRegisterCallback[3] = { tcpdev_RegisterCallback, udpdev_RegisterCallback, serdev_RegisterCallback };
pfn_PickEvent                   DevPickEvent[3] = { tcpdev_PickEvent, udpdev_PickEvent, serdev_PickEvent };
pfn_PickEventAsText             DevPickEventAsText[3] = { tcpdev_PickEventAsText, udpdev_PickEventAsText, serdev_PickEventAsText };
pfn_DevGetInfo                  DevGetDeviceInfo[3] = { tcpdev_GetInfo, udpdev_GetInfo, serdev_GetInfo }; 

//******************************************************************************
// DEVICE Entry Points
//******************************************************************************

EXPORTSPEC void SNAP_API device_CreateEthernet(XOBJECT& Device, int Proto, byte DeviceID, const char* Address, int Port)
{
    if (Proto == ProtoUDP || Proto == ProtoRTUOverUDP)
    {
        Device.Object = SNAP_Object(new TMBUdpDevice(Proto, DeviceID, Address, Port));
        Device.Selector = _UDPDevice;
    }
    else {
        Device.Object = SNAP_Object(new TMBTcpDevice(Proto, DeviceID, Address, Port));
        Device.Selector = _TCPDevice;
    }
}
//------------------------------------------------------------------------------
EXPORTSPEC void SNAP_API device_CreateSerial(XOBJECT& Device, int Format, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow)
{
    Device.Object = SNAP_Object(new TMBSerDevice(Format, DeviceID, PortName, BaudRate, Parity, DataBits, Stops, Flow));
    Device.Selector = _SerialDevice;
}
//------------------------------------------------------------------------------
EXPORTSPEC void SNAP_API device_Destroy(XOBJECT& Device)
{
    if (Device.Object)
    try
    {
        DevDestroy[Device.Selector](Device.Object);
    }catch(...){}
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_SetParam(XOBJECT& Device, int ParamIndex, int Value)
{
    if (Device.Object)
        return DevSetParam[Device.Selector](Device.Object, ParamIndex, Value);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_BindEthernet(XOBJECT& Device, byte DeviceID, const char* Address, int Port)
{
    if (Device.Object)
    {
        if (Device.Selector == _TCPDevice)
            return PMBTcpDevice(Device.Object)->SetDeviceBind(DeviceID, Address, Port);
        else
            return PMBUdpDevice(Device.Object)->SetDeviceBind(DeviceID, Address, Port);
    }
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_BindSerial(XOBJECT& Device, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow)
{
    if (Device.Object)
        return PMBSerDevice(Device.Object)->SetDeviceBind(DeviceID, PortName, BaudRate, Parity, DataBits, Stops, Flow);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_GetSerialInterframe(XOBJECT& Device, int& InterframeDelay, int& MaxInterframeDetected)
{
    if (Device.Object)
    {
        if (Device.Selector == _SerialDevice)
            return PMBSerDevice(Device.Object)->GetInterframe(InterframeDelay, MaxInterframeDetected);
        else {
            InterframeDelay = 0;
            MaxInterframeDetected = 0;
            return 0;
        }
    }
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_SetUserFunction(XOBJECT& Device, byte FunctionID, int Value)
{
    if (Device.Object)
        return DevSetUserFunction[Device.Selector](Device.Object, FunctionID, Value);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_Start(XOBJECT& Device)
{
    if (Device.Object)
        return DevStart[Device.Selector](Device.Object);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_Stop(XOBJECT& Device)
{
    if (Device.Object)
        return DevStop[Device.Selector](Device.Object);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_AddPeer(XOBJECT& Device, const char* Address)
{
    if (Device.Object)
        return DevAddPeer[Device.Selector](Device.Object, Address);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_RegisterArea(XOBJECT& Device, int AreaID, void* Data, int Amount)
{
    if (Device.Object)
        return DevRegisterArea[Device.Selector](Device.Object, AreaID, Data, Amount);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_CopyArea(XOBJECT& Device, int AreaID, word Address, word Amount, void* Data, int CopyMode)
{
    if (Device.Object)
        return DevCopyArea[Device.Selector](Device.Object, AreaID, Address, Amount, Data, CopyMode);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_LockArea(XOBJECT& Device, int AreaID)
{
    if (Device.Object)
        return DevLockArea[Device.Selector](Device.Object, AreaID);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_UnlockArea(XOBJECT& Device, int AreaID)
{
    if (Device.Object)
        return DevUnlockArea[Device.Selector](Device.Object, AreaID);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_RegisterCallback(XOBJECT& Device, int CallbackID, void* cbRequest, void* UsrPtr)
{
    if (Device.Object)
        return DevRegisterCallback[Device.Selector](Device.Object, CallbackID, cbRequest, UsrPtr);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_PickEvent(XOBJECT& Device, void* pEvent)
{
    if (Device.Object)
        return DevPickEvent[Device.Selector](Device.Object, pEvent);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_PickEventAsText(XOBJECT& Device, char* Text, int TextSize)
{
    if (Device.Object)
        return DevPickEventAsText[Device.Selector](Device.Object, Text, TextSize);
    else
        return SetError(errNullObject);
}
//------------------------------------------------------------------------------
EXPORTSPEC int SNAP_API device_GetDeviceInfo(XOBJECT& Device, TDeviceInfo& DeviceInfo)
{   
    if (Device.Object)
        return DevGetDeviceInfo[Device.Selector](Device.Object, DeviceInfo);
    else
        return SetError(errNullObject);
}
//******************************************************************************
// COMMON
//******************************************************************************
EXPORTSPEC const char* SNAP_API ErrorText(int Error, char* Text, int TextSize)
{
    return _ErrorText(Error, Text, TextSize);
}
//------------------------------------------------------------------------------
EXPORTSPEC const char* SNAP_API EventText(void* Event, char* Text, int TextSize)
{
    return _EventText(Event, Text, TextSize);
}

