**opensource Prometheus (Pull based system)**
- [Usage scenario](#us)
- [Internal Architecture](#int)
- [Terms](#terms)
  - [1. Target](#tar)
  - [2. Metric](#met)
  - [3. Scrape](#sc)
- [Configuring Prometheus](#conf)

<a name=pro></a>
## Prometheus (Centralized Monitoring,Alerting & logging tool)
- This is central monitoring and logging system. This is designed as standalone and hence reliable system, so that when complete infra goes down, promethus should be up and can be used to diagnose the problem.
  - _1. Monitor & Alert:_ Monitors resources(High memory, CPU usage, latency etc) of servers on data center. Whenever any server's CPU goes high or latency increses it alerts admin about the same.
  - _2. Logging:_ store logs and sends [metrices](#met).
- DISADVANTAGE: Promethus is difficult to scale.
- Prometheus is Compatible with Docker and kubernets: Prometheus is fully compatible with both and is available as docker images.

<a name=us></a>
### Usage scenario
- Consider datacenter running [Kubernets cluster]() on several servers, K8s cluster is running applications inside containers(and each application has 5-10 threads/processes) and things are interconnected.
- App4 crashed making App8 to function inappropraitely and whole application becomes unavailable to user.
- How to identify which process in application crashed and Why it crashed?
  - Prometheus will store logs, which can be monitored using (Prometheus UI or Grafanna) to check the issue.

<a name=int></a>
### Internal Architecture
- **1. Retriever:** Retriever call [REST API](/Networking/OSI-Layers/Layer-7/WebServer_WebClient_WebService/WebClient_Connecting_WebServer/REST) `http GET ip-address:port/metrics`. [Target or server](#tar) provides [metrics](#met) with help of [Client library](#hl), retriever stores in DB. Target should expose metrics in correct format.
- **2. Database:** Prometheus stores data on local hard-disk(hdd/ssd), it can also store data into [relational databases](/System-Design/Concepts/Databases).
- **3. HTTP Web Server:** shows the data to prometheus UI or Grafanna after accepting APIs.
- **4. AlertManager:** Prometheus server reads alert rules and sends notifications/alerts to users.
- **5. PromQL query language:** Using promQL, http server can be queried. For example:
  - _a._ Querying a particular target
  - _b._ Feed data to Grafanna 
```c
------------------------------------------------- cloud ------------------------------------------------------
               |----------Prometheus----------|          |-------server-1-------|     |-------server-2-------|
prometheus UI <--HTTP webServer<-|            |          | container[App1]      |     | container[App3]      |
or             |   |             |            |          |      container[App2] |     |      container[App4] |
Grafanna       |   |           DB<-|          |          |----------------------|     |----------------------|
               |   |               |          |
               |   |               |          |                                       |-------server-n-------------------------|
               |  \/              Retriever(API call) -http GET hostaddress/metrics---> User-Application(http_server)          |
   Email <------ AlertManager                 |                                       |      ----------data----->Client Library|
               |                             <-- prometheus metrics------------------------  <-prometheus metric-----          |
               |------------------------------|                                       |                                        |
                                                                                      |        container[App8]                 |
                                                                                      |----------------------------------------|
```
<a name=hl></a>
**Helper Utilities to generate metric**
  - **[a. Client libraries (`*.so, *.a, *.lib, *.dll`)](https://prometheus.io/docs/instrumenting/clientlibs/)** User applications will use these and these libs will generate data in metric form. Different languages like node.js, java, c++, rust have different libs.
```c
  |-----Prometheus-------|                              |-----------------------
  |                      ------GET hostaddress/metrics--> User-Application(Target/Server) 
  |----------------------|                              |     --------data-------------> Client Library
                                                        |    <-----prometheus metric---------
                       <---------------metric----------------
                                                        |------------------------
```
  - **[b. Exporter:](https://prometheus.io/docs/instrumenting/exporters/)** These Can fetch statistics from another, non-Prometheus system. Client Libraries will turn these statistics to prometheus metrics.
  - _a. linux_ just download expoter.tar.gz install, it will expose /metric endpoint and send the data to server once needed.
  - _b. mysql:_ mysql has side car exporter.
```c
  |-----Prometheus-------|                              |--------------------
  |                      ------GET hostaddress/metrics--> User-Application(on Linux) 
  |                      |                              |     ----get system data------> Exporter
  |                      |                              |    <-----data--------------------
  |                      |                              |   ---------data--------------> client Library
  |                      |                              |   <---- prometheus metric---------
  |                    <-----prometheus metric----------------
  |----------------------|                              |---------------------
```
<a name=terms></a>
### Terms
<a name=tar></a>
#### 1. Target
Identity which Prometheus can monitor is called target. Eg:
  - Linux/Windows server: Monitor CPU status, memory/disk usage
  - Single Application: Can monitor exception count, request count, response count
  - Service, DB
<a name=met></a>
#### 2. Metrics
Data which is monitored for specific target is called metric. This data is generated by user application using [client library](#int), sent to prometheus using [exporter](#int) and [Retriever](#int) saves on DB.
```
//Example of metrics entry

# HELP: process_max_fds        //Description: Maximum number of open file descriptors
# TYPE: process_max_fds gauge
process_max_fds 811818

# HELP: process_open_fds        //Description
# TYPE: process_open_fds gauge
process_max_fds 123

# HELP: process_start_time_seconds   //Description: Start time since unix epoch in seconds
# TYPE: process_start_time_seconds gauge
process_start_time_seconds 1920910291.91

# HELP: process_virtual_memory_bytes   //Description: virtual memory size in bytes
# TYPE: process_virtual_memory_bytes gauge
process_virtual_memory_bytes 12889098109
```
<a name=sc></a>
#### 3. Scrape
Pulling data from targets is called scraping. Prometheus will scrap the metric using http. [Target](#tar) should support `http://ip:port/metrics/` and provide metrics.

<a name=conf></a>
### Configuring Prometheus
Who and what need to be [scraped](#sc) is defined inside prometheus.yml file and at what interval.
