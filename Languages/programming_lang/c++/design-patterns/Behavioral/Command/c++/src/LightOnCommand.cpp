#include "LightOnCommand.hpp"
#include "Light.hpp"

LightOnCommand::LightOnCommand (Light *a):l(a){}

void LightOnCommand::execute ()
{
	l->on();
}
