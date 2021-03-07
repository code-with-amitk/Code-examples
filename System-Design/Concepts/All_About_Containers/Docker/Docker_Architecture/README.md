## Docker Architecture
- **Docker Daemon / dockerd?** Manages Docker objects(Eg: Images, containers, networks, and volumes). dockerd also communicate with other daemons to manage Docker services.
- **Docker client / docker?** Users interact with docker client.

```
  User 
$ docker run -----> [Docker Client]
                             -----------------> [Docker Daemon/dockerd]
```
