## RESTFul JSON Server
- [What is REST](/Networking/OSI-Layers/Layer5/WebServer_WebClient_WebService/WebClient_Connecting_WebServer)

### Install & Start JSON Server
- *1.* Install Node.js on Windows
```c
  a. Install nvm-setup.zip from https://github.com/coreybutler/nvm-windows/releases. It sets up NVM_HOME, NVM_SYMLINK in env varaible.
  b. Open cmd prompt and install latest Node.js
    cmd> nvm install v16.1.0
       > nvm use 16.1.0
```
- *2.* Install & start json-server
  - Download [speakers.json](https://github.com/tmarrs/json-at-work-examples/blob/master/chapter-1/speakers.json)
```c
  cmd> npm install -g json-server
  >json-server -p 5000 ./speakers.json
```

### Access JSON from Clients
- **1. Web Browser**
  - `http://localhost:5000/speakers`. This will issue GET request to json-server.
- **2. Postman:** Provides the ability to fully test a RESTful API.
