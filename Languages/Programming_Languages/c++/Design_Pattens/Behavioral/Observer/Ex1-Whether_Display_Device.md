## Design a Whether Display Device.
- Whether display device is wall mounted and will diplay temp, pressure, humidity.
- **Design**
  - _1._ Sensor: Measures the temp, humidity, pressure.
  - _2._ Collector(Subject): Recieves information from and processes it for display.
  - *c.* Display-devices(Observer):
    - Registers themseleves to subject.
    - Receives trigger in case of event.

```c
              ------------Whether Display Device----------------------- 
              |                                                        |
              |     -------             Subject            Observer    |
temprature->  |    |        | -tem->  -------------      ------------  |    User
  Humidity->  |    | Sensor | -Hum->  | Collector | --> |Display Unit| |     0
  Pressure->  |    |        | -Prr->  | (subject) |      ------------  |    /|\
              |     -------            -----------                     |    /|\
              |                                                        |
               --------------------------------------------------------
```

### Code    
```c++
- sensor: Not implementing this. main() acts as sensor.
- collector:
- display-device:
*/
#include<iostream>
#include<vector>
using namespace std;

class CollectorIntf;
class DisplayIntf{
public:
        virtual void RegisterToSubject(CollectorIntf *)=0;
        virtual void RecievedNotification(float,float,float)=0;
};

/*********************Collector*****************************/
class CollectorIntf{
public:
        virtual void NotifyObservers()=0;
        virtual void SetObservers(DisplayIntf *)=0;
        virtual void removeObservers(DisplayIntf *)=0;
};

class Collector:public CollectorIntf{
        float temp, humdity, pressure;
        vector <DisplayIntf *> observers;
public:
        void removeObservers(DisplayIntf *){}

        /*override(C++11): Specifically tells this function is overriden from base class
        not to be confused with similar-named function not declared in interface*/
        void SetObservers(DisplayIntf *p) override{
                cout<<"[Collector] Registered "<<p<<endl;
                observers.push_back(p);
        }
        void NotifyObservers() override{
                for(auto i=observers.begin(); i!=observers.end(); i++){
                        (*i)->RecievedNotification(temp,humdity, pressure);
                }
        }
        void GetMeasurements(float a, float b, float c){
                temp=a; humdity=b; pressure=c;
                cout<<"[Collector] recieved measurements from sensor\
        ..Notifying Observers\n";
                NotifyObservers();
        }
};


/********************Display*****************************/
class DisplayUnit1:public DisplayIntf{
public:
        void RegisterToSubject(CollectorIntf *p){
                cout<<"[Display-Unit/Observer] "<<this<<" Registering to Collector(Subject)\n";
                p->SetObservers(this);
        }
        void RecievedNotification(float t, float h, float p){
                cout<<"[Display-Unit/Observer] recievedNotification, showing data:\n\
                        Temprature:"<<t<<"\n\
                        Humidity:"<<h<<"\n\
                        Pressure:"<<p<<"\n\
                        \n";
        }
};

/********************Driver*****************************/
int main(){
        Collector *co = new Collector();

        DisplayIntf *dis = new DisplayUnit1();          //Object
        dis->RegisterToSubject(co);                     //Object registers to subject

        co->GetMeasurements(10.1,20.5,30.7);            //Sensor provides measurements to collector
        //tempDisplay tdo;
        //tdo.registerToSubject(&co);
}
/*
# ./a.out 
[Display-Unit/Observer] 0x178aeb0 Registering to Collector(Subject)
[Collector] Registered 0x178aeb0
[Collector] recieved measurements from sensor   ..Notifying Observers
[Display-Unit/Observer] recievedNotification, showing data:
                        Temprature:10.1
                        Humidity:20.5
                        Pressure:30.7
*/
```
