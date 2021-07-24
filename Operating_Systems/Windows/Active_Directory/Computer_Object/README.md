- [What is Computer Object](#what)
- [Pre-stage Account](#pre)
- [Machine/Computer Account Password](#acc)

<a name=what></a>
## Computer Object
- In Simple terms this is Computer account maintained on ADDS for all computers which are joined to AD. Each computer has a (SID+Attributes).
- Computer accounts are used in the same ways that user accounts are used for users.
- **Disabling User/Computer Account:** ADDS never disables the account. Only Manual or script(WMI/powershell) disabling of User/computer account can happen
```
    RHEL                            AD
# net ads join -U <>
                               PS> import-module activedirectory
                               PS> Get-ADComputer -Identity rhel7-5(ie hostname)
```

<a name=pre></a>
## Pre-stage Account
- Apart from joining AD using `net ads join`, Admin can manually create the computer account in advance which is called pre-stage.
- Joining the computer using 'net' or 'realm', host will check whether a pre-staged computer account is present, and if it is then it will use that computer account instead of creating one within the Computers container.
- _Why pre-stage?_
  - A pre-stage computer account ensures that the computer is put into the correct OU. if not pre-staged computer account will be created in the default location of computers which may have different Group policies from what are required.
  - When a pre-stage computer account is created, permissions can be assigned on the pre-stage account
- _Creating pre-stage account?_
  - Active Directory Users and Computers > OU=test-Computers > new > Computer

<a name=pass></a>
## Machine/Computer Account Password
- Once the computer is joined to a domain,we can configure password for it. 
- Age of password? Never. Setting value AD Local Security Policy > Local Policies > Security Options > Domain member: Maximum machine account password age.
