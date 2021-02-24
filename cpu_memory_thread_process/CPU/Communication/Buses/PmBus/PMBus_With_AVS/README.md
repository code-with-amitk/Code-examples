## PMBus (Power Management Bus) with AVS

## AVS(Adaptive Voltage Scaling) Bus
- **What:** This is dedicated bus to control processor voltages statically and dynamically. AVS is closed loop real time feedback from Devices to Voltage Regulator to update the voltage requested from the power supply.
- **Adv:** Intelligent power consumption savings.

### AVS [Frames](https://pmbus.org/Assets/PDFS/Public/20130912PMBus_1-3_DPF.pdf)
```c
 Write Frame (32 bit)

  
 Read Frame (32 bit)
```
### AVSBus Commands
```c
– Target Rail Voltage
– Target Rail Vout Transition Rate (Rising and Falling)
– Rail Current (read only)
– Rail Temperature (read only)
– Reset Rail Voltage to Default Value (write only)
– Power Mode (Full Power, Maximum Efficiency)
– AVSBus Status (VGood, OCW, UVW, OTW, OPW)
– AVSBus Version
```
