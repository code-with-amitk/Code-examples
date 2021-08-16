- [chroot](#ch)
- [Redirection `>`](#re)
- [sed](#sed)

<a name=ch></a>
### chroot
- Every process/command in Linux has root directory. chroot changes the root directory for currently running processes as well as its child processes.
- **jailed Directory?** A process/command that runs in such a modified environment cannot access files outside the root directory. This modified environment is known as “chroot jail” or “jailed directory”.
- **Advantages, Disadv of jail**
  - To create a test environment.
  - To recover the system or password.
  - To reinstall the bootloader.
- **Disadvatanges of Jail**
  - *1.* User can still access files outside root using relative paths,symlinks.
    - jail1/user1 can kill programs running outside of the jail. Also jail can look into the network devices.
  - *2.* `chroot` call overrides current jail.
  - *3.* Only priviledged processes with CAP_SYS_CHROOT are able to call chroot
  - *4.* Root user can create new jail and easily escape from a jail by running a program like this:
```c
int main(void){
    mkdir(".out", 0755);
    chroot(".out");
    chdir("../../../../../");
    chroot(".");
    return execl("/bin/bash", "-i", NULL);
}
```
- **Steps of Creating new root directory**
```c
$ mkdir $HOME/jail                    //Create a “jail” directory inside the “home” directory, which will be our new root.

$ mkdir -p $HOME/jail/{bin, lib64}    //Create bin, lib64 inside “$HOME/jail”:
$ cd $HOME/jail

$ cp -v /bin/{bash, ls} $HOME/jail/bin  //Copy /bin/bash and /bin/ls into $HOME/jail/bin/ location.

$ ldd /bin/bash                         //Use ldd command to print shared libraries used by /bin/bash

$ cp -v libraries/displayed/by/above/command $HOME/jail/lib64   //Copy required libraries into $HOME/jail/lib64/.

//Similarly, copy the libraries of ls command into $HOME/jail/lib64 location.

$ sudo chroot $HOME/jail /bin/bash              //Finally, chroot into your mini-jail:

//Create file in root it will created in `$HOME/jail`.
```

<img src=chroot-jail.png width=400 />

<a name=re></a>
### Redirection `ls -ltr > a.txt`
Redirection is implemented using dup2() system call.

<a name=sed></a>
### SED(Stream Editor)
For performing file operations(Search Text, Find and replace, Insert, delete) without opening files.
```c
//Replace Commands
  $ sed 's/unix/linux/g' test.txt       //Replace all occurence of unix with linux from file test.txt
    
  $ sed 's/unix/linux/2' test.txt       //Replace 2nd occurence of unix with linux
    
  $ sed '3 s/unix/linux/' test.txt      //Replace occurence only on 3rd line
    
  $ sed '1,3 s/unix/linux/' test.txt    //Replace occurence only on 1st,3rd line
```    
