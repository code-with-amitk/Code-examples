**XML**
- [Advantage](#adv)
- **Terms**
  - [DOM](#dom)
  - [DTD](#dtd)
  - [XML Namespace](#name)
  - [XPath](#xpath)
  - [XSLT](#xslt)
  - [XQuery](#xq)
- [XML Parsers](#par)

<a name=adv></a>
## Advantages of XML
- **Interoperatability:** 2 applications written in different languages can communicate easily using XML.
- **Meta-data** data about data is represented clearly wrt plain text.

## Terms
<a name=dom></a>
#### [DOM(Document Object Model)](https://www.w3.org/TR/DOM-Level-3-Core/introduction.html)
- DOM is framework of defininig XML/html document using trees/forests. Xerces is based on DOM. In DOM each element is called object(having functions and identity).
- World is moving away from DOM(and using other technologies to parse xml) since DOM takes huge memory. To parse 1MB XML it takes around 5MB RAM.
```xhtml
<table>
  <tbody> 
    <tr> 
      <td>Shady Grove</td>
      <td>Aeolian</td> 
    </tr> 
    <tr>
      <td>Over the River, Charlie</td>        
      <td>Dorian</td> 
    </tr> 
  </tbody>
</table>
```

<img src=dom.JPG width=400/>

```xml
<?xml version="1.0" encoding="UTF-8"?>        //XML Version
<note>                                        //Root Element
  <to>Tove</to>                               //Child Elements: to, from, heading, body
  <from>Jani</from>
  <heading>Reminder</heading>
  <body>Don't forget me this weekend!</body>
</note>                                        //Root Element End. Closing Tag is Must
```

<a name=dtd></a>
#### DTD / Document Type Definition
Both DTD & XML Schemas describe strucuture of XML document and what data is allowed.
- _XML Validation:_ DTD and schema can be used to validate XML document that doc recived is as per prescribed format or not.
- _DTD vs XML Schemas:_ DTD is older standard wrt XML schemas. XML schemas are easy an offer more functionality. Most tools use XML schemas now.

<a name=name></a>
#### Namespace
Name conflicts in XML is used to avoid name conflict. It uses name prefix.
```xml
<h:table>
  <h:tr>
    <h:td>Apples</h:td>
    <h:td>Bananas</h:td>
  </h:tr>
</h:table>

<f:table>
  <f:name>African Coffee Table</f:name>
  <f:width>80</f:width>
  <f:length>120</f:length>
</f:table>
```

<a name=xpath></a>
#### XML XPath
Complete path of element in XML document. XPath of 1st book=`/bookstore/book[0]`
```xml
<?xml version="1.0" encoding="UTF-8"?>
<bookstore>
<book category="cooking">
  <title lang="en">Everyday Italian</title>
  <author>Howdy</author>
  <year>2005</year>
  <price>30.00</price>
</book>
</bookstore>
```

<a name=xslt></a>
#### XSLT (eXtensible Stylesheet Language Transformations)
XSLT is [sylesheet language](/Languages/StyleSheetLanguage) for XML. XSLT is used for transforming XML doc to HTML. Example

**XML doc**
```xml
<?xml version="1.0" encoding="UTF-8"?>
<breakfast_menu>
  <food>
    <name>Pasta</name>
    <price>$5.95</price>
    <calories>650</calories>
  </food>
</breakfast_menu>
```
**XSLT stylesheet doc**
```xslt
<?xml version="1.0" encoding="UTF-8"?>
  <html xsl:version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <body style="font-family:Arial;font-size:12pt;background-color:#EEEEEE">
      <xsl:for-each select="breakfast_menu/food">
        <div style="background-color:teal;color:white;padding:4px">
        <span style="font-weight:bold"><xsl:value-of select="name"/> - </span>
      <xsl:value-of select="price"/>
    <div style="margin-left:20px;margin-bottom:1em;font-size:10pt">
      <p>
        <xsl:value-of select="description"/>
        <span style="font-style:italic"> (<xsl:value-of select="calories"/> calories per serving)</span>
      </p>
    </div>
  </xsl:for-each>
  </body>
</html>
```

<a name=xq></a>
#### XQuery
Querying XML document data using query statements. Xquery us similar to SQL in DB.
```xml
for $x in doc("books.xml")/bookstore/book
where $x/price>30
order by $x/title
return $x/title
```

<a name=par></a>
### XML Parsers
```c
                    Name            |   About
------------------------------------|-----------------------
MSXML(Microsoft Core XML services)  | Microsoft's XML tool(including parser), exposed as COM object, accessed using C++ also.
System.Xml.XmlDocument              | In Microsoft .Net library. Has all standard DOM features.
Saxon                               | Micheal Kay's product for XML parsing, quering, transforming. In java & .net
Xerces                              | In java and c++ by Apache open source
```
