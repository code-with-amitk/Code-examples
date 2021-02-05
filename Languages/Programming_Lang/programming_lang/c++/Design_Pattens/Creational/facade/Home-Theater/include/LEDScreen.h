#ifndef LEDSCREEN_H
#define LEDSCREEN_H
#include"screen.h"

class LEDScreen:public screen{
public:
	void brightness();
	void on();
	void off();
};

#endif
