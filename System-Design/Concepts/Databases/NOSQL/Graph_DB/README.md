**Graph DB**
- [Terms: Node](#te)
- **Examples**
  - [1. Neoj4](#nj)
  - [2. Amazon Neptune](#nep)

## Graph DB
We all are connected to each other with complex graph.
- *[GraphDB use cases](#nep)*
- *Graph vs Relational DB*
```c
DB                      |        Graph                                  |           Relational
------------------------|-----------------------------------------------|-------------------------------
Computing relationships | stores connections alongside the data in node | Uses expensive JOIN operations
```

<a name=te></a>
## Terms
**Node** Entity of graph storing data. Data stored on Node:
```c
Properties:    These are <key:value> pair stored on node. Node can hold any number of attributes.
Label:         Each node can have a label representing different role in domain.
Relationnship: Always directed. Provides connections between two nodes. (e.g. Employee WORKS_FOR Company).
  - Relationships can also have properties(Eg: weights, costs, distances, ratings, time intervals, or strengths).
```

## Examples
<a name=nj></a>
### 1. Neoj4 (written in java)
Developed by(Neo4j, Inc), version-1.0(2010), 4.1(2020). Neo4j has both a Community Edition and Enterprise Edition of the database.
- *Properties* ACID complaint, Graph storage and processing
- If want to use other languages you need to use [Cypher(Query Language)](https://en.wikipedia.org/wiki/Cypher_(query_language))

#### Installation
```c
//Ubuntu
 # sudo apt install openjdk;
 # java --version                         //JDK version 9 or above is good
 $ sudo wget -O - https://debian.neo4j.org/neotechnology.gpg.key | sudo apt-key add -      //Take key
 $ sudo echo 'deb https://debian.neo4j.org/repo stable/' | sudo tee -a /etc/apt/sources.list.d/neo4j.list //Add repository
 $ sudo apt-get update
 $ sudo apt install neo4j                     //Install
 $ sudo apt remove neo4j                     //Remove
 $ neo4j --version

//Fedora
# rpm --import https://debian.neo4j.com/neotechnology.gpg.key
# cat <<EOF>  /etc/yum.repos.d/neo4j.repo
[neo4j]
name=Neo4j RPM Repository
baseurl=https://yum.neo4j.com/stable
enabled=1
gpgcheck=1
EOF
# yum install neo4j -y
# systemctl disable neo4j                     //Disable autostart
```

<a name=nep></a>
### 2. Neptune
Used for applications that work with highly connected datasets. Stores billions of relationships and queries the graph with milliseconds latency.
- **Use cases?** Used where you need to create relationships between data and quickly query these relationships.    
- **Examples**
```c
1. social networking:      Neptune enables highly interactive graph queries with high throughput to bring social features into your applications.
2. Recommendation engines: Neptune allows you to store relationships between information such as customer interests, friends, and purchase history in a graph. Hence Neptune can be used to make product recommendations 
3. fraud detection:        Neptune can use relationships to process financial and purchase transactions in near real time to easily detect fraud patterns. Eg: multiple people sharing the same IP address but residing in different physical addresses.
4. Knowledge Graphs:
    - *What is KG* allows to store information in a graphs and use graph queries to enable users to navigate highly connected datasets.
    - *For example*  if a user is interested in The Mona Lisa, you can also help them discover other works of art by Leonardo da Vinci 
5. Life Sciences:      1. Use Neptune to store models of disease and gene interactions. 2. model chemical compounds as a graph and query for patterns in molecular structures
6. Network / IT Operations: Neptune can store a graph of network and use graph queries to answer questions like how many hosts are running a specific application.
    - Neptune can find hosts or devices that may be compromised. For example, if you detect a malicious file on a host, Neptune can help you to find the connections between the hosts that spread the malicious file, and enable you to trace it to the original host that downloaded it
```
