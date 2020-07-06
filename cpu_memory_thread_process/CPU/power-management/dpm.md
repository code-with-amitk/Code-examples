## DPM(Dynamic power management)
- **What** 
  - This is collaboration project between the IBM Austin Research Lab and MontaVista Software.
  - Project aims at making power consumption low by using open source software.
  -  GPU and memory clocks adjust dynamically based on load & saves power.
- This results in very low fan noise and heating.  

### Enabling AMD RADEON DPM in Ubuntu 13.0
  - Will work for Radeon HD 2000 graphics cards and newer
  - In Ubuntu 14.0 this may be enabled by default.
```
# vim /etc/default/grub
  GRUB_CMDLINE_LINUX_DEFAULT="quiet splash" radeon.dpm=1
# sudo update-grub
# reboot
```
