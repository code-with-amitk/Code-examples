#ifndef GARAGEDOOROPENCOMMAND_H
#define GARAGEDOOROPENCOMMAND_H

#include "GarageDoor.hpp"
#include "Command.hpp"

class GarageDoorOpenCommand : public Command
{
	GarageDoor *g;
public:	
	GarageDoorOpenCommand (GarageDoor *);
	void execute () override;
};
#endif
