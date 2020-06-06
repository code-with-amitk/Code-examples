#include "config.hpp"
#include "RemoteControl.hpp"
#include "Light.hpp"
#include "LightOnCommand.hpp"
#include "LightOffCommand.hpp"
#include "GarageDoor.hpp"
#include "GarageDoorOpenCommand.hpp"
#include "GarageDoorClosedCommand.hpp"

int main(){
        Light *light = new Light();
        LightOnCommand *lonc = new LightOnCommand(light);
        LightOffCommand *lofc = new LightOffCommand(light);

        GarageDoor *gd = new GarageDoor();
        GarageDoorOpenCommand *gdo = new GarageDoorOpenCommand(gd);
        GarageDoorClosedCommand *gdc = new GarageDoorClosedCommand(gd);

        RemoteControl rc;
        rc.setCommand (0, lonc, lofc);
        rc.setCommand (1, gdo, gdc);

        rc.onButtonWasPushed(0);
        rc.offButtonWasPushed(0);
        rc.onButtonWasPushed(1);
        rc.offButtonWasPushed(1);
}

/*
# make
c++ -Wall -Wextra -Werror -Iinclude/ -c src/LightOffCommand.cpp -o build/objects/src/LightOffCommand.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/LightOnCommand.cpp -o build/objects/src/LightOnCommand.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/RemoteControl.cpp -o build/objects/src/RemoteControl.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/Light.cpp -o build/objects/src/Light.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/GarageDoorClosedCommand.cpp -o build/objects/src/GarageDoorClosedCommand.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/GarageDoorOpenCommand.cpp -o build/objects/src/GarageDoorOpenCommand.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/main.cpp -o build/objects/src/main.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -Iinclude/ -c src/Garage.cpp -o build/objects/src/Garage.o -L/usr/lib -lstdc++ -lm
c++ -Wall -Wextra -Werror -o ./build/apps/command-dp build/objects/src/LightOffCommand.o build/objects/src/LightOnCommand.o build/objects/src/RemoteControl.o build/objects/src/Light.o build/objects/src/GarageDoorClosedCommand.o build/objects/src/GarageDoorOpenCommand.o build/objects/src/main.o build/objects/src/Garage.o -L/usr/lib -lstdc++ -lm

# ./build/apps/command-dp 
Light on
Light off
GarageDoor opened
GarageDoor closed
*/
