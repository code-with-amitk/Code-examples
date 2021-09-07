**Xalan**
- **Build**
  - [Linux](#lin)
  - [Windows](#win)
- **Source**
  - [Merge 2 xml files](#mer)

## Xalan
Xalan compatiblity with xerces, Check [Release History](https://apache.github.io/xalan-c/releases.html)

### Build
<a name=lin></a>
**1. Linux**
```c
# cmake .;  make;  sudo make install
```

<a name=win></a>
**2. Windows** [Build steps apache.github.io](https://apache.github.io/xalan-c/build.html)
- [CMAKE_PREFIX_PATH](https://cmake.org/cmake/help/latest/variable/CMAKE_PREFIX_PATH.html)
```c
///////////////////Method-1 (Not Working)//////////////////////
//Get latest xalan from github    //Release pages https://github.com/apache/xalan-c
- Extract xalan in c:
cmd> c:\xalan_c; mkdir build
cmd> cd build
cmd> cmake -G "Visual Studio 16 2019" -DCMAKE_PREFIX_PATH=C:\xerces-c\libs\ -DCMAKE_INSTALL_PREFIX=c:\xalan_c\libs c:\xalan_c(\path\to\Xalan-c\source)
cmd> cmake --build . --config Debug
Issue-1: error MSB8066: Custom build for "C:\xalan-c\build\CMakeFiles\54721b435eedbbf1c365bb7e2edfcd61\inmemory-dependencies.rule" exited with code -1073741515
Sol: https://github.com/apache/xalan-c/pull/37
cmd> ctest -V -C Debug -j 4
cmd> cmake --build . --config Debug --target install

//////////////////Method-2 (Working)///////////////////////////
cmd> git clone https://github.com/Microsoft/vcpkg.git         //in C:      //https://vcpkg.io/en/getting-started.html
cmd> bootstrap-vcpkg.bat
cmd> vcpkg install xalan-c:x64-windows             //Install all dependencies, compiles and xalan libs in C:\vcpkg\packages
```

### Code
<a name=mer></a>
#### Merge 2 XML files
```c
$ cat test.cpp
#include <xalanc/Include/PlatformDefinitions.hpp>
#include <xalanc/XalanTransformer/XalanTransformer.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>
#include <string.h>

// The next 2 include files are for parsing XML documents as nodeset parameters.
#include <xalanc/XalanTransformer/XalanParsedSource.hpp>
#include <xalanc/XSLT/XSLTInputSource.hpp>

// DATA STORAGE FOR TOP-LEVEL PARAMETERS
struct {
    char *  parmType;   // -s key string, -n key number, -d key document
    char *  parmName;   // the key or parameter name
    char *  parmValue;  // the represented string value
} Parameter[15];

// The Parsed Document Nodesets
using xalanc::XalanParsedSource;
const XalanParsedSource * NodesetParam[15] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

int Usage() {   //Usage help function
    using std::cerr;
    using std::endl;
    cerr << "Usage: UseStylesheetParam xmlFile xslFile outFile [parameters]" <<endl
         << "   Parameters are:" <<endl
         << "   -s name \"'String Value'\"" <<endl
         << "   -n name NumberValue" <<endl
         << "   -d name \"Document Nodeset File\"" <<endl;
    return 1;
}

int main(int argc, char* argv[]) {
    using std::cerr;
    using std::endl;

    int theResult = 0;
    int i, j;
    int paramCount = 0;

    if (argc < 4)
        return Usage();

    // Collect the top-level parameter arguments
    for (i=4, j=0; i < argc;) {
        if (!strcmp(argv[i],"-s") || !strcmp(argv[i],"-n") || !strcmp(argv[i],"-d")) {
            Parameter[j].parmType  = argv[i++];
            Parameter[j].parmName  = argv[i++];
            Parameter[j].parmValue = argv[i++];
            paramCount = ++j;
        }
        else  return Usage();
    }

    {
        using xercesc::XMLPlatformUtils;
        using xercesc::XMLException;

        using xalanc::XalanTransformer;
        using xalanc::XSLTInputSource;

        // Call the static initializer for Xerces.
        try
        {
             XMLPlatformUtils::Initialize();
        }
        catch (const XMLException& toCatch) {
             cerr << "Error during Xerces initialization.  Error code was "
                  << toCatch.getCode()
                  << "."
                  << endl;
             theResult = -1;
        }

        if (theResult == 0) {

            XalanTransformer::initialize();

            {
                using xalanc::XalanDOMString;

                // Create a XalanTransformer.
                XalanTransformer    theXalanTransformer;

                // Prepare and set the top-level parameters

                for (j = 0; j < paramCount; j++)
                {
                    // The String Top-Level Parameters
                    if (!strcmp(Parameter[j].parmType, "-s"))
                    {
                        theXalanTransformer.setStylesheetParam(
                            Parameter[j].parmName,
                            Parameter[j].parmValue);
                    }

                    // The DOUBLE Number Top-Level Parameters
                    if (!strcmp(Parameter[j].parmType, "-n"))
                    {
                        theXalanTransformer.setStylesheetParam(
                            Parameter[j].parmName,
                            strtod(Parameter[j].parmValue, NULL));
                    }
                    // The Parsed XML Document (nodeset) Top-Level Parameters
                    if (!strcmp(Parameter[j].parmType, "-d"))
                    {
//                      NodesetParam[j] = NULL;
                        if (theXalanTransformer.parseSource(
                                    XSLTInputSource(Parameter[j].parmValue,
                                        theXalanTransformer.getMemoryManager()),
                                    NodesetParam[j]) == 0)
                        {
                            theXalanTransformer.setStylesheetParam(
                                Parameter[j].parmName,
                                NodesetParam[j]->getDocument());
                        }
                        else
                        {
                            cerr << "WARNING: XML parsing error in "
                                 << Parameter[j].parmName << " file: "
                                 << Parameter[j].parmValue <<endl
                                 << theXalanTransformer.getLastError() <<endl <<endl;
                        }
                    }
                }
                theResult = theXalanTransformer.transform(argv[1], argv[2], argv[3]);
                if(theResult != 0)
                {
                    cerr << "UseStylesheetParam Error: \n" << theXalanTransformer.getLastError()
                         << endl
                         << endl;
                }

            // Clear the top-level parameters - Note: They are sticky across transformations.

                theXalanTransformer.clearStylesheetParams();

            // Destroy the parsed XML documents used as nodeset parameters.

                for (j=0; j < paramCount; j++)
                {
                    if (!strcmp(Parameter[j].parmType, "-d") && NodesetParam[j])
                        theXalanTransformer.destroyParsedSource(NodesetParam[j]);
                }
            }
            XalanTransformer::terminate();
        }
        XMLPlatformUtils::Terminate();
        XalanTransformer::ICUCleanUp();   //Clean up ICU if its integrated
    }

    return theResult;
}

$ cat a.xml
<jamsExport>
  <JKSClients>
    <JKS address="127.0.0.1" description="" id="JKS1"/>
  </JKSClients>
</jamsExport>

$ cat b.xml
<jamsExport>
  <JKSClients>
    <JKS address="127.0.0.2" description="" id="JKS2"/>
  </JKSClients>
</jamsExport>

$ cat ab.xslt
<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:param name="parmA"/>
<xsl:template match="jamsExport">
 <xsl:copy-of select="."/>
 <xsl:copy-of select="$parmA"/>
</xsl:template>
</xsl:stylesheet>

$ g++ UseStylesheetParam.cpp -I/usr/local/include -I/usr/include/ -L/usr/local/lib/ -lxerces-c-3.2 -lxalan-c -g
$ ./a.out a.xml ab.xslt ab.out -d parmA "b.xml"

$ cat ab.out
<?xml version="1.0" encoding="UTF-8"?><jamsExport>
  <JKSClients>
    <JKS address="127.0.0.1" description="" id="JKS1"/>
  </JKSClients>
</jamsExport><jamsExport>
  <JKSClients>
    <JKS address="127.0.0.2" description="" id="JKS2"/>
  </JKSClients>
</jamsExport>
```
