### Generating Server Key and Certificate:
```
$ openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout server.key -out server.crt
```
### Generating Client CSR:
```
$  openssl req -new -nodes -days 365 -newkey rsa:1024 -keyout client.key -out client.csr
```
### Signing Client CSR from server and getting client certificate:
```
$ openssl x509 -req -in client.csr -CA server.crt -CAkey server.key -CAcreateserial -out client.crt
```
### COMPILE-Server
```
$ g++ -v -Wall -o SSL-SERVER  ssl-server.cpp -L/usr/local/lib64/ -lssl -lcrypto
```
### COMPILE-Client
```
$ g++ -v -Wall ssl-client.cpp -L/usr/local/lib64/ -lssl -lcrypto -o SSL-CLIENT
```
### Running Server
```
$ sudo ./SSL-SERVER 9100 ./server.crt
```
### Running Client
```
$ ./SSL-CLIENT localhost 9100 ./server.crt ./client.crt ./client.key
```
