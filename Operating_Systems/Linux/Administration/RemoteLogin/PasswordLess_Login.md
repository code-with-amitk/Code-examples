## Using ssh public Pvt Key pairs

### 1. Linux to Linux
- **A. {Client} Generate ssh public pvt key pairs**
```c
# ssh-keygen -t rsa     //-t:type of key
 > pub key: /home/amit/.ssh/id_rsa.pub
 > pvt key: /home/amit/.ssh/id_rsa
```

- **B. {Server} Copy Public key to server and check permissions**
```c
$ vim ~/.ssh/authorized_keys
  <<paste /home/amit/.ssh/id_rsa.pub>>
$ chmod 700 ~/.ssh
$ chmod 640 ~/.ssh/authorized_keys
```

- **C. {Client} ssh without password**
```c
$ ssh user@server
```
