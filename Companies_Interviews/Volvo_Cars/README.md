- [Volvo cars Architecture](#ar)
- **April, 2022**
  - [R1. Online Assesement](#r1)
  - [R2. OOD](#r2)
  - [R3](#r3)

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

## April,2022
<a name=r1></a>
### R1. Online Assesement

<a name=r2></a>
### R2. OOD. Design Perception function
#### 1. Write a perception function for self driven vehicle
- Vehicle is equipped with: 
  - _1. front looking camera:_ Will just just click photos.
  - _2. front looking radar:_ Using electromagnetic sensor it detects/recognizes various objects and their distances.
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
//listen on kafka or timer expiry
perception_func() {
  camera_object co = top_queue_camera()
  radar_object ro = top_queue_radar()
  
  if (co.timestamp == ro.timestamp){ //if timestamps match
	predict_objects_in_picture(vector<radar_obj>)
  }
}

//Try Predicting Object name
predict_objects_in_picture(vector<radar_obj>& ) {
  //1. Use opencv for image recognizance. OpenCV searches for objects within a picture. It does not names objects.
  (https://github.com/amitkumar50/Code-examples/tree/master/Languages/ScriptingLanguages/Python/machine_learning)
  array_of_images(x,y,z,w) arr = opencv_recognize_objects();
    
  //2. Library-2 to name objects.
  object_names[] = lib-2_fun(array_of_images);
  for (auto &i:object_names){
	//i=cat
	ret = predict_distance_direction(cat, vector<radar_object>& )
  }
}

//3. Library-3 to predict distance,direction,angle of object
predict_distance_direction(object_name(cat), vector<radar_object>& ) {
  dis(x,y,z,degree,time_to_hit) = lib-3_fun(cat, vector<radar_object>&)
  if (dis != 0) {
  	//This is cat coming
	vector<radar_object>& .remove(cat)	//Delete entry from radar vector
	
	//4. Provide data to path planner function
	path_planner_func (dis);
  }
  else {
  	//Wrong prediction
  }
}
```
#### OOD
```c
Objects:
  Camera
  Radar
  Perception_Module
  Path_Planner_Module
  Acutator_Module
                       |---------Camera---------------|
		       | camera(vector<resolution>){  |
		       |   for (num of cameras)       |
		       |    init_camera(callback())-----------------> firmware ----init----> CAMERA-1
		       | }                            |
		       | thread-1{
		       | camera_callback() {          |                                     click_picture
		       |           <---------------- picture, timestamp-----------------------------
		       |  publish on Embedded_Queue   |
		       |   }                          |
		       | }                            |
		       |------------------------------|
		       
		       |------Radar------------|         |-----PerceptionServer----------------|
		       |thread-1 {             |         | Check Acutator,Path Planner on pipe |
		       |  publish on queue     |         | thread-1 {
		       |}                      |         |  listen on queue-1
		       |                       |         | }
		       |-----------------------|         | thread-2 {
		                                         |  listen on queue-2
		       				         | }
							 | As events arrive, check timestamps  |
							 |-------------------------------------|
main() {               
 PathPlanner OPathPlanner;
 AcutatorServer OAcutator;
 PerceptionServer OPerceptionServer;
 Camera OCamera;
 Radar ORadar;
 
}
```

<a name=r3></a>
### Round-3
- Sprint cycle, agile, scrum, Jenkins rule writing, Creating CI/CD pipeline(Have you written)?
