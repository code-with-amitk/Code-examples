**Commands**
- [get ip addresses](#g)
- [User Identification](#ui)
- [Logging](#sl)
  - [Batch query logs](#bql)
- [Counters, Status](#cs)
- [Policies, Authentication Tables](#p)

### Commands
<a name=ui></a>
#### Get IP Addresses
```c
> cli
> show interfaces terse
```

<a name=ui></a>
#### User Identification
```c
root# cli
root> edit
Entering configuration mode
root# show | display set                              //All services
set version 10.4R
set global interfaces 1o0 ...........   //Interfaces for connectivity
set                                     //zones
..                                      //Policies

# show services user-identification | display set     //for JIMS
set services user-identification device-information authentication-source-network-access-controller
set services user-identification device-information end-user-profile profile-name a domain-name <>
set services user-identification device-information end-user-profile profile-name a-group device-identity string <>
set services user-identification identity-maangement connection connect-method https

delete services user-identification identity-maangement connection connect-method https        //To delete config

set services user-identification identity-maangement connection port 443
set services user-identification identity-maangement connection primary address jims-IP        //Primary
set services user-identification identity-maangement connection primary client-id test 
set services user-identification identity-maangement connection primary client-secret test
set services user-identification identity-maangement connection secondary address jims-IP      //Secondary
set services user-identification identity-maangement connection secondary client-id test 
set services user-identification identity-maangement connection secondary client-secret <>
set services user-identification identity-maangement batch-query items-per-batch 100
set services user-identification identity-maangement batch-query query-interval 5

root# deactivate services user-identification identity-management connection secondary          //Deactivate Secondary
root# commit
root# set services user-identification identity-maangement connection primary address jims-IP   //Set New Primary
root# commit
root# set services user-identification identity-maangement connection primary client-secret test
root# commit
```
<a name=sl></a>
#### Set Logging
```c
exit
exit
> configure
Entering configuration mode
# set services user-identification identity-maangement traceoptions file test.txt
# set services user-identification identity-maangement traceoptions flag all
# set services user-identification identity-maangement traceoptions level all
# exit
Exiting configuration mode
> exit
> cat /var/log/test.txt
```
<a name=bql></a>
**Batch query logs**
```c
set groups jims-server services user-identification identity-management traceoptions file jims_query.log
set groups jims-server services user-identification identity-management traceoptions file size 10M
set groups jims-server services user-identification identity-management traceoptions level all
set groups jims-server services user-identification identity-management traceoptions flag all
set groups jims-server services user-identification identity-management traceoptions flag jims-validator-query

show log jims-query.log
or 
goto shell prompt and open /var/log/jims-query.log
```

<a name=cs></a>
#### Counters, Status
```c
# run show services user-identification identity-management counters
# run show services user-identification identity-management status
            Primary server :
            Address                      : ip
            Port                         : 443
            Source                       : Automatic
            Interface                    : Automatic
            Routing-instance             : Automatic
            Connection method            : HTTPS
            Connection status            : Online
            Last received status message : OK (200)
            Access token                 : <>
            Token expire time            : 2022-01-31 16:20:08
            
            Secondary server :
            Address                      : ip
            Port                         : 443
            Source                       : Automatic
            Interface                    : Automatic
            Routing-instance             : Automatic
            Connection method            : HTTPS
            Connection status            : Online
            Last received status message : OK (200)
            Access token                 : <>
            Token expire time            : 2022-01-31 16:22:19

//////////////reboot: Needed when you change config////////////////
# reboot
```

<a name=p></a>
### Policies, Authentication Tables
```c
1. On qa-central or dav-central.
$ get_vsrx_tanant <tanent-id>
  TenantPop: uuid1
    srx: ip-address-1
  TenantPop: uuid2
    srx: ip-address-2
  TenantPop: uuid3
    srx: ip-address-3
    
2. Login to any srx
$ ssh root@ip-address-2
Password:
# run show services user-identification authentication-table authentication-source all
Total entries: 8
Key            Username       groups(Ref by policy)   state
1.2.3.4        administrator                          Valid
4.5.6.6        amit                                   Valid             //user=amit logged with IP

# run show services user-identification authentication-table authentication-source all extensive
```
