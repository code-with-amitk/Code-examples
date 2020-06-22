#ifndef GARAGEDOORCLOSEDCOMMAND_H
#define GARAGEDOORCLOSEDCOMMAND_H

#include "GarageDoor.hpp"
#include "Command.hpp"

class GarageDoorClosedCommand : public Command
{
	GarageDoor *g;
public:	
	GarageDoorClosedCommand (GarageDoor *);
	void execute () override;
};

#endif
