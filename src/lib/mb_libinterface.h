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
#ifndef mb_libinterface_h
#define mb_libinterface_h
//---------------------------------------------------------------------------
#include "mb_netclient.h"
#include "mb_fieldcontroller.h"
#include "mb_serclient.h"
#include "mb_tcpdevice.h"
#include "mb_udpdevice.h"
#include "mb_serdevice.h"
#include "mb_serchannels.h"
#include "mb_text.h"
//---------------------------------------------------------------------------

typedef uintptr_t SNAP_Object; // multi platform/processor object reference

#pragma pack(1)

typedef struct {
	uintptr_t Object;
	uintptr_t Selector;
}XOBJECT;

#pragma pack()

//==============================================================================
// POLYMORPHIC BROKER (CONTROLLER/CLIENT)                                   
//==============================================================================
#define _FieldController    0
#define _EthernetClient     1
#define _SerialClient       2

typedef void (*pfn_Destroy)(SNAP_Object& Broker);

typedef int (*pfn_SetLocalParam)(SNAP_Object Broker, byte ClientID, int ParamIndex, int Value);
typedef int (*pfn_SetClientParam)(SNAP_Object Broker, byte ClientID, int ParamIndex, int Value);
typedef int (*pfn_SetRemoteDeviceParam)(SNAP_Object Broker, byte DeviceID, int ParamIndex, int Value);
typedef int (*pfn_Connect)(SNAP_Object Broker);
typedef int (*pfn_Disconnect)(SNAP_Object Broker);
typedef int (*pfn_GetIOBufferPtr)(SNAP_Object Broker, byte DeviceID, int BufferKind, pbyte &Data);
typedef int (*pfn_GetIOBuffer)(SNAP_Object Broker, byte DeviceID, int BufferKind, pbyte Data);
typedef int (*pfn_GetDeviceStatus)(SNAP_Object Broker, byte DeviceID, TDeviceStatus& DeviceStatus);
typedef int (*pfn_ReadHoldingRegisters)(SNAP_Object Broker, byte DeviceID, word Address, word Amount, void*pUsrData);
typedef int (*pfn_WriteMultipleRegisters)(SNAP_Object Broker, byte DeviceID, word Address, word Amount, void*pUsrData);
typedef int (*pfn_ReadCoils)(SNAP_Object Broker, byte DeviceID, word Address, word Amount, void*pUsrData);
typedef int (*pfn_ReadDiscreteInputs)(SNAP_Object Broker, byte DeviceID, word Address, word Amount, void*pUsrData);
typedef int (*pfn_ReadInputRegisters)(SNAP_Object Broker, byte DeviceID, word Address, word Amount, void*pUsrData);
typedef int (*pfn_WriteSingleCoil)(SNAP_Object Broker, byte DeviceID, word Address, word Value);
typedef int (*pfn_WriteSingleRegister)(SNAP_Object Broker, byte DeviceID, word Address, word Value);
typedef int (*pfn_ReadWriteMultipleRegisters)(SNAP_Object Broker, byte DeviceID, word RDAddress, word RDAmount, word WRAddress, word WRAmount, void*pRDUsrData, void*pWRUsrData);
typedef int (*pfn_WriteMultipleCoils)(SNAP_Object Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
typedef int (*pfn_MaskWriteRegister)(SNAP_Object Broker, byte DeviceID, word Address, word AND_Mask, word OR_Mask);
typedef int (*pfn_ReadFileRecord)(SNAP_Object Broker, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData);
typedef int (*pfn_WriteFileRecord)(SNAP_Object Broker, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData);
typedef int (*pfn_ReadFIFOQueue)(SNAP_Object Broker, byte DeviceID, word Address, word& FifoCount, void* FIFO);
typedef int (*pfn_ReadExceptionStatus)(SNAP_Object Broker, byte DeviceID, byte& Data);
typedef int (*pfn_Diagnostics)(SNAP_Object Broker, byte DeviceID, word SubFunction, void* pSendData, void* pRecvData, word ItemsToSend, word& ItemsReceived);
typedef int (*pfn_GetCommEventCounter)(SNAP_Object Broker, byte DeviceID, word& Status, word& EventCount);
typedef int (*pfn_GetCommEventLog)(SNAP_Object Broker, byte DeviceID, word& Status, word& EventCount, word& MessageCount, word& NumItems, void* Events);
typedef int (*pfn_ReportServerID)(SNAP_Object Broker, byte DeviceID, void*pUsrData, int& DataSize);
typedef int (*pfn_ExecuteMEIFunction)(SNAP_Object Broker, byte DeviceID, byte MEI_Type, void*pWRUsrData, word WRSize, void*pRDUsrData, word& RDSize);
typedef int (*pfn_CustomFunctionRequest)(SNAP_Object Broker, byte DeviceID, byte UsrFunction, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected);
typedef int (*pfn_RawRequest)(SNAP_Object Broker, byte DeviceID, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected);

// Control functions
EXPORTSPEC void SNAP_API broker_CreateFieldController(XOBJECT& Broker);
EXPORTSPEC void SNAP_API broker_CreateEthernetClient(XOBJECT& Broker, int Proto, const char* Address, int Port);
EXPORTSPEC void SNAP_API broker_CreateSerialClient(XOBJECT& Broker, int Format, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow);
EXPORTSPEC void SNAP_API broker_Destroy(XOBJECT& Broker);
EXPORTSPEC int SNAP_API broker_Connect(XOBJECT& Broker);
EXPORTSPEC int SNAP_API broker_Disconnect(XOBJECT& Broker);
EXPORTSPEC int SNAP_API broker_AddControllerNetDevice(XOBJECT& Broker, int Proto, byte DeviceID, const char* Address, int Port);
EXPORTSPEC int SNAP_API broker_AddControllerSerDevice(XOBJECT& Broker, int Format, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow);
EXPORTSPEC int SNAP_API broker_SetLocalParam(XOBJECT& Broker, byte LocalID, int ParamIndex, int Value);
EXPORTSPEC int SNAP_API broker_SetRemoteDeviceParam(XOBJECT& Broker, byte DeviceID, int ParamIndex, int Value);
EXPORTSPEC int SNAP_API broker_GetIOBufferPtr(XOBJECT& Broker, byte DeviceID, int BufferKind, pbyte &Data);
EXPORTSPEC int SNAP_API broker_GetIOBuffer(XOBJECT& Broker, byte DeviceID, int BufferKind, pbyte Data);
EXPORTSPEC int SNAP_API broker_GetDeviceStatus(XOBJECT& Broker, byte DeviceID, TDeviceStatus& DeviceStatus);
// Modbus functions
EXPORTSPEC int SNAP_API broker_ReadHoldingRegisters(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
EXPORTSPEC int SNAP_API broker_WriteMultipleRegisters(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
EXPORTSPEC int SNAP_API broker_ReadCoils(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
EXPORTSPEC int SNAP_API broker_ReadDiscreteInputs(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
EXPORTSPEC int SNAP_API broker_ReadInputRegisters(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
EXPORTSPEC int SNAP_API broker_WriteSingleCoil(XOBJECT& Broker, byte DeviceID, word Address, word Value);
EXPORTSPEC int SNAP_API broker_WriteSingleRegister(XOBJECT& Broker, byte DeviceID, word Address, word Value);
EXPORTSPEC int SNAP_API broker_ReadWriteMultipleRegisters(XOBJECT& Broker, byte DeviceID, word RDAddress, word RDAmount, word WRAddress, word WRAmount, void* pRDUsrData, void* pWRUsrData);
EXPORTSPEC int SNAP_API broker_WriteMultipleCoils(XOBJECT& Broker, byte DeviceID, word Address, word Amount, void* pUsrData);
EXPORTSPEC int SNAP_API broker_MaskWriteRegister(XOBJECT& Broker, byte DeviceID, word Address, word AND_Mask, word OR_Mask);
EXPORTSPEC int SNAP_API broker_ReadFileRecord(XOBJECT& Broker, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData);
EXPORTSPEC int SNAP_API broker_WriteFileRecord(XOBJECT& Broker, byte DeviceID, byte RefType, word FileNumber, word RecNumber, word RegsAmount, void* RecData);
EXPORTSPEC int SNAP_API broker_ReadFIFOQueue(XOBJECT& Broker, byte DeviceID, word Address, word& FifoCount, void* FIFO);
EXPORTSPEC int SNAP_API broker_ReadExceptionStatus(XOBJECT& Broker, byte DeviceID, byte& Data);
EXPORTSPEC int SNAP_API broker_Diagnostics(XOBJECT& Broker, byte DeviceID, word SubFunction, void* pSendData, void* pRecvData, word ItemsToSend, word& ItemsReceived);
EXPORTSPEC int SNAP_API broker_GetCommEventCounter(XOBJECT& Broker, byte DeviceID, word& Status, word& EventCount);
EXPORTSPEC int SNAP_API broker_GetCommEventLog(XOBJECT& Broker, byte DeviceID, word& Status, word& EventCount, word& MessageCount, word& NumItems, void* Events);
EXPORTSPEC int SNAP_API broker_ReportServerID(XOBJECT& Broker, byte DeviceID, void* pUsrData, int& DataSize);
EXPORTSPEC int SNAP_API broker_ExecuteMEIFunction(XOBJECT& Broker, byte DeviceID, byte MEI_Type, void* pWRUsrData, word WRSize, void* pRDUsrData, word& RDSize);
EXPORTSPEC int SNAP_API broker_CustomFunctionRequest(XOBJECT& Broker, byte DeviceID, byte UsrFunction, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected);
EXPORTSPEC int SNAP_API broker_RawRequest(XOBJECT& Broker, byte DeviceID, void* pUsrPDUWrite, word SizePDUWrite, void* pUsrPDURead, word& SizePDURead, word SizePDUExpected);

//==============================================================================
// POLYMORPHIC DEVICE
//==============================================================================
#define _TCPDevice    0
#define _UDPDevice    1
#define _SerialDevice 2

typedef void (*pfn_DevDestroy)(SNAP_Object& Device);
typedef int (*pfn_DevSetParam)(SNAP_Object Device, int ParamIndex, int Value);
typedef int (*pfn_SetUserFunction)(SNAP_Object Device, byte FunctionID, int Value);
typedef int (*pfn_Start)(SNAP_Object Device);
typedef int (*pfn_Stop)(SNAP_Object Device);
typedef int (*pfn_AddPeer)(SNAP_Object Device, const char* Address);
typedef int (*pfn_RegisterArea)(SNAP_Object Device, int AreaID, void* Data, int Amount);
typedef int (*pfn_CopyArea)(SNAP_Object Device, int AreaID, word Address, word Amount, void* Data, int CopyMode);
typedef int (*pfn_LockArea)(SNAP_Object Device, int AreaID);
typedef int (*pfn_UnlockArea)(SNAP_Object Device, int AreaID);
typedef int (*pfn_RegisterCallback)(SNAP_Object Device, int CallbackID, void* cbRequest, void* UsrPtr);
typedef int (*pfn_PickEvent)(SNAP_Object Device, void* pEvent);
typedef int (*pfn_PickEventAsText)(SNAP_Object Device, char* Text, int TextSize);
typedef int (*pfn_DevGetInfo)(SNAP_Object Device, TDeviceInfo& DeviceInfo);

EXPORTSPEC void SNAP_API device_CreateEthernet(XOBJECT& Device, int Proto, byte DeviceID, const char* Address, int Port);
EXPORTSPEC void SNAP_API device_CreateSerial(XOBJECT& Device, int Format, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow);
EXPORTSPEC void SNAP_API device_Destroy(XOBJECT& Device);
EXPORTSPEC int SNAP_API device_SetParam(XOBJECT& Device, int ParamIndex, int Value);
EXPORTSPEC int SNAP_API device_BindEthernet(XOBJECT& Device, byte DeviceID, const char* Address, int Port);
EXPORTSPEC int SNAP_API device_BindSerial(XOBJECT& Device, byte DeviceID, const char* PortName, int BaudRate, char Parity, int DataBits, int Stops, int Flow);
EXPORTSPEC int SNAP_API device_GetSerialInterframe(XOBJECT& Device, int& InterframeDelay, int& MaxInterframeDetected);
EXPORTSPEC int SNAP_API device_SetUserFunction(XOBJECT& Device, byte FunctionID, int Value);
EXPORTSPEC int SNAP_API device_Start(XOBJECT& Device);
EXPORTSPEC int SNAP_API device_Stop(XOBJECT& Device);
EXPORTSPEC int SNAP_API device_AddPeer(XOBJECT& Device, const char* Address);
EXPORTSPEC int SNAP_API device_RegisterArea(XOBJECT& Device, int AreaID, void* Data, int Amount);
EXPORTSPEC int SNAP_API device_CopyArea(XOBJECT& Device, int AreaID, word Address, word Amount, void* Data, int CopyMode);
EXPORTSPEC int SNAP_API device_LockArea(XOBJECT& Device, int AreaID);
EXPORTSPEC int SNAP_API device_UnlockArea(XOBJECT& Device, int AreaID);
EXPORTSPEC int SNAP_API device_RegisterCallback(XOBJECT& Device, int CallbackID, void* cbRequest, void* UsrPtr);
EXPORTSPEC int SNAP_API device_PickEvent(XOBJECT& Device, void* pEvent);
EXPORTSPEC int SNAP_API device_PickEventAsText(XOBJECT& Device, char* Text, int TextSize);
EXPORTSPEC int SNAP_API device_GetDeviceInfo(XOBJECT& Device, TDeviceInfo& DeviceInfo);

//==============================================================================
// MISC                                    
//==============================================================================
EXPORTSPEC const char* SNAP_API ErrorText(int Error, char* Text, int TextSize);
EXPORTSPEC const char* SNAP_API EventText(void* Event, char* Text, int TextSize);


#endif // mb_libinterface_h

