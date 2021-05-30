## Generating JSON Schema
- **Two steps**
  - _a. Generate using any_
    - _1. [Using URL JSONSchma.net](JSONSchma)_
  - _b. Validate schema_
    - _1. http://jsonvalidate.com/_
    - _2. Using JSONlint_
```json
$ test.json
{
    "email": "amitk@google.com",
    "age": 39
}

//Generate JSON Schema using JSONSchema.net and store in test_schema.net

cmd> jsonlint -V test.json test_schema.json
```
- **[JSON Schema Keywords](JSON_Schema_Keywords)**
