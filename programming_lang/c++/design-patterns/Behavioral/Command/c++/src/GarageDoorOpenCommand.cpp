#include "GarageDoorOpenCommand.hpp"

#include "GarageDoor.hpp"

GarageDoorOpenCommand::GarageDoorOpenCommand (GarageDoor *k)
{
	g = k;
}

void GarageDoorOpenCommand::execute ()
{
	g->open();
}
