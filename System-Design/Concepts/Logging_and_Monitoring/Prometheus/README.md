**opensource Prometheus (Pull based system)**
- [About](#ab)
- [Usage scenario](#us)
- [Internal Architecture](#int)
- [Terms](#terms)
  - [1. Target](#tar)
  - [2. Metric](#met)
  - [3. Scrape](#sc)
- [Configuring Prometheus](#conf)

<a name=pro></a>
## Prometheus (Monitoring,Alerting & logging tool)
### About Prometheus
- _1._ This is pull based system
- _2._ Designed as standalone and hence reliable system, so that when complete infra goes down, promethus should be up and can be used to diagnose the problem.
  - DISADVANTAGE: Promethus is difficult to scale.
- _3. Compatible with Docker and kubernets_: Prometheus is fully compatible with both and is available as docker images.

<a name=us></a>
### Usage scenario
  - Consider datacenter running several servers running containarized applications(and each application has 5-10 threads/processes) and things are interconnected.
  - App4 crashed making App8 to function inappropraitely and whole application becomes unavailable to user.
  - How to identify which process in application crashed and Why it crashed?
- **What Prometheus does?**
  - _1. Monitor & Alert:_ Monitors resources(High memory, CPU usage, latency etc) of servers on data center. Whenever any server's CPU goes high or latency increses it alerts admin about the same.
  - _2. Logging:_ store logs and sends [metrices](#met).

<a name=int></a>
### Internal Architecture
- _1. Retriever:_ Retriever sends "http GET hostaddress/metrics", fetches metriecs from Applications and stores in DB. Server should expose metrics in correct format.
  - _Exporter:_ Prometheus provides exporters which can be installed and used on target. Exporter will generate metrics to be sent to prometheus server. Example 
    - _a. linux_ just download expoter.tar.gz install, it wil expose /metric endpoint and send the data to server once needed.
    - _b. mysql:_ mysql has side car exporter.
    - _c. client libraries:_ For user applications, these are avaiable in different languages like node.js, java, c++ etc
- _2. DB:_ Prometheus stores data on local hard-disk(hdd/ssd), it can also store data into [relational databases]().
- _2. HTTP Web Server:_ shows the data to prometheus UI or Grafanna after accepting APIs.
- _3. AlertManager:_ Prometheus server reads alert rules and sends notifications/alerts to users.
- _4. PromQL query language:_ Using promQL, http server can be queried. For example:
  - _a._ Querying a particular target
  - _b._ Feed data to Grafanna 
```c
------------------------------------------------- cloud ------------------------------------------------------
               |----------Prometheus----------|          |-------server-1-------|     |-------server-2-------|
prometheus UI <--HTTP webServer<-|            |          | container[App1]      |     | container[App3]      |
or             |   |             |            |          |      container[App2] |     |      container[App4] |
Grafanna       |   |           DB<-|          |          |----------------------|     |----------------------|
               |   |               |          |
               |  \/              Retriever  ----http GET hostaddress/metrics-->  |-------server-n---------|
   Email <------ AlertManager                 |                                   | exporter creates data  |
               |                             <--metrics----------------------------                        |
               |------------------------------|                                   |   container[App9]      |
                                                                                  |        container[App8] |
                                                                                  |------------------------|
```  

<a name=terms></a>
### Terms
<a name=tar></a>
#### 1. Target
- Identity which Prometheus can monitor is called target. Eg:
  - Linux/Windows server: Monitor CPU status, memory/disk usage
  - Single Application: Can monitor exception count, request count, response count
  - Service, DB
<a name=met></a>
#### 2. Metrics
Data which is monitored for specific target is called metric which is saved in DB. Example of metrics entry.
```
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
