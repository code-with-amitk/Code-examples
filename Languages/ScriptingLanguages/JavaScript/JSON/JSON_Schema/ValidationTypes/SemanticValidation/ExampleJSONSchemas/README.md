## Example JSON Schemas
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
