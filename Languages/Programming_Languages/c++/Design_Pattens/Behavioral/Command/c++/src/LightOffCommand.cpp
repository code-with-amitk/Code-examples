#include "LightOffCommand.hpp"
#include "Light.hpp"

LightOffCommand::LightOffCommand (Light *a):l(a){}

void LightOffCommand::execute ()
{
	l->off();
}
