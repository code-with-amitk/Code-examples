## Nginx container binds directly to port 80 on the Docker host
- Start ngnix in container with host networking, ngnix listens on port 80 which is same as docker host.
- This is same as nginx process were running directly on the Docker host and not in a container. Other things are isolated from host:
  - Storage, process namespace, and user namespace etc

### Steps
- *1.* Create and start container as [Detached process](/Threads_Processes_IPC/Threads/detachable_thread.md). See [switch meanings](../../../../Docker_Commands
)
```
  # docker run --rm -d --network host --name my_nginx nginx
```
- *2.* Access ngnix by browsing `http://localhost:80/`
- *3.* Look at network stack and see no new one is created
```c
  # ip addr show 
```
- *4.* Check which process is binded to port 80.
```c
  # sudo netstat -tulpn | grep :80
```
- *5.* Stop the container, it will be removed automatically since start with -rm switch
```c
  $ docker container stop my_nginx
```
