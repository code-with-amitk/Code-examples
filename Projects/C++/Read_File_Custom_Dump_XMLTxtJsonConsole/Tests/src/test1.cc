#include "common.h"
#include "tests.h"
#include "Display.h"
#include "Parser.h"

void testBasic()
{
    {
        std::cout << "Test: fakefile" << std::endl;
        Display oDisplay;
        std::string strFile = "./fakefile.txt";
        Parser oParser(strFile);
        char* a = new char[5]();
        char** av = &a;
        int ac = 1;
        //Test:
        //./Driver
        //Expected: should FAIL
        CTEST_ASSERT_THROW(oDisplay.OutputOptions(ac, av) == E_FAIL);
    }
    {
        std::cout << "Test: correctFile" << std::endl;
        Display oDisplay;
        std::string strFile = "./input.txt";
        Parser oParser(strFile);
        char* b = "-d xml";
        char** av = &b;
        int ac = 3;
        //./Driver -d xml
        //Expected: should Pass
        CTEST_ASSERT_THROW(oDisplay.OutputOptions(ac, av) == E_SUCCESS);
    }
    {
        std::cout << "Test: nofile" << std::endl;
        Display oDisplay;
        std::string strFile = "";
        Parser oParser(strFile);
        char* b = "-d xml";
        char** av = &b;
        int ac = 3;
        //./Driver -d xml
        //Expected: should Fail
        CTEST_ASSERT_EQUAL(oParser.ParseFile(), E_FAIL);
    }
    {
        std::cout << std::endl << "Test: file" << std::endl;
        Display oDisplay;
        std::string strFile = "./input.txt";
        Parser oParser(strFile);
        char* b = "-d file";
        char** av = &b;
        int ac = 3;
        //./Driver -d file
        CTEST_ASSERT_EQUAL(oParser.ParseFile(), E_SUCCESS);
        CTEST_ASSERT_EQUAL(oDisplay.OutputOptions(ac, av), E_SUCCESS);
        //CTEST_ASSERT_EQUAL(oDisplay.Dump(oParser), E_SUCCESS);
    }
}

void testAdvanced()
{
  // a more advanced test
    std::cout << "advanced Test" << std::endl;
    int a = 1, b = 1, c = 2;

    //CTEST_ASSERT_THROW(a == b);
    //CTEST_ASSERT_THROW(0);
}

int main(int ac, char** av)
{
    testBasic();
    testAdvanced();
}  
