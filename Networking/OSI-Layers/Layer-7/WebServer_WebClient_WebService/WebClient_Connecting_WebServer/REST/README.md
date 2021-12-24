**REST / (Representation State Transfer) APIs**
- [What REST](#what)
- [Restful Methods/APIs/Verbs](#meth)
- [Why Restful](#why)

## REST / (Representation State Transfer) APIs
<a name=what></a>
### What REST
- **Restful Web Server/Application?** Web application that implements Restful APIs POST,GET,PUT,DELETE(or HTTP methods). Eg: Twitter, facebook are implemented using restful APIs.
- When web-client calls Restful APIs then Web-Server will transfer data representing state of the requested resource. Representation can be in [JSON](/Languages/ScriptingLanguages/JavaScript) or HTML or [XML](/Languages/Markup_Language) format.
- REST are standards which computers/nodes must comply with in order to communicate with each other.
```c
   Client	                        	                Web Service
 http://<ip-address>/get/username
                                        Implement APIs GET(){..} POST(){..} DELETE(){..} PUT(){..}
                     <---data----
```
<a name=meth></a>
### Restful Methods/APIs/Verbs
Client calls these methods and response returned over HTTP.
```c
  - POST: This will create a new record in web service
  - GET: Get list of all records in web service
  - PUT: Update a record in web service
  - DELETE: delete 1 record in web service
```

- [What is WebService](../WebServer_vs_WebService)
- [6 Constraints for Application to be Restful](Restful_Constraints)
- **[Code Implementation using Python flask-restful](/Languages/ScriptingLanguages/Python/web-frameworks/flask-restful)**
- [REST vs SOAP](REST_vs_SOAP)
- [REST_vs_HTTP](REST_vs_HTTP)

<a name=why></a>
### Why Restful
- *1. Rest makes Web Service OS Independent:* Web applications can reside on different operating systems, some could be on Windows, and others could be on Linux.
- *2. Rest makes Web Service language independent:* Web services can be implemented in any language(C++,RUST etc)
- *3. On Cloud:* RESTful applications are moved can reside on cloud. Azure and Amazon provide a lot of API's based on the Restful architecture. 
