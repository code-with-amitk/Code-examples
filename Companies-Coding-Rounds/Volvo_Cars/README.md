- [Volvo cars Architecture](#ar)
- **Roles**
  - [Position: Senior Software Developer (Gothenberg, Sweden)](#p1)

<a name=ar></a>
### Architecture
#### Present Day: Based on ECU(Electric control Unit)
  - Around 100+ ECU, which talk to each other/dashboard.
  - These are sort of firmware(Hardware+ complied software) maybe from different vendors.
  - Used to control behaviour of components(Eg: parking camera)
```c
    -| |--------------Volvo car------------
    |
    |   ecu-vendor-1-------------|---|--------ecu-vendor-3
    |                            |
    |        ecu-vendorn---------|
    |
    -| |-----------------------------------| |-
```
#### Future: Core computer
- Car will have high end CPU/GPU 2 boxes which communicate over other components over ethernet.
- Does not rely on supplier provided ECUs for behaviour we want.
- Work load is distributed between these core_computers using distributed framework.
```c
    -| |--------------Volvo car------------
    |
    |   ecu-1---LAN(ethernet cable)------core_computer-1
    |                     |
    |        ecu-n--------|     core_computer_2
    |
    -| |-----------------------------------| |-
```
Volvo cars will launch its own OS.

<a name=p1></a>
### Position: Senior Software Developer: Onboard Core Computer (Gothenberg, Sweden)
#### Mission
  - Self-driving
  - Fully electric(Green)
  - Connected, and super safe vehicle.
#### Challenges
Around +140 electric components in the car do not communicate the way we want it to
#### Solution
Build Onboard core computer with the capacity to carry a vast majority of electric control units and applications.
#### Responsibilities
- On board application design,
- Develop software components for onboard systems
- API review/governance for our onboard systems, API development, Supporting our R&D org at large with your software skills.
