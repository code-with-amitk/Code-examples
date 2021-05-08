## Core Data Types
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
