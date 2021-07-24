- [What is Active Directory](#what)
- AD Objects
  - [1. Container Objects](#con)
  - [2. Leaf Objects](#leaf)
- [Trust](#trust)
  - [Directions](#dir)


<a name=what></a>
## AD? 
- Centralized DB/Repository of Objects(Users, Groups, Resources, Services).     
- Resources: Print Server, File Servers(Shared Folders), Mail server

## AD Objects
<a name=con></a>
### 1. Container Objects
These can contain other objects inside them. Examples
- **A1. DOMAIN:** 
  - In Dictionary meaning it is Area/region controlled by authority. In AD Terms this is Logical group of computers/objects having Windows OS installed.
- **A2. TREE:** 
  - This is hierarchical arrangement of Windows domains that share same namespace. Collection of 1 or more domains. Each domain must have relation-ship(Eg: parent child)
- **A3. FOREST:**  
  - This is biggest container Object in AD. This is collection of Trees. Forest is collection of 2 or more tress. User in 1 AD forest can access resource in other AD tree. https://www.youtube.com/watch?v=DPFXmOfzuMI

<a name=leaf></a>
### 2. Leaf Objects
- Cannot contain other objects inside them. Eg: User, computers, printers
```c
<---------------------------Forest------------------------------------------>
             Tree-1 Root                            Tree-2 Root  
              abc.com           <---trust---->      inktank.com
       /                \                         /                \                      
{Parent Domain}  {Parent Domain}                /                    \
x.abc.com        y.abc.com                      brno.inktank.com   us.inktank.com  
  /                                                                                                                                       
{Child/Sub Domain}                                                                                                          
x1.x.abc.com
```

## Trust
- Suppose Company-x has AD-1 and AD-2. Trust relationship can be established b/w 2 ADs. Users on AD-1 can access resources joined on AD-2.
<a name=dir></a>
### Directions
#### 1 way
- unidirectional authentication path created between two domains (trust flows in one direction, and access flows in the other). This means that in a one-way trust between a trusted domain and a trusting domain, users or computers in the trusted domain can access resources in the trusting domain. However, users in the trusting domain cannot access resources in the trusted domain
#### 2 way
- the trusting and trusted domains both trust each other (trust and access flow in both directions). This means that authentication requests can be passed between the two domains in both directions. All domain trusts in an Active Directory forest are two-way, transitive trusts. When a new child domain is created, a two-way, transitive trust is automatically created between the new child domain and the parent domain.
