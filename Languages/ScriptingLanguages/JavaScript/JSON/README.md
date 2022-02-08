- [What, Why JSON](#what)
- [Datatypes](#datatypes)
- [JSON Schema](#schema)
- [JSON Transform, Converting JSON to HTML,XML,JSON](#transform)
- [RESTFul JSON Server](#restful)
- [Building Web Application using Yeoman](#webapp)
- [Rust Json Object]()

<a name=what></a>
## JSON / JavaScript Object Notation
- JSON is text-based, language-independent **data interchange format**. JSON format is syntactically identical to the code for creating JavaScript objects.
- **JSON Comments:** There are no comments in a JSON document. Reasons:
  - JSON parsers had difficulties supporting comments.
  - People were abusing comments. For example, Comments were being used for parsing directives, which would have destroyed interoperability.
  - Removing comments simplified and enabled cross-platform JSON support.
#### Why JSON
- *1.* [RESTful Web Applications](/Networking/OSI-Layers/Layer5/WebServer_to_WebClient_Connection_Methods/REST) can communicate using JSON.
- *2.* The simplicity of JSON’s basic data structures
- *3.* The increasing popularity of JavaScript
- *4.* Thousands of RESTful APIs leverage JSON. Eg: LinkedIn, Twitter, Facebook, Salesforce, GitHub, DropBox, Tumblr, Amazon Web Services (AWS).

<a name=datatypes></a>
## JSON datatypes
### Core Data Types
- **1. Name (or Key)/value pair:** Consists of a key and a value.
  - Valid value types: Object, array, string, number, boolean, null
```json
nameValue.json {
 "name": "amit",                  //Value type: String
 "age": 36,                       //Value type: int
}
```
- **2. Object:** An unordered collection of name/value pairs.
```json
Object.json {
 "address" : {
   "Flat no": "B602"
   "city"   : "Mountain View",
   "country": "USA"
  }
}
```
- **3. Array:** Contains nested objects. Array is enclosed using `[ ]`.
```json
Array.json {
  "People": [            //Array         
    {
      "name": "Amit",
      "age" : 36,
    },
    {
      "name": "Ram",
      "age" : 10,
    }
  ]
}
```

<a name=schema></a>
## [JSON Schema](JSON_Schema)

<a name=transform></a>
## JSON Transform, Converting JSON to HTML,XML,JSON
- We have couple of 3rd party libraries for doing the conversion.
**JSON to HTML Transform**
  - [Mustache](http://mustache.github.io/)
  - [Handlebars](https://handlebarsjs.com/): Extension of Mustache
**JSON to JSON Transform**
  - JSON Patch
  - JSON-T
  - [Mustache](http://mustache.github.io/)
  - [Handlebars](https://handlebarsjs.com/): Extension of Mustache
  - Jolt: Only for java env
**JSON to XML Transform**
  - Badgerfish
  - Parker

<a name=schema></a>
## RESTFul JSON Server
- [What is REST](/Networking/OSI-Layers/Layer5/WebServer_WebClient_WebService/WebClient_Connecting_WebServer). 
- **Steps:**
  - _a. Install & Start JSON Server_
    - Install Node.js on Windows**
```c
  a. Install nvm-setup.zip from https://github.com/coreybutler/nvm-windows/releases. 
      It sets up NVM_HOME, NVM_SYMLINK in env varaible.
  b. Open Windows cmd prompt and install latest Node.js
    cmd> nvm install v16.1.0
       > nvm use 16.1.0
```
- *b. Install & start json-server.* Download [speakers.json](https://github.com/tmarrs/json-at-work-examples/blob/master/chapter-1/speakers.json)
```c
  cmd> npm install -g json-server
  >json-server -p 5000 ./speakers.json
```
- _c. Access JSON from Clients_
```c
From Web Browser
  - `http://localhost:5000/speakers`. This will issue GET request to json-server.
  - `http://localhost:5000/speakers/0`. Will give 1st speaker
OR From Postman: 
  Provides the ability to fully test a RESTful API.
```

<a name=webapp></a>
## [Building Web Application using Yeoman](Web_Application)

  
