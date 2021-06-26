- [1. What is JSON Schema](#what)
  - [1.1 Example of JSON Schema](#example)
- [2. JSON Doc Validation Types](#val)
  - [2.1 Syntactic Validation](#syntactic)
  - [2.2 Semantic Validation](#semantic)
- [3. Generating & Validating JSON Schema](#generate)
- [4. JSON Schema Keywords](#keywords)


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

<a name=generate></a>
## 3. Generating & Validating JSON Schema
- _1._ Generate schema using JSONSchma.net. JSONSchema.net is a online tool to generate schema. We need to provide JSON Doc it generates schema for us.
```json
////Submit JSON doc in URL/////
{
    "email": "amitk@google.com",
    "age": 39
}

//////Get Schema Generated//////
{
    "$schema": "http://json-schema.org/draft-07/schema",
    "$id": "http://example.com/example.json",
    "type": "object",
    "title": "The root schema",
    "description": "The root schema comprises the entire JSON document.",
    "default": {},
    "examples": [
        {
            "email": "amitk@google.com",
            "age": 39
        }
    ],
    "required": [
        "email",
        "age"
    ],
    "properties": {
        "email": {
            "$id": "#/properties/email",
            "type": "string",
            "title": "The email schema",
            "description": "An explanation about the purpose of this instance.",
            "default": "",
            "examples": [
                "amitk@google.com"
            ]
        },
        "age": {
            "$id": "#/properties/age",
            "type": "integer",
            "title": "The age schema",
            "description": "An explanation about the purpose of this instance.",
            "default": 0,
            "examples": [
                39
            ]
        }
    },
    "additionalProperties": true
}
```
- _2._ Validate schema using http://jsonvalidate.com
```json
$ test.json
{
    "email": "amitk@google.com",
    "age": 39
}

//Generate JSON Schema using JSONSchema.net and store in test_schema.net

cmd> jsonlint -V test.json test_schema.json
```

<a name=keywords></a>
## 4. JSON Schema Keywords
- **properties:** Specifies the fields for an object. It contains type information.
- **$schema:** Tells JSON Schema (spec) version.
```json
“$schema": "http://json-schema.org/draft-04/schema#"            //Schema conforms to version 0.4
$schema": "http://json-schema.org/schema#"                      //Using latest version of the specification
```
- **type:** Specifies the data type for a field. For example: string, number, boolean
