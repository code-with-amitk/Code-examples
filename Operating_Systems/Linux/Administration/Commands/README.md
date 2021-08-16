- [chroot](#ch)
- [netstat](#net)
- [Pipe `ls -ltr | grep test`](#pipe)
- [Redirection `ls -ltr > a.txt`](#re)
- [sed](#sed)
- [systemctl](#sys)
- [systemd-run](#sysd)

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

<a name=net></a>
### netstat
Print network connections, routing tables, interface statistics, masquerade connections, and multicast memberships. *Options*
```c
-p:show pid,    -a:all interfaces,  -n:show Numeric,  -t:tcp,   -u:udp
```
**Commands**
- *1. Show TCP/UDP statistics of all interfaces:* `# netstat  -plunt`
- *2. Get number of active connections:* `# netstat -ant | awk '{print $NF}' | grep -v '[a-z]' | sort | uniq -c`
- *3. Get number of connections per ip address:* `# netstat -ntu | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -n`
- *4. Get all IP Address connected to your host:* `# netstat -lantp | grep ESTABLISHED |awk '{print $5}' | awk -F: '{print $1}' | sort -u`
- *5. Monitor open connection to web server on port 80, count and sort it by IP:* `# watch "netstat -plan|grep :80|awk {'print \$5'} | cut -d: -f 1 | sort | uniq -c | sort -nk 1"`

<a name=pipe></a>
### Pipe `ls -ltr | grep test`
Output of process-1 becomes the input of process-2 ie standard output (stout) of one command is sent to the standard input (stdin) of a second command.
- Pipes are unidirectional i.e data flows from left to right through the pipeline.
- **Filter?** Commands which takes input from prev commands are called filters. These can modify the stream

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

<a name=sys></a>
### systemctl
[systemd](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1) utility that is responsible for Controlling the systemd system and service manager.
- **Listing units commands**
```c
# systemctl -t help                             //List all available units of systemd

//////////SERVICE UNIT///////////
# systemctl --all list-units | grep .service    //lists all available units in the type service.
  abrt-ccpp.service
  abrt-ops.service
  abrt-vmcore.service
# systemctl start | is-active | reload | list-dependencies sshd.service       //View status/reaload/list-dependencies of service
# systemctl list-dependencies <unit>                            //Prints tree of units those must be started if this unit is started.
# systemctl    mask/unmask     network        //Masking service

///////////SOCKET UNIT///////////////
#systemctl list-unit-files | grep .socket       //status of socket units
```

<a name=sysd></a>
### systemd-run
systemd-run may be used to create and start a transient systemd [`*.service` or `*.scope` unit](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1) and run the specified COMMAND in it.
- **Steps**
  - *1.* Create [Transient cgroup](/Operating_Systems/Linux/Resource_Control/Kernel_Namespaces/cgroup/RHEL_Provided_cgroup)
```c
//Create a new group called group1. Run top command inside that group. Name of command=amit_top.service
# sudo systemd-run --unit=amit_top --slice=group1 top -b
```
  - *2.* Set amount of resource cgroup can use.
```c
//systemctl set-property --runtime    name          property=value
# systemctl set-property --runtime amit_top.service CPUShares=600 MemoryLimit=500M
```
  - *3.* View information about control group.
```c
# systemd-cgls              //Entire cgroup hierarchy
├─system
│ ├─1 /usr/lib/systemd/systemd --switched-root --system --deserialize 20  
├─ group1.slice
|   ├─ amit_top.service
        ├─ 3714 /bin/top -b
....

# systemd-cgtop                         //View Resource,CPU,IO consumed by cgroup
Path                             Tasks   %CPU    Memory    Input/s   Output/s
/                                 260     3.4     658.9M      -         -
/group1.slice/amit_top.service      1      -        -         -         -
...
```
