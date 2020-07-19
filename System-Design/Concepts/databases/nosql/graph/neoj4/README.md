# About Neoj4
- **Developed by** Neo4j, Inc
  - version-1.0(2010), 4.1(2020)
- Neo4j has both a Community Edition and Enterprise Edition of the database.
  - Enterprise Edition: includes all that Community Edition features, plus extra enterprise requirements such as backups, clustering, and failover abilities.
- **Properties** ACID complaint, Graph storage and processing
- **Written in** Java. 
  - If want to use other languages you need to use [Cypher(Query Language)](https://en.wikipedia.org/wiki/Cypher_(query_language))

# A. Installation
#### Ubuntu
```
 # sudo apt install openjdk;
 # java --version                         //JDK version 9 or above is good
 $ sudo wget -O - https://debian.neo4j.org/neotechnology.gpg.key | sudo apt-key add -      //Take key
 $ sudo echo 'deb https://debian.neo4j.org/repo stable/' | sudo tee -a /etc/apt/sources.list.d/neo4j.list //Add repository
 $ sudo apt-get update
 $ sudo apt install neo4j                     //Install
 $ sudo apt remove neo4j                     //Remove
 $ neo4j --version
``` 

#### Fedora   `[Working]`
```
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

# B. DATABASE
- Neo4j supports multiple databases within the same DBMS. 
- The metadata + security-model for these databases is maintained in a special database called the **system database**.
- All multi-database administrative commands must be run against the system database.
