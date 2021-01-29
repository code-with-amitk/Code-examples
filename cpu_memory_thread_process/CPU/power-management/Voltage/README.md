### Terms
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
- **Rail?** In a PC, different components use different voltage levels, and so a power supply must take the electricity from the wall and split it into 12v, 5v, and 3.3v power. A rail is simple a wire/path inside the PSU that carries electricity of a certain voltage. The 12v rail provides power for GPUs and CPUs, generally the two most power-hungry components.
- **Voltage Rail Types?**
  - *1. GFX:* voltage in use while GPU is not idle
  - *2. SOC:* voltage floor for rest of the the SoC(System on chip).
  - *3. HBM:*
  - *4. PCIE:*
  - *5. VPP:*  
  - *6. SVI:*  1 SVI rail can support upto 2 planes
-  
