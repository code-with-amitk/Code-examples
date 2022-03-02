**YAML (YAML Ain't Markup Language)**
- [yaml vs xml vs json](#vs)
- [design Goals](#d)
- Data Structures
  - [Key, Value pairs](#kv)
  - [Objects](#o)
  - [List or Arrays](#l)
  - [Multiline string](#ml)
  - [Place holders {{ }}](#ph)
- Different yaml files
  - [configmap.yaml]
  - [deployment.yaml]

## [YAML](https://yaml.org/spec/)
- YAML(rhymes with “camel”) is a human-friendly, cross language, Unicode based **data serialization language**.
  - Serialization language means Applications written in Different languages(Rust,c++,python) can send data to each other using SL. Other SA are XML, json.
- **YAML is designed for these use cases**
  - configuration files, log files, interprocess messaging, cross-language data sharing, object persistence and debugging of complex data structures.
- **Features**
  - YAML is case sensitive
  - tabs not allowed. spaces are allowed instead.

<a name=vs></a>
### yaml vs xml vs json
xml,json are defined using special characters. 
  - xml has `<>`
  - json has `{} []`
  - yaml does not have those. data is defined using line seperation, spaces and indentation.
```c
////////yaml////////////
microservices:
  - app: user-authentication
    port: 9090
    version: 1.0
    
///////xml///////////
<microservices>
  <app> user-authentication </app>
  <port> 9090 </port>
  <version> 1.0 </version>
  
//////json//////////
{
  microservices [
    {
      app: "user-authentication"
      port: 9090
      version: "1.0"
    }
  ]
}
```

<a name=d></a>
### Design Goals
- Easily readable by humans.
- Portable between programming languages.
- Match the native data structures of dynamic languages.
- One-pass processing.
- Easy to implement and use.

<a name=ds></a>
### Data Structures
[Online yaml validator](http://www.yamllint.com/)
<a name=kv></a>
#### Key, Value pairs
```yml
name: Amit
age: 35
version: 2.0
```
<a name=o></a>
#### Objects
Just indent kv pairs inside a object. name,age,version are its attributes
```yml
--- 
person1: 
  age: 35
  name: Amit
  version: 2.0
  
person1.age     #Accessing the value
```
<a name=l></a>
#### List or Arrays
```yml
# Format1
---
test: 
  - 1
  - 2
  - 3
  - "4"

# Format2
test: [a,1]
```
<a name=ml></a>
#### Multiline string
All lines are interpreted as seperate lines.
```yml
--- 
multiline: |
    this is 1st line
    this is 2nd line
    this is 3rd line
```
<a name=ph></a>
#### Place holders {{ }}
Instead of providing the values directly, we can provide {{ .Values.service.port }}, which will be replaced parameters in values.yaml.j2.
```yml
# Check in http://www.yamllint.com/
version: 1
kind: service
config:
  port: {{ .Values.jams.port }}
  ip: {{ .Values.jams.ip }}
```
