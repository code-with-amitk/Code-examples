#include"HomeTheaterFacade.h"

void HomeTheaterFacade::switchOnHomeTheater(){
	rtl->on();
	mcp->on();
	les->on();
	les->brightness();
	mcp->pop();
	sdp->on();
	sdp->pause();
	sdp->play();
	sdp->setSurroundSound();
	sdp->setTwoChannelAudio();
}

void HomeTheaterFacade::switchOffHomeTheater(){
	rtl->off();
	mcp->off();
	les->off();
	mcp->off();
	sdp->eject();
	sdp->stop();
	sdp->off();
}

