## REST / (Representation State Transfer) APIs
- **What?** 
  - When web-client calls Restful APIs then Web-Server will transfer data representing state of the requested resource. Representation can be in [JSON](/Languages/ScriptingLanguages/JavaScript) or HTML or [XML](/Languages/Markup_Language) format.
  - REST are standards which computers/nodes must comply with in order to communicate with each other.
  - **Restful Web Application?** Web application that implements Restful APIs POST,GET,PUT,DELETE. Eg: Twitter, facebook are implemented using restful APIs.
```c
   Client	                        	                Web Service
 http://<ip-address>/get/username
                                        Implement APIs GET(){..} POST(){..} DELETE(){..} PUT(){..}
                     <---data----
```
- [What is WebService](../WebServer_vs_WebService)
- [6 Constraints for Application to be Restful](Restful_Constraints)
- [Why Restful](Why_Restful.md)
- [Restful Methods/APIs/Verbs](Methods_API)
- [Code Implementation](/Languages/ScriptingLanguages/Python/web-frameworks/flask-restful)
- [REST vs SOAP](REST_vs_SOAP)
- [REST_vs_HTTP](REST_vs_HTTP)

