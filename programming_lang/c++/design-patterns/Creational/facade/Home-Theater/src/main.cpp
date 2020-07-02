#include"config.h"
#include"LEDScreen.h"
#include"MetalPopCornPopper.h"
#include"RoundTheaterLights.h"
#include"HomeTheaterFacade.h"
#include"SonyDVDPlayer.h"

int main(){
	LEDScreen *l = new LEDScreen();
	MetalpopCornPopper *m = new MetalpopCornPopper();
	RoundTheaterLights *r = new RoundTheaterLights();
	SonyDVDPlayer *s = new SonyDVDPlayer();
	
	HomeTheaterFacade *h = new HomeTheaterFacade(l,m,r,s);	
	cout<<"\nButton-1 Pressed STARTING YOUR HOME THEATER! Enjoy your time\n";
	h->switchOnHomeTheater();
	cout<<"\nButton-2 Pressed SWITCHING OFF YOUR HOME THEATER! \n";
	h->switchOffHomeTheater();
}
