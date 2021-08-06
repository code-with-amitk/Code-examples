**Networking Devices**
- [Firewall vs Gateway vs Router](#comp)
- Types
  - [Firewall](#fw)
  - [Gateway](#gw)
  - [Router](#rtr)


<a name=comp></a>
## Firewall vs Gateway vs Router

||Firewall(Layer3,4)|SWG(Secure Web Gateway) / Gateway(3,4,5)|Router(Layer 3)|
|---|---|---|---|
|Can look|IP,port of incoming,outgoing packets|Into HTTP packet content|IP|

<img src=Firewall_Gateway_Router.jpg width=800 />

**Bridge?** This is a Link Layer device which forwards traffic between network-1 and network-2. This can be hardware or Software.

## Types
<a name=fw></a>
### Firewall
sits at gate of organization in DMZ Zone.

<a name=gw></a>
### Gateway / SWG(Secure Web Gateway) / Application Level Gateway
Bridges 2 networks. Can look into application level packet contents. Eg:
  - *1.* HTTP is used for Web browsing(allow this)
  - *2.* HTTP is used for File-sharing(block this)
  - *3.* Not allowing documents to send by Email using HTTP.

**Real world SWG**
- [Juniper SRX Series](Gateway/Juniper_SRX)
- Fiiire-Storrm (see pvt reasearch)

<a name=rtr></a>
### Router
Within network. Device or a hardware which is responsible for receiving, analyzing and forwarding the data packets to other networks
