**Access Control**
- [setuid](#u)
  - [File suid](#fs)

## Access Control
Access control means authenticate and authorize users to access the information.

<a name=u></a>
### 1. setuid / (u+s)/4XXX / Set user id / Execute Permission
- This is special user's permission. This is execute permission, ie execute bit is set to `s`.
- **(On Files)** File executes as the user that owns/created the file, not the user that ran the file. 
- **(On Dir)** No effect
```c
$ ls -ltr test.txt
- rw- --- ---
$ chmod u+s test.txt
- rwS --- ---         //If file does not have execute permissions Upper case S. else s
```

<a name=fs></a>
### File setuid
- **Example-1: setuid vim**
  - *1.* User=amit created a file `test.txt` and removed group and other permissions `chmod g-rwx o-rwx`
```c
amit@server$ pwd
/home/amit
amit@server$ cat test.txt
hello
amit@server$ ls -ltr
- rw- --- ---     user=amit    group=amit    test.txt
```
  - *2.* User=ram want to read the file. He cannot.
```c
ram@server$ pwd
/home/ram
ram@server$ vim /home/amit/test.txt
  Permissions denied
```
  - *3.* How can all users be granted read permissions if they access file using `vim`? 
    - setuid of vim. This means process `/usr/bin/vim` can be executed by other users using Permissions of Owner=amit.
```c
# chmod u+s /usr/bin/vim
ram@server$ vim /home/amit/test.txt
hello
```
- **Example-2: passwd program**
  - s stands for setuid. Means this process `/usr/bin/passwd` can be executed by other users using Permissions of Owner=root
```c
$ ls -l /usr/bin/passwd
 -rwsr-xr-x.  root root /usr/bin/passwd
``` 

### Directory setuid
- chmod u+s file    OR    chmod 4644 file         //If file does not have execute permissions. Upper case S
