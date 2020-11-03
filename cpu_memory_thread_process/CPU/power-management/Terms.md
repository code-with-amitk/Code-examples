## 1. Voltage 
- **Voltage?** Voltage, electric potential difference, electric pressure or electric tension is the difference in electric potential between two points.
- **Voltage Regulator?** Component which takes varied voltage and outputs regulated/cutted voltage.
  - 1 VR supports 2 SVI planes/domains.
```c
--Varying Voltage--> |Voltage Regulator| ---Stable Voltage-->
```
- **SVI(Serial VID Interface) Controller/Regulator?** Allows dynamic adjustment of the Core and Northbridge output voltages independently and in combination from 0.500V to 1.55V. Voltage control is done using SVI.
- **Voltage Control Types?**
  - *1.* SVI Based voltage control
  - *2.* I2C based voltage control
  - *3.* Parallel based Voltage control/GPI
### Voltage Rails?
- **Rail?**
  - In a PC, different components use different voltage levels, and so a power supply must take the electricity from the wall and split it into 12v, 5v, and 3.3v power
  - A rail is simple a wire/path inside the PSU that carries electricity of a certain voltage.
  - The 12v rail provides power for GPUs and CPUs, generally the two most power-hungry components.
- **Voltage Rail Types?**
  - *1. GFX:* voltage in use while GPU is not idle
  - *2. SOC:* voltage floor for rest of the the SoC(System on chip).
  - *3. HBM:*
  - *4. PCIE:*
  - *5. VPP:*  
  - *6. SVI:*  1 SVI rail can support upto 2 planes
-  
  
## 2. POWERPLAY
- **What** Set of technologies for the reduction of the energy consumption in AMD's GPUs & APUs supported by graphics device driver "Catalyst".
- **Functions** Reduce energy consumption, lower the noise levels created by the cooling in desktop, mobile devices.
- This succeeds AMD's powertune.

## 3. DPM(Dynamic power management)
- **What?** This is collaboration project between the IBM Austin Research Lab and MontaVista Software. Project aims at making power consumption low by using open source software.
GPU and memory clocks adjust dynamically on load & saves power. This results in very low fan noise and heating.
- **Enabling AMD RADEON DPM in Ubuntu 13.0** Will work for Radeon HD 2000 graphics cards and newer. In Ubuntu 14.0 this may be enabled by default.
```c++
# vim /etc/default/grub
  GRUB_CMDLINE_LINUX_DEFAULT="quiet splash" radeon.dpm=1
# sudo update-grub
# reboot
```

## 4. ACPI(Advanced Configuration and Power Interface)
- **What** 
  - This is a open standard that Operating Systems can use for configuring hardware for least ***power management***.
  - ACPI brings the power management under the control of the operating system, earlier it was controlled by BIOS & platform-specific firmware.
- **How It works** 
  - Putting unused components to sleep
  - Perform status monitoring.
- ACPI replaces ***Advanced Power Management (APM)*** & ***Plug and Play BIOS (PnP) Specification***. 
- **(ACPICA) ACPI Component Architecture**
[Official URL](https://acpica.org/)
  - provides an operating system (OS)-independent reference implementation of the Advanced Configuration and Power Interface Specification (ACPI).
  
## 5. SMU(System Management Unit)
- This is an advanced internal subsystem introduced in 2004 with the iMac G5 and Power Mac G5 series computers.
- **What it does**
  - Power management. Earlier done by PMU(Power managment unit)
  - Cooling functions.
  - keeping audible noise to a minimum
  - OS monitors power consumption and temperature & sends to SMU. The SMU makes the changes, slowing down or speeding up fans as necessary.
- **PMU (Power Management Unit)**

