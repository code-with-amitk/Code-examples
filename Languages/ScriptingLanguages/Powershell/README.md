- [What is powershell](#what)
- Examples
  - [Services list](#ser)
- [Functions](#fun)

<a name=what></a>
## Powershell
- This is command-line shell, a scripting language, and a configuration management framework. PowerShell runs on Windows, Linux, and macOS.
- This is case-insensitive.
```ps1
/////Syntax(is natural english language)////////
$ get-service   -name   "*.net"   //Get all service name ending with net
  /\    /\        Parameters
 verb   Noun
 
 //////Help////
 $ get-help <cmd> -full   //Get-Help get-service
 $ get-command            //All command list
```

## Examples
<a name=ser></a>
### Services
```ps1
$ get-service                                           //List all services on system
$ get-service | where-object {$_.status -eq "stopped"}  //All stopped services
$ PS C:\Users\amitk> get-service | get-member           //Get all methods avilable on services

Name                      MemberType    Definition
----                      ----------    ----------
Close                     Method        void Close()
Continue                  Method        void Continue()
```

<a name=fun></a>
## Functions
```ps1
PS C:\Users\amitk> function add
>> {
>> $var = 3+2
>> write-output $var
>> }
PS C:\Users\amitk> add
5
```
