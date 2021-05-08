## Core Data Types
- **1. Name (or Key)/value pair:** Consists of a key (a data attribute) and a value.
```json
nameValue.json {
 "conference": "OSCON",
 "speechTitle": "JSON at Work",
 "track": "Web APIs"
}
```
- **2. Object:** An unordered collection of name/value pairs.
```json
simpleJsonObject.json {
 "address" : {
 "line1" : "555 Any Street",
 "city" : "Denver",
 "stateOrProvince" : "CO",
 "zipOrPostalCode" : "80202",
 "country" : "USA"
 }
}
```
- **3. Array:** A collection of ordered values. Array is enclosed using `[ ]`
```json
jsonArray.json {
  "presentations": [            
  {
    "title": "JSON at Work: Overview and Ecosystem",
    "length": "90 minutes",
    "abstract": [ "JSON is more than just a simple replacement for XML when",
    "you make an AJAX call."
    ],
    "track": "Web APIs"
  }
}
```
