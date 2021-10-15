#include "Parser.h"
#include "Display.h"

int main(int ac, char **av) {
    _HResult ret = E_FAIL;

    Display oDisplay;
    if (oDisplay.OutputOptions(ac, av) == E_SUCCESS) {

        //Parse input file
        std::string strFile = "./input.txt";
        Parser oParser(strFile);
        if (oParser.ParseFile() == E_SUCCESS) {

            //Dump output on different mediums:
            //console, txt file, xml file, json etc
            oDisplay.Dump(oParser);
        }
    }
    return ret;
}
