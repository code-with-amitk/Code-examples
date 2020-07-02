#ifndef SONY_DVDPLAYER_H
#define SONY_DVDPLAYER_H
#include"DVDPlayer.h"

class SonyDVDPlayer:public DVDPlayer{
public:
	virtual void on();
	virtual void off();
	virtual void eject();
	virtual void pause();
	virtual void play();
	virtual void setSurroundSound();
	virtual void setTwoChannelAudio();
	virtual void stop();
};

#endif
