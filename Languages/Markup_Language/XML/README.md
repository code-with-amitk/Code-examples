- [DOM](#dom)

<a name=dom></a>
## [DOM(Document Object Model)](https://www.w3.org/TR/DOM-Level-3-Core/introduction.html)
DOM defines 
  - Logical structure(tree or forest) of DOM documents(XML or html & the way a document is accessed and manipulated. 
  - Fraework for accessing these docs. DOM can be used with any programming language.
- With DOM we can build,navigate,add,modify,delete elements in documents.
- DOM documents does not provide elements rather each element is called object(having functions and identity).
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

<img src=DOM.JPG width=400/>

```xml
<?xml version="1.0" encoding="UTF-8"?>        //XML Version
<note>                                        //Root Element
  <to>Tove</to>                               //Child Elements: to, from, heading, body
  <from>Jani</from>
  <heading>Reminder</heading>
  <body>Don't forget me this weekend!</body>
</note>                                        //Root Element End. Closing Tag is Must
```
