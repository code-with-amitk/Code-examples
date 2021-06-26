- [1. What is JSON Schema](#what)
  - [1.1 Example of JSON Schema](#example)
- [2. JSON Doc Validation Types](#val)
  - [2.1 Syntactic Validation](#syntactic)
  - [2.2 Semantic Validation](#semantic)


<a name=what></a>
## 1. JSON Schema
- This tells about JSON document's content, structure, format. 
- A JSON Schema validates a JSON document.
- *Why JSON Schema for security*
  - _a._ Web Services should validate their payloads by using a Schema.
  - _b._ Where producer and consumer are on far apart, it important to validate using schema else it will be wastage of time for consumer. 

<a name=example></a>
### 1.1 Example of JSON Schema
- *1.* Schema specifies that a document can have three fields (email, firstName, lastName) each one is a string.
```json
$ cat basic-schema.json
{
 "$schema": "http://json-schema.org/draft-04/schema#",
 "type": "object",
 "properties": {
    "email": {
      "type": "string"
    },
    "firstName": {
      "type": "string"
    },
    "lastName": {
      "type": "string"
    }
  }//properties    
}  

$ cat document_complying_to_schema.json
{
  "email": "larsonrichard@ecratic.com",
  "firstName": "Larson",
  "lastName": "Richard"
}
```

<a name=val></a>
## 2. Validation Types

<a name=syntactic></a>
### 2.1 Syntactic Validation
- When we validate a JSON document without Schema, we're validating only the syntax of the document. Eg: matching braces, double quotes for keys etc.
- *Tools for doing so:* JSONLint, JSON parsers for each platform.
```json
test.json
{
  "email": "amit@google.com",
  "age": 39
}

cmd> npm install -g jsonlint
cmd> jsonlint test.json

//We can also do semantic Validation using jsonlint
```

<a name=semantic></a>
### 2.2 Semantic Validation
- Validating the meaning of the data, not just the syntax. Eg: Validating format of a phone number, date/time, postal code, email address, or a credit card number etc.


