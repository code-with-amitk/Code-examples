- [What is VPN](#what)
- [Terms](#terms)
- Types of VPN
  - [1. Policy Based](#pb)
  - [2. Route Based](#rb)
  - [3. Site To Site](#s2s)
    - [3.1 Hub & Spoke](#hs)
    - [3.2 Full Mesh](#fm)
    - [3.3 Partial Mesh or MultiPoint](#pm)
  - [4. Remote Access](#ra)
- [Opensource VPN Implementations](#os)


<a name=what></a>
## VPN / Virtual Private Network
- Encrypted connection over the Internet between devices. Eg: An employee working from home connects securely to his office servers.

<a name=terms></a>
## [Terms](Terms)
Cookie, DOI(Domain on Interpretation), Nonce, PFS(Perfect Forward Secrecy), SA(Security Association), SP(Security Policy), SPI(Security Parameter Index), NAT Traversal, XAuth

## Types of VPN
<a name=pb></a>
### 1. Policy-Based VPN
- Policy is defined (Eg: based on source IP, destination IP, application, and respective to- and from-zones).
- Traffic satisfying particular policy is passed thru VPN tunnel.
- Proxy IDs are derived from the firewall policy.

<a name=rb></a>
### 2. Route Based
- These uses a Virtual Interface(called secure tunnel interface (st0 interface)).
- All traffic routed into the interface will be sent into a VPN.
- Traffic to be sent into st0 is decided on routing, hence name route-based VPN.
- **Types of Route Based VPNs**
  - *1. Point To Point VPN*
    - There are only 2 hosts in VPN communication channel. Host-1 interface connects to Host-2 using secure interface.
    - Host-1 may have other interface connected to other subnets.
  - *2. Point to Multipoint*
    - One interface can connect to multipoint VPN servers.

<a name=s2s></a>
### 3. Site To Site VPN
- S2S VPN is terminated between to 2 Gateways.

<a name=hs></a>
#### 3.1 Hub & Spoke
- Many company networks have 1 corporate office with many branch offices.
- If branch office need to access the resource, they connect to corporate office.
```html
BranchOffice-1(SPOKE) ---------------
                                    \/
BranchOffice-2(SPOKE) --------> CorporateOffice(HUB)
                                    /\
BranchOffice-3(SPOKE) ---------------
```
- *Disadvantages?*
  - *1. Overloaded Hub resulting in lag, [Latency](/System-Design/Concepts/Terms) Issues* 
    - If Spoke=branchOffice-1 want to connect to Spoke=BranchOffice-2 it need to go thru Hub.
    - Big issue for applications eg: VoIP, Video Confrencing

<a name=fm></a>
#### 3.2 Full Mesh
- Each branch office connects to other branch office directly.
```html
site-1 --- site-3
 |    \     |
 |      \   |
site-2 -- site-4
```
- *Disadvantages*
  - *1. Complexity of implementation*
    - Because all sites must be interconnected), they cannot scale.
  - *2. Management overhead* 

<a name=pm></a>
#### 3.3 Partial Mesh or MultiPoint
- Combination of Hub & Spoke and Full Mesh VPN. Some Branch offices have direct connection to each other while some does not
```html
BranchOffice-1 -----------------
    |                          \/
BranchOffice-2 ----------> Corporate-Office(Hub)
    |                          /\
BranchOffice-3 -----------------
```
- *Advatages*
  - *1. Branch offices can connect to Hub and also amonngt themseleves*
    - This is good for performance reasons since, some office may need to exchange heavy data and overload hub.

<a name=ra></a>
### 4. Remote Access VPN
- User connects to office using VPN to access resources. Use can be working at home/traveling connects to office. Software needed to be installed on Remote user system.
```html
HomeUser1   ---vpn over internet---
                                  \/
HomeUser2   -------------------- Office
                                  /\
HomeUser3   -----------------------
```
- **Types of Remote Access VPN**
  - *1. IPSec VPN:* Establishes Layer3 Tunnel between Host and Office. Does encryption.
  - *2. SSL VPN:* Layer-5 browser is secured using SSL.

<a name=os></a>
## [Opensource VPN Implementations](OpenSource_VPN_server_Clients)
Libreswan/strongswan, openvpn

### Establishment of VPN Tunnel
- **2 Parts**
  - _[Part-1 IKE:](Part1_IKE)_ Establish encryption keys which is used to secure data sent on VPN tunnel.
  - *[Part-2 IPSec:](Part2_IPSec)* Encrypt data & send in [Tunnel or Transport mode](Part2_IPSec/Modes_Tunnel_Transport).
- [key lifetimes](Terms)
- **[Packet Flow:](Part2_IPSec/Packet_Flow)** IPSec packet comes to interface, goes out
