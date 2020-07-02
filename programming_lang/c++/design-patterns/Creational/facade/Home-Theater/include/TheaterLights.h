#ifndef THEATERLIGHTS_H
#define THEATERLIGHTS_H

//Abstract class
class TheaterLights{
public:
	virtual void on()=0;
	virtual void off()=0;
	virtual void dim()=0;
};

#endif
