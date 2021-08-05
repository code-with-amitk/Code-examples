**[Apache Xerces](https://xerces.apache.org/xerces-c/index.html)**
- What is Xerces
- Download,Install
  - [Linux](#linux)
  - [Windows](#win)
- **Examples**
  - [Parse element from XML](#parse)

## Xerces
XML parsing/manipulating/validating library written in C++ using the DOM, SAX, and SAX2 APIs.

## Download, Install
<a name=linux></a>
**Linux**
```c
# git clone https://github.com/apache/xerces-c.git
# ./configure; make; make install
```
<a name=win></a>
**Windows**
```c
Install cmake
$ git clone https://github.com/apache/xerces-c.git
$ cd xerces; mkdir build; cd build
$ cmake ..
$ cmake --build . --config Debug --target install
cd ..
cd ..
```

## Examples
<a name=parse></a>
### Parse element from XML Fie
XML
```xml
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<test>
    <test1>hello world</test1>
</test>
```
Code
```cpp
#include <iostream>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>

using namespace xercesc;
using namespace std;

int main() {

  XMLPlatformUtils::Initialize();
  
  XercesDOMParser *parser = new XercesDOMParser;            //Create the DOM parser
  parser->setValidationScheme(XercesDOMParser::Val_Never);
  parser->parse("sample.xml");
  
  DOMDocument *doc = parser->getDocument();                 //Get the DOM representation
  DOMElement* root = doc->getDocumentElement();             //Get the root element

  DOMXPathResult* result=doc->evaluate(                     //Evaluate the xpath
      XMLString::transcode("/test/test1"),
      root, NULL,
      DOMXPathResult::ORDERED_NODE_SNAPSHOT_TYPE,
      NULL);

  if (result->getNodeValue() == NULL)
    cout << "There is no result for the provided XPath " << endl;
  else
    cout<<TranscodeToStr(result->getNodeValue()->getFirstChild()->getNodeValue(),"ascii").str()<<endl;

  XMLPlatformUtils::Terminate();
  return 0;
}

$ sudo ln -s /usr/local/lib/libxerces-c-3.2.so /usr/lib/
$ g++ -g -Wall -pedantic -L/usr/local/lib/ -I/usr/local/include -DMAIN_TEST test1.cpp -lxerces-c-3.2 -o xpath
$ ./xpath
hello world
```
