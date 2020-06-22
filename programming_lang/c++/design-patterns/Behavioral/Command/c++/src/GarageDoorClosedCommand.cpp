#include "GarageDoorClosedCommand.hpp"

GarageDoorClosedCommand::GarageDoorClosedCommand (GarageDoor *k)
{
	g = k;
}

void GarageDoorClosedCommand::execute ()
{
	g->closed();
}
