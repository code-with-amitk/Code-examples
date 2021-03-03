## Target Unit 
- **What?** 
  - systemd units named as `*.target`. Every target has a configuration file at `/usr/lib/systemd/*target`. 
  - To define the various system states, the SysV uses numbers, known as run-levels, while the Systemd uses keyword, known as target-units. Eg: Graphical, Multiuser, Rescue, Emergency
  - One target can be part of another target. Eg: graphical.target includes multi-user.target which in turn depends on basic.target.
  - 
### Commands
- Listing all available targets and check which current?
```c
    $ systemctl    list-units    --type=target    --all    
    $ vim    /usr/lib/systemd/*.target
    # systemctl    get-default
        graphical.target
```
- Listing Dependencies
```c
    $ systemctl    list-dependencies    graphical.target    |    grep target
```
- Setting the mode/target
```html
    # systemctl     set-default    graphical.target
    # systemctl    isolate    multi-user.target            //This changes system to Text-mode without booting the system. System is still in graphical mode.    #systemctl isolate <dst-target-system>
    # systemctl    ioslate    graphical.target            //Brings back Graphical.target
```
- Booting kernel in rescue.target/emergency.target
```html
        <Interrupt boot loader by pressing any key>
        <Press e to edit command line>    At end of Line starting with linux16 enter       systemd.unit=rescue.target 
        <Press Ctrl+x to save and exit>
        systemd.unit=emergency.target        //This boots root system in RO mode. 
```
