#ifndef SCREEN_H
#define SCREEN_H

//Abstract class
class screen{
public:
	virtual void brightness()=0;
	virtual void on()=0;
	virtual void off()=0;
};

#endif
