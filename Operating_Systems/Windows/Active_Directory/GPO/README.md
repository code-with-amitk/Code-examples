**GPO**
- [Where GPO can be applied](#where)
- [GPO Terms](#terms)
- [Structure of GPO](#st)
- [View GPO](#view)
- [Distribute PAC file URL to joined Machines](#p)

## GPO / Group Policy Object
- GPO is a collection of settings for a group. Ex: Enforce a password complexity policy that prevents users from choosing an overly simple password. GPO is always linked to a Container. Eg: "ou=test-computers,dc=atest,dc=com"
- By default these 2 GPOs are linked to the AD domain object(all users and computers):
  - _1. Default Domain Policy GPO GUID:31B2F340-016D-11D2-945F-00C04FB984F9_: Contains settings applicable to all computers and users in the domain, 
  - _2. Default Domain Controllers Policy GPO GUID:6AC1786C-016F-11D2-945F-00C04fB984F9_ Contains settings applicable to computers functioning as domain controllers. 

<a name=where></a>
### Where GPOs can be applied?
> Order in which GPO can be applied are: Local,Site,Domain,OU (LSD OU)
- **a. Local(L):** GPO applied to local computer. This can be overridden by GPO's applied to site, domain, or OU.
- **b. Site(S)** GPO applied to AD site. Viewing Site-GPO > cmd > Group Policy Management Editor > Forest > Sites
**c. Domain(D)** Applied to Domain. Policies created at ROOT of domain.
- **d. Organizational Unit(OU)** Group policies assigned to the organizational unit (OU) in which the computer or user are placed.

<a name=terms></a>
### GPO Terms
- _1. gpOption:_ Parameter for AD Object, not related to gpLinkOption.
- _2. gpLink:_ String in which AD passes GPO list to ldapclient. Format: `[<GPO DN_1>;<GPLinkOptions_1>][<GPO DN_2>;<GPLinkOptions_2>]... [<GPODN_n>;<GPLinkOptions_n>]`
- _3. gpLinkOption:_ `<gpLink; gpLinkOption>` This is an Integer value. used to block GPO inheritance. Values:
```c
    0: Default is 0. The GPO Link preceding the <GPLinkOptions> field is not ignored and is not an enforced GPO.
    1: The GPO Link preceding the <GPLinkOptions> field MUST be ignored
    2: The GPO Link preceding this <GPLinkOptions> is an enforced GPO.
    3: The GPO Link preceding the <GPLinkOptions> field MUST be ignored; in other words, when the 0x00000001 bit is set, the 0x00000002 bit is ignored, and the behavior is the same as if the flag value were 0x00000001.
```
- _4. Enforced GPO:_ Enforced GPO will have higher precedence. By default GPO is not Enforced.
- _5. RSOP:_ The resulting Group Policy settings applied to a given computer or user are known as the Resultant Set of Policy (RSoP)

<a name=st></a>
### Structure of GPO
- It composed of 2 parts:
  - _a. GPC(Group Policy Container):_ which exists in AD
  - _b. GPT(Group Policy Template):_ where the actual content of your GPOs resides
  - _c. CSE(Client-Side Extensions):_ Can be found on client devices and are necessary for them to properly process the Group Policies assigned to them

<a name=view></a>
### Viewing 
```c
Domain-GPO > cmd > Group Policy Management Editor > Forest > Domains > atest.com > Double Click
```

<a name=p></a>
### Distribute PAC file URL to joined Machines
#### Distribute 
- [Method-1. Zsaler](https://help.zscaler.com/zia/distributing-pac-file-url-my-users)
- [Method-2. Using Registry](https://www.youtube.com/watch?v=A_GjfvR7qhA)
#### [Check PAC URL recieved on joined Machine](https://www.youtube.com/watch?v=A_GjfvR7qhA)
