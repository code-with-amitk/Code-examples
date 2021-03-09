### Pre-requisites
- WDF(Windows Driver Framework) These are collection of libraries for writing Windows Device Drivers. WDF-10 is provided with Microsoft Visual 2015.This is comprised of:
- KMDF(Kernel Mode Driver Framework)
- UMDF(User Mode Driver Framework): 
  - This is subset of KMDF.
  - These are used for packet based devices. Eg; USB. Where you are sending data across the bus.
  - It is not good for high speed devices.
- What is Universal Windows Driver? Writing 1 driver that runs on all platforms from Embedded systems, tablets, Desktop PCs.
- Writing Universal Windows Driver (KDMF)
  - You have Microsoft Visual Studio 2015, Windows Driver Kit (WDK-10) installed.
  - Microsoft Visual Studio -> New -> Project -> WDF -> KDMF Mode Driver -> Name(KDMFHelloWorld).
  - Configuration Properties -> Driver Settings -> General -> Target Platform (Universal).
  - Add driver.c file inside "Source Files". Open file, paste this code:

### Code
```c
#include <ntddk.h>
#include <wdf.h>
DRIVER_INITIALIZE DriverEntry;
EVT_WDF_DRIVER_DEVICE_ADD KmdfHelloWorldEvtDeviceAdd;

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject, _In_ PUNICODE_STRING RegistryPath){
    NTSTATUS status;
    WDF_DRIVER_CONFIG config;
    KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry\n" ));
    WDF_DRIVER_CONFIG_INIT(&config, KmdfHelloWorldEvtDeviceAdd);
    status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);
    return status;
}

NTSTATUS KmdfHelloWorldEvtDeviceAdd(_In_ WDFDRIVER Driver, _Inout_ PWDFDEVICE_INIT DeviceInit){
    NTSTATUS status;
    WDFDEVICE hDevice;
    UNREFERENCED_PARAMETER(Driver);
    KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: KmdfHelloWorldEvtDeviceAdd\n" ));
    status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);
    return status;
}
```
