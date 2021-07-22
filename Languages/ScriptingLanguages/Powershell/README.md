- [What is powershell](#what)
- Examples
  - [Services](#ser)

<a name=what></a>
## Powershell
- This is command-line shell, a scripting language, and a configuration management framework. PowerShell runs on Windows, Linux, and macOS.
- This is case-insensitive.
```ps
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
```ps
$ get-service                                           //List all services on system
$ get-service | where-object {$_.status -eq "stopped"}  //All stopped services
$ PS C:\Users\amitk> get-service | get-member           //Get all methods avilable on services

Name                      MemberType    Definition
----                      ----------    ----------
Close                     Method        void Close()
Continue                  Method        void Continue()
```
