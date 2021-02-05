#ifndef DVDPLAYER_H
#define DVDPLAYER_H

//Abstract class
class DVDPlayer{
public:
	virtual void on()=0;
	virtual void off()=0;
	virtual void eject()=0;
	virtual void pause()=0;
	virtual void play()=0;
	virtual void setSurroundSound()=0;
	virtual void setTwoChannelAudio()=0;
	virtual void stop()=0;
};

#endif
