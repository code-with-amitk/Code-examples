**DNS Zone**
- Types of Zones
  - [A. Primary Zone](#pz)
  - [B. Secondary Zone](#sz)
  - [C. Stub Zone](#stz)
  - [D. Forward Lookup](#flz)
  - [E. Reverse Lookup](#rlz)


## DNS Zone
- Area/Sub-Part of a domain whose responsibility is given to a separate manager. A DNS name space is divided into nonoverlapping zones. And where zone boundaries are placed is up to zone administrator.
- **Why dns zone?** 
  - if whole information of 1 domain lies on 1 single machine(eg: for com domain lies on 1 machine), then TLD machines would be hugely overloaded and failure of 1 machine will make whole domain down.

<img src=dns-zones.PNG width=800 />

### Types of Zones
<a name=pz></a>
#### A. Primary Zone
- Methods of storing DNS information/DNS DB:    
- *1. locally in .txt file:* 
    - Disadvantages:
      - if some DNS Client asks question about server10 and if I donot have info then I keep on asking other DNS servers.
      - If server goes down name resolution for zone goes down since you are storing info locally on drive, there is no fault tolerance.
      - Since information lies inside simple text file, this can be easily hacked, Lot of security mechanisms needed to be applied to secure it
  - *2. On Active directory:* Here DNS has to reside on Domain Controller.

<a name=sz></a>
#### B. Secondary Zone
DNS secondary zone must get DB from primary zone. They get entire copy of DB. now DNS has locally stored DB but it is not editable. 

<a name=stz></a>
#### C. Stub Zone
This zone only contains those Resource Records which directs/points towards DNS server of other zones. https://www.youtube.com/watch?v=-92V95F-Hsg
  - Problem Scenario: if t1.abc.com want to resolve/contact p1.xyz.com. Then it asks same from abc.com. abc.com asks from com. com asks from root and then IP Address of xyz.com is returned to abc.com by com
  - Solution-Stub zone:   abc.com already stores few resource records of xyz.com so that every time it does not have to go to com to resolve it. records which are copied:   SOA, NS, glue A record, IP address of master server.
  - Creating a stub zone:    DNS Server > Forward Lookup zone > Right Click > New Zone > Next > Stub Zone > Zone name(abc.com) > IP Address (of Other domain's DNS Server) > Enter > Finish
```html
                         root
                           |
                          com
                   /                  \
             xyz.com                  abc.com
            /        \             /            \
    p1.xyz.com    p2.xyz.com     t1.abc.com    t2.abc.com
```
<a name=flz></a>
#### D. Forward Lookup Zone
- Zone that provides hostname to IP address service. DNS clients can use this zone to obtain such information as IP addresses that correspond to DNS domain names or services that is stored in the zone.

<a name=rlz></a>
#### E. Reverse Lookup Zone
Used to resolve IP Address to hostname
