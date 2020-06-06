#include "RemoteControl.hpp"
#include "NoCommand.hpp"

RemoteControl::RemoteControl()
{
       Command *noCom = new NoCommand();

	for (int i=0; i<5; i++)
	{
		onCom[i] = noCom;
        	offCom[i] = noCom;
	}
}

void RemoteControl::setCommand(int i, Command *on, Command *off)
{
	onCom[i] = on;
        offCom[i] = off;
}

void RemoteControl::onButtonWasPushed(int i) 
{
	onCom[i]->execute();
}

void RemoteControl::offButtonWasPushed(int i) 
{
	offCom[i]->execute();
}
