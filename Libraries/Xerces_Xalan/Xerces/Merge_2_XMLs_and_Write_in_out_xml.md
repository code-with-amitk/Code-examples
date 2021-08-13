- This code is taken from **xerces-c-3.2.3\samples\src\DOMPrint.**
- DOMPrint has Exceptions defined, this is simplified code.

**XMLs**
```xml
//file1.xml
<?xml version=1.0 encoding=UTF-8.0?>
<ele1>
  <ele2>hello world file1</ele2>
</ele1>

//file2.xml
<?xml version=1.0 encoding=UTF-8.0?>
<ele1>
  <ele2>hello world file2</ele2>
</ele1>

//out.xml
<?xml version=1.0 encoding=UTF-8.0?>
<ele1>
  <ele2>hello world file1</ele2>
  <ele2>hello world file2</ele2>
</ele1>
```

**Code**
```cpp
/*
  1. Initialize() neccessary call
  2. Created Object of XercesDOMParser class to parse input XML doc
  3. Parse XML
  4. Store XML file into DOM document.
  5. Get all DOM nodes under the tagname.
  6. Get 1st elememt in DOM Doc implementation
  7. Return first registered DOM doc implementation
  8. Create DOMLSSerializer to send DOM Tree to XML document
  9. Create a new "empty" LSOutput (load and save output)
  10. Create object of LocalFileFormatTarget. This class is used to RW to files
  11. Sets the byte stream for this input source
  12. Write out the specified node
*/

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/OutOfMemoryException.hpp>
#include <string.h>
#include <stdlib.h>

using namespace xercesc;
using namespace std;
static const XMLCh  element_person[] = {
	//chLatin_p, chLatin_e, chLatin_r, chLatin_s, chLatin_o, chLatin_n, chNull
  0x70,0x65,0x72,0x73,0x6F,0x6E,0x00
};
static const XMLCh  element_link[] = {
	//chLatin_l, chLatin_i, chLatin_n, chLatin_k, chNull
  0x6C,0x69,0x6E,0x68,0x00
};

int main() {
  XMLPlatformUtils::Initialize();                           //1
  
  /* Read Input-file 1 */
  XercesDOMParser *parser = new XercesDOMParser;            //2
  parser->parse("d:/amit/file1.xml");                       //3
  DOMDocument *doc = parser->getDocument();                 //4
  DOMNodeList* pDOMNodeList1 = doc->getElementByTagName (XMLString::transcode("ele1"));   //5
  DOMNode* docRoot = pDOMNodeList1->item(0);                //6

  /* Read Input-file 2 */
  XercesDOMParser *parser2 = new XercesDOMParser;
  parser2->parse("d:/amit/file2.xml");           
  DOMDocument *doc2 = parser2->getDocument();     
  DOMNodeList* pDOMNodeList2 = doc2->getElementByTagName (XMLString::transcode("ele2"));
  DOMNode* doc2Root = pDOMNodeList2->item(0);
  
  /* 3. Append file-2(ele2) to file-1 */
  docRoot->appendChild (doc->importNode (doc2Root, true));
  
  /* 4. Set DOMLSSerializer, DOMLSOutput for sending data to File */
  XMLCh tempStr[3] = {chLatin_L, chLatin_S, chNull};
  DOMImplementation *impl          = DOMImplementationRegistry::getDOMImplementation(tempStr);  //7
  //DOMLSSerializer provides an API for serializing(writing) a DOM document out in an XML document
  DOMLSSerializer* pDOMLSSerializer = ((DOMImplementationLS*)impl)->createLSSerializer();       //8
  DOMLSOutput* pOutDestination      = ((DOMImplementationLS*)impl)->createLSOutput();  
  
  /*5 Open output file, Writing data to it */
  XMLFormatTarget* pOutFormatter = new LocalFileFormatTarget("D:/amit/out.xml");              //10
  pOutDestination->setByteStream (pOutFormatter);                                             //11
  pDOMLSSerializer->write (doc, pOutDestination);                                             //12
  
  /* 6. Release DOMLSSerializer, DOMLSOutput, XMLFormatTarget and input file parser */
  pOutDestination->release ();
  pDOMLSSerializer->release();
  delete pOutFormatter;
  delete parser;
  
  XMLPlatformUtils::Terminate();
}
```
