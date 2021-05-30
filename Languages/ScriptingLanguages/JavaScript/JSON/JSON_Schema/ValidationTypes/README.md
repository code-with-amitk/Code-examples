## Validation Types
- **Syntactic Validation**
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
- **[Semantic Validation](Semantic_Validation)**
