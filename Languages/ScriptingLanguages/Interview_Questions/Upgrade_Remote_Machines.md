## Upgrade remote machines 
- Send packets to remote machines and try to upgrade the packet remotely.Troubleshooting why some of the machines are not updated.

## Approach
- *1.* Prior to login for upgrade, We should configure passwordless login using ssh public,pvt keys
- *2.* Take a txt file containing username and IP addresses
```c
  amit@10.20.30.189
  test@10.118.161.22
```
- *3.* Read the text file line by line.
- *4.* Call ssh and execute `yum upgrade` command on remote machine. Check the return status of `yum upgrade`

## Code
```bash
#!/usr/bin/env bash

sshRemote(){
  ssh $1 "sudo apt upgrade | grep 'success'"
  if [ $? == 0 ]                                  #Check return code
  then
    YUMSTATUS = 0
  else
    YUMSTATUS = 1
  fi
}

ReadFile() {              #Read every line from input file
  while IFS='' read -r ParsedLine
  do
    sshRemote ParsedLine
    if [ $YUMSTATUS == 0 ]
      echo "Upgrade Success"
    else
      echo "Upgrade Failed"
  done < "$1"
}

ReadLine $1
```
