## [JSONSchma.net](https://jsonschema.net/home)
  - Online tool to generate schema. We need to provide JSON Doc it generates schema for us.
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
