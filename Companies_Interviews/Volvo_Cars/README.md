- [Volvo cars Architecture](#ar)
- **April, 2022**
  - [R1. Online Assesement](#r1)
  - [R2. OOD](#r2)

<a name=ar></a>
### Architecture
**Present Day: Based on ECU(Electric control Unit)**
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
**Future: Core computer**
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

### April,2022
<a name=r1></a>
#### R1. Online Assesement

<a name=r2></a>
#### R2. OOD. Design Perception function
**Question**
- Vehicle is equipped with: 
  - _1. front looking camera:_ Will just just click photos.
  - _2. front looking radar:_ Using electromagnetic sensor it detects/recognizes various objects and their distances.
- Write a perception function for self driven vehicle.
```c
//Read surrounding env of the vehicle
//Provide information to other functions(path_planner(), acutator_control())
perception_func() {
  //Every 1ms
	path_planner_func();
	acutator_control_func();
}
```
**Design**
- _1._ Camera, Radar are independent functions which clicks photo, detects object every 1 ms and inputs to some queue.
```c
 Every 1 ms
  Camera(Click photo) pushes on queue.
                                      | <photo,timestamp=11.02am> | <photo,timestamp=11.01am> |
                                      top
  Radar(Senses object,distance,angle) & push on queue.
    obj=<len,bre,height>, vector<obj>
                                     | <<obj1,dis1,angle1>,<obj2,dis2,angle2>,timestamp=11.02am> |...|
                                      top
```
- _2._ Perception function will pop tops of both queues. Matches timestamps.
```c
perception_func() {
  camera_object co = top_queue_camera()
  radar_object ro = top_queue_radar()
  
  if (co.timestamp == ro.timestamp){ //if timestamps match
    //Try Predicting Object name and distance
    
  }
}
```
