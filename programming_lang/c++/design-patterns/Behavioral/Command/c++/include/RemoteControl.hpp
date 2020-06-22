#ifndef REMOTECONTROL
#define REMOTECONTROL

#include "Command.hpp"

class RemoteControl
{
        Command* onCom[5];
        Command* offCom[5];
public:
        RemoteControl();
	void setCommand(int i, Command *on, Command *off);
	void onButtonWasPushed(int i);
	void offButtonWasPushed(int i);
};
#endif
