#ifndef LIGHTONCOMMAND_H
#define LIGHTONCOMMAND_H
/* I wasted whole day, #define was named as LightOnCommand
 * renamed to LIGHTONCOMMAND_H problem resolved
*/

#include"Command.hpp"
#include"Light.hpp"

class LightOnCommand : public Command
{
	Light *l;
public:	
	LightOnCommand (Light *);
	void execute() override;
};

#endif
