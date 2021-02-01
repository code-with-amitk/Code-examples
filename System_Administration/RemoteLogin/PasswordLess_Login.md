## Using ssh public Pvt Key pairs

### 1. Linux to Linux
- **SSH-Client Configuration**
```c
//1. Generate ssh public pvt key pairs
# ssh-keygen
  > public key: test.pub
  > pvt key: test.pvt
  
//2. Configure ssh to pick pvt key
# vim ~/.ssh/config
Host ssh_server
IdentityFile  ~/test1.pvt
# service sshd restart
```

- **SSH-Server Configuration**
```c
//3. Copy ssh public key to remote ssh server
server# vim ~/.ssh/authorized_keys
  <<<paste contents of test.pub>>
server# service sshd restart  
```
