**opensource Prometheus (Pull based system)**
- [Usage scenario](#us)
- [Internal Architecture](#int)
- [Terms](#terms)
  - [Target](#tar)
  - [Metric](#met)
  - [Scrape](#sc)
  - [Collector](#col)
- [Setting up Prometheus](#conf)

<a name=pro></a>
# Prometheus (Centralized Monitoring,Alerting & logging tool)
- This is central monitoring and logging system. This is designed as standalone and hence reliable system, so that when complete infra goes down, promethus should be up and can be used to diagnose the problem.
  - _1. Monitor & Alert:_ Monitors resources(High memory, CPU usage, latency etc) of servers on data center. Whenever any server's CPU goes high or latency increses it alerts admin about the same.
  - _2. Logging:_ store logs and sends [metrices](#met).
- DISADVANTAGE: Promethus is difficult to scale.
- Prometheus is Compatible with Docker and kubernets: Prometheus is fully compatible with both and is available as docker images.

<a name=us></a>
## Usage scenario
- Consider datacenter running [Kubernets cluster]() on several servers, K8s cluster is running applications inside containers(and each application has 5-10 threads/processes) and things are interconnected.
- App4 crashed making App8 to function inappropraitely and whole application becomes unavailable to user.
- How to identify which process in application crashed and Why it crashed?
  - Prometheus will store logs, which can be monitored using (Prometheus UI or Grafanna) to check the issue.

<a name=int></a>
## Internal Architecture
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
## [Prometheus Glossary](https://prometheus.io/docs/introduction/glossary/#collector)
<a name=tar></a>
### 1. Target
Identity which Prometheus can monitor is called target. Eg:
  - Linux/Windows server: Monitor CPU status, memory/disk usage
  - Single Application: Can monitor exception count, request count, response count
  - Service, DB
<a name=met></a>
### 2. Metrics
Data which is monitored for specific target is called metric. This data is generated by user application using [client library](#int), sent to prometheus using [exporter](#int) and [Retriever](#int) saves on DB.
```
//Example of metrics entry
http_requests_total
http_request_size_bytes
system_memory_used_bytes
node_network_receive_bytes_total

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
#### [Metric Types](https://prometheus.io/docs/concepts/metric_types/)
##### a. Gauge
- gauge is a metric that represents a single numerical value that can arbitrarily go up and down
- Eg:  temperatures, current memory usage

##### b. Counter
- Represents a single monotonically increasing counter whose value can only increase or be reset to zero on restart.
- NOTE: Do not use a counter to expose a value that can decrease. For example, do not use a counter for the number of currently running processes; instead use a gauge.

##### c. Histogram/Buckets
- histogram samples observations (usually things like request durations or response sizes) and counts them in configurable buckets

##### d. Summary
- Similar to histogram, it calculates configurable quantiles over a sliding time window.

<a name=sc></a>
### 3. Scrape
Pulling data from targets is called scraping. Prometheus will scrap the metric using http. [Target](#tar) should support `http://ip:port/metrics/` and provide metrics.
<a name=col></a>
### 4. Collector
A collector is a part of an [exporter](#hl) that represents a set of metrics. It may be a single metric if it is part of direct instrumentation, or many metrics if it is pulling metrics from another system.

<a name=lab></a>
### 5. Label
There is one problem in [metric](#met). if 2 targets(ie 2 machines) are scraped, and they produced same variable name, then how prometheus will identify the data differently for both server.
```c
  Prometheus
          -scrape-> machine-1
          <-mem_used=20-
          
          ------scrape---------> machine-2
          <-mem_used=80------------
 What's mem_used for machine-2?
```
**Solution: Labels**
- Labels in prometheus are arbitary.
```c
  Prometheus
          -----scrape----------------------------> Srv-1
          <-mem_used=20{instance="srv-1", service="a"}-
          
          -------------------scrape--------------------------------> Srv-2
          <-mem_used=80{instance="srv-2", service="b"}-------------------
```

<a name=conf></a>
## [Setting up Prometheus](https://www.youtube.com/watch?v=4WWW2ZLEg74)
```c
///////////Install and run prometheus/////////////
> on WSL
$ wget https://prometheus.io/download/prometheus-2.34.0.linux-amd64.tar.gz
$ tar -xvf prometheus-2.34.0.linux-amd64.tar.gz
$ cd prometheus-2.34.0.linux-amd64/
$ ./prometheus

////////////Configure Prometheus to scrape a datasource//////////
```
Who and what need to be [scraped](#sc) is defined inside prometheus.yml file and at what interval.
