**XML**
```xml
<?xml version="1.0" encoding="UTF-8" standalone="no"?>
<test>
    <test1>hello world</test1>
</test>
```
**Code**
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
