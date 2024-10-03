**Markup Languages**
- [SAML(Security Assertion Markup Language)](https://code-with-amitk.github.io/Languages/Markup/SAML/index.html)
- [Terms: Elements, Attributes](#ter)
- [HTML vs XML](#vs)

## Markup Language
Language that uses tags to define elements within a document. It is human-readable, meaning markup files contain english words, rather than typical programming syntax.
- _Examples?_ While several markup languages exist, the two most popular are HTML and XML.

<a name=ter></a>
### Terms
```xml
<users>
  <user> firstname="amit" lastname="kumar" </user>
  <user> firstname="ram" lastname="singh" </user>
</users>
```
- **Elements:** users
- **Attributes:** firstname, lastname

<a name=vs></a>
### HTML vs XML
```c
                               HTML     |   XML(Extensible Markup Language)
-----------|----------------------------|-------------------------
What       | Used for creating webpages | Use for storing structured data
Tags       | Uses predefined tags       | Uses custom tags to define elements
             Examples:`<head>,<body>  
Data       | More user centric ie more  | Both Application and user centric
             focus on display data to    XML data can be processed easily by applcations
             user                        also can be displayed in browser
Use cases  | Showing data to users      | 1. Document storage. storing data in xml files. Showing data to user.
                                          2. Image representation. svg image is xml based.
```
