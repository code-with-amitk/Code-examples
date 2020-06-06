#ifndef LIGHTOFFCOMMAND_H
#define LIGHTOFFCOMMAND_H

#include"Command.hpp"
#include"Light.hpp"

class LightOffCommand : public Command
{
        Light *l;
public:
        LightOffCommand (Light *);
        void execute() override;
};

#endif
