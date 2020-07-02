#ifndef HOME_THEATER_FACADE_H
#define HOME_THEATER_FACADE_H
#include"RoundTheaterLights.h"
#include"MetalPopCornPopper.h"
#include"LEDScreen.h"
#include"SonyDVDPlayer.h"

class HomeTheaterFacade{
	LEDScreen *les;		
	MetalpopCornPopper *mcp;
	RoundTheaterLights *rtl;
	SonyDVDPlayer *sdp;
public:
	HomeTheaterFacade(
		LEDScreen *l,
		MetalpopCornPopper *m,
		RoundTheaterLights *r,
		SonyDVDPlayer *s):les(l),mcp(m),rtl(r),sdp(s){}
	void switchOnHomeTheater();
	void switchOffHomeTheater();
};

#endif
