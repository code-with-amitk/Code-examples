**YAML (YAML Ain't Markup Language)**
- About
  - [yaml vs xml vs json](#vs)
- **Data Types, Data Structures**
  - [Data types](#dt)
  - [Data Structures: (Key, Value pairs), Objects, (List or Arrays), Multiline string, Place holders {{ }}](#ds)
- Different yaml files
  - [configmap.yaml]
  - [deployment.yaml]
- [objects types](#ot)

### [YAML](https://yaml.org/spec/)
- YAML(rhymes with “camel”) is a human-friendly, cross language, Unicode based **data serialization language**.
  - Serialization language means Applications written in Different languages(Rust,c++,python) can send data to each other using SL. Other SA are XML, json.
- **YAML is designed for these use cases**
  - configuration files, log files, interprocess messaging, cross-language data sharing, object persistence and debugging of complex data structures.
#### Features
  - YAML is case sensitive
  - tabs not allowed. spaces are allowed instead.
#### Design Goals
- Easily readable by humans.
- Portable between programming languages.
- Match the native data structures of dynamic languages.
- One-pass processing.
- Easy to implement and use.


<a name=vs></a>
#### yaml vs xml vs json
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

<a name=dt></a>
### Data Types
#### 1. Scalars (numbers, strings)
Basic values like numbers or strings are called scalars
#### 2. Complex Types (arrays, objects)
All others are complex types 

<a name=ds></a>
### Data Structures
[Online yaml validator](http://www.yamllint.com/)

#### Key, Value pairs
```yml
name: Amit
age: 35
version: 2.0
```

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

#### Multiline string, Block Pipe |
- All lines are interpreted as seperate lines.
- The pipe is used when you want newlines to be kept as newlines.
```yml
--- 
multiline: |
    this is 1st line
    this is 2nd line
    this is 3rd line
```

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

<a name=ot></a>
### [Object types](/System-Design/Concepts/Containers/Kubernets/README.md#ko)
```
test.yaml
  kind: service
  kind: Role
  kind: clusterRole
```
