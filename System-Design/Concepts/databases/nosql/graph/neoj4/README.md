## NEOj4

### Basic Information
- **Developed by** Neo4j, Inc
  - version-1.0(2010), 4.1(2020)
- **Properties** ACID complaint, Graph storage and processing
- **Written in** Java. 
  - If want to use other languages provides support for [Cypher(Query Language)](https://en.wikipedia.org/wiki/Cypher_(query_language))

### Installation
#### Ubuntu
```
 # sudo apt install openjdk-8-jdk; 
 $ sudo wget -O - https://debian.neo4j.org/neotechnology.gpg.key | sudo apt-key add -       //Update the package repository to include Neo4J
 $ sudo echo 'deb https://debian.neo4j.org/repo stable/' | sudo tee -a /etc/apt/sources.list.d/neo4j.list
 $ sudo apt-get update
 $ sudo apt install neo4j
 $ neo4j --version
 
