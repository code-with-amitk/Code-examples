**Container Orchestration**
- [Kubernets](#Kub)
  - [Kubernets Architecture](#ka) 
    - [Master Node](#mn)
    - [Worker Node](#wn)
      - [Pod](#pod)
      - [Namespaces](#ns)
  - Kubernets Terms
    - [configmap](#cm)
  - [Configure kubernets Cluster](#cfgk)
  - [Helm Chart](#hc)
    - [1. chart.yaml.j2](#h1)
    - [2. Values.yaml.j2](#h2)
    - [3. templates/configmap-jams.yaml](#h3)
    - [4. templates/deployment.yaml](#h4)
  - [Commands](#kcmd)


## Container Orchestration
**Orhestration?** Managing the lifecycles of containers. These are GUI/tools to automate following tasks: Deployment, Scaling up/down, Movement of containers from one host to another, Load balancing, Health monitoring.
  - *Examples of Container Orhestrators:* Kubernets, Docker swarm, Nomad

<a name=kub></a>
# Kubernets
Cluster having different microservices inside it.
```c
  |--------------k8s cluster------------|
  | micro_service1      micro_service4  |
  |                                     |
  |   micro_service2                    |
  |                                     |
  |           micro_servicen            |
  |-------------------------------------|
```
<a name=ka></a>
## Kubernets Architecture
```c

User               |------MASTER_NODE--------|      |--------WORKER_NODE-1 -------|
   --*.yaml-->     |Controller  API_service <--------> Kubelet Kubectl_Proxy--------> Worker_Node-2
                   |                         |      |                  |------------> Worker_Node-3
                   |Scheduler     etcd       |      |                             |
                   |-------------------------|      |  |------POD---------------| |
                                                    |  | |-container1(docker)-| | |
                                                    |  | | Application-1,libs | | |
                                                    |  | |--------------------| | |
                                                    |  |                        | |
                                                    |  | |-container2(docker)-| | |
                                                    |  | | Application-1,libs | | |
                                                    |  | |--------------------| | |
                                                    |  |                        | |
                                                    |  |------------------------| |
                                                    |-----------------------------|
```
<a name=mn></a>
### A. Master Node
- User Intercts with Master node(using yaml file). Master node create/destroy worker nodes.
- **Daemon in master node**
  - *1. Controller Manager:* Monitors created containers/worker nodes. When worker node finishes the task(or load on cluster is low). VM/Worker node is bought down and when load becomes high a new worker node/VM is spawned again.
  - *2. API Service:* Manages all communication with Worker nodes(using kubelet)
  - _3. Scheduler:_ For placing pods across nodes to balance resource consumption.
  - 4. _etcd:_ Database that hosts cluster state information.

<a name=wn></a>
### B. Worker Node
- handles workload. Worker nodes hosts [PODS](#pod). 1 Pod can contain 1 or more [containers](#con).
- **Daemons in worker node:** *1. Kubelet:* Process for communication with master, *2. [Docker](#doc):* A container runtime, *3. Kube Proxy:* for communication with other nodes in cluster.

<a name=pod></a>
#### POD 
- Complete package which Kubernets creates to install application on Worker Node. Pod can contain multiple containers(application). Pods run in isolated pvt enviornment. Memory is allocated to Pods using [Volumes](/Operating_Systems/Linux/Partitions_Mounting).
- Pod Contains: 
  - *1.* Container(Eg: [Docker](#doc))
  - *2.* Shared storage, as Volumes
  - *3.* Networking, as a unique cluster IP address,port,  *4.* other Information 

<img src=kubernets_pod_worker_node.png width=600>

<a name=ns></a>
#### Namespaces
- Collection of pods ie Virtual clusters inside kubernets cluster. Multiple pods can run inside a namespace.
- 3 predefined namespaces:
  - _a. Default_ 
  - _b. Kube-system:_ resources created by kubernets
  - _c. Kube-public:_ reserved for future
```c
$ kubectl create namespace test                       //Creating new namespace
$ kubectl --namespace=test  run ngnix --image=nginx   //Deploy namespace
```

## Kubernets Terms
<a name=cm></a>
### Configmap
This is the configuration file that stores the configuration used by [POD](#ka)
#### Creating a configmap from File
```yaml
# cat test.properties
name=Amit
age=25
life=Great
worry=None

# kubectl create configmap amit-configmap --from-file=test.properties   //Create configmap
# kubectl get configmaps amit-configmap -o yaml                         //View configmap
apiVersion: v1
kind: ConfigMap
metadata:
  creationTimestamp: "2022-02-17T12:41:43Z"
  name: amit-configmap
  namespace: fs-central
  resourceVersion: "55390398"
  uid: 65e65104-d94c-4054-9359-16f5dc221b53
data:
  test.properties: |
    name=Amit
    age=25
    life=Great
    worry=None
```

<a name=cfgk></a>
## Configure kubernets Cluster(1 master, n workers)
#### a. Configuration file for deploying 2 containers. Containers having ngnix image.
```yaml
$ vim test.yaml
apiVersion: app/v1
kind: Development
metadata:
  name: nginx-deployment
  labels:
    app: nginx
sped:
  replicas: 3                       //Number of pods to be running at a time
  selector:
    matchlabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
      spec:
        containers:
        - name: nginx
          image: nginx:1.7.9
          ports:
          - containerPort: 80
```
#### b. Create container using kubectl command
```c
$ kubectl apply -f test.yaml
```
#### c. Install,start kubernets master, worker nodes
```c
$ install
$ minikube start                                            //Start minikube kubernets cluster
$ kubectl version
  Client Version: version.Info{Major:"1", Minor:"17"...}    //Worker node version
  Server Version: version.Info{Major:"1", Minor:"17",..}    //Master node version
$ kubectl get nodes                                         //How many nodes are in kubernetes cluster
NAME       STATUS   ROLES    AGE   VERSION
minikube   Ready    master   2m    v1.17.3
```
#### d. Deploy Application on cluster
```c
//Run command on Master Node. This will create Application=amit-app on any of available worker node/VM
$ kubectl create deployment amit-app --image=gcr.io/google-samples/kubernetes-bootcamp:v1
  deployment.apps/amit-app created

$ kubectl get deployments.apps 
NAME                  READY   UP-TO-DATE   AVAILABLE   AGE
amit-app              1/1     1            1           111s
kubernetes-bootcamp   1/1     1            1           3m19s
```
#### e. Check Pods and worker nodes
```c
$ kubectl get pods
$ kubectl describe pods
$ kubectl proxy                               //Note, pods run on pvt network hence proxy is needed to communicate with them.
$ systemctl start apache                      //Start Application inside container
```

<a name=ck1></a>
## Helm Chart
**What?** This is collection of yaml files/[jinja templates](/Languages/Templating_Language/Jinja2) for configuration,installation of A service in cluster. HC is used to install/upgrade service in cluster. Files in HC:
```c
jams/                       //Every chart will have same structure
  Chart.yaml.j2
  values.yaml.j2
  templates/                //These all templates will get values from Values.yaml.j2
    configmap-jams.yaml       
    deployment.yaml
    ...
```

<a name=h1></a>
#### 1. Chart.yaml.j2           //Contains meta information of this chart
```yaml
$ cat chart.yaml.j2
  version: 1.2      //Application version
  maintainers:
  - email: amit@google.com
    name: Amit
  name: jams
  type: application  
```

<a name=h2></a>
#### 2. Values.yaml.j2          //Defines default values to be passed to templated files
- number of replicas
- repository for image
- database's username, password
- Other microservices URLs
- Kafka topics on which this service will listen
- autoscaling and resource limits
```yaml
$ cat values.yaml.j2

replicas: 1

common:
  registry: github/amitkumar50

jams:
  name: jams-server

chart:
  name: jams

image:
  repository: github/amitkumar50/dir1/dir2/
  initRepository: github/amitkumar50/init/
  initTag: v1.0.0
  dbTag: {{ 1.2.3 }}

jamsVersion:
  imageTag: v1.2.3.141.333.444

database:
  enabled: true
  host: abc.db.com
  user: admin
  password: admin
  dialect: postgres
  sslmode: require
  maxOpenConn: 5
  
sled-DB:
  source: Sled
  enabled: false
  user: admin
  password: admin
  dialect: postgres
  sslmode: require
  maxOpenConn: 5

k8sServices:
  service1: https://service1:9091
  service2: https://service2.test2:9091

log:
  level: warning

Kallactar-API:
  name: collector
  port: 8001
  tls: true
  workers: 8

metrics-API:
  name: metrics
  port: 9009
  tls: false

healthcheck:
  path: /health
  port: 9009

certs:
  certFile:
    path: /etc/jams/certs
  privateKey:
    path: /etc/jams/pvt-keys

kafka:
  brokers: kafka.atom-message-bus:9092
  topics:
    - "topic1"
    - "topic2"

service_Monitor:
  name: jams-server-mon
  enabled: false
  interval: 30s
  timeout: 10s

resources:
  limits:
    memory: 32Gi
    #cpu: 4
  requests:
    memory: 8Gi
    #cpu: 2

autoscaling:
  enabled: false
  minReplicas: 1
  maxReplicas: 1
  targetCPUUtilizationPercentage: 80
```

<a name=h3></a>
#### 3. templates/configmap-jams.yaml                    
**What?** Contains information related to configuration of this service. This is shared across all [PODS](#pod)
- Templates are defined to pick values from [Values.yaml.j2](#h2).
```yaml
$ cat configmap-jams.yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: jams-config
  labels:
    app: {{ .Values.image.app }}            //Pick from Values.yaml.j2
data:
  test.yaml: |-
    servicename: jams
    pg_database_config:
      host: {{ .Values.database.host }}           //Pick from Values.yaml.j2
      user: {{ .Values.database.user }}           
      password: {{ .Values.database.password }}
      ssl_mode: {{ .Values.database.sslmode }}
    log_config:
      log_level: {{ .Values.log.level }}
      log_to_file: false
      rotate_keep: 20
      rotate_size_mb: 10
    servers:
      bat_query:
        params:
          workers: {{ .Values.batQueryAPI.workers }}
        server:
          host: 0.0.0.0
          port: {{ .Values.batchQueryAPI.port }}
          tls: {{ .Values.batchQueryAPI.tls }}
      cert_password: null
      lb_port: {{ .Values.API.lbPort }}
      lb_query_fqdn: {{ .Values.API.lbFqdn }}
      kafka_config:
        brokers: {{ .Values.kafka.brokers }}
        topics:
          {{- toYaml .Values.kafka.topics | nindent 10 }}

    service1_url: {{ .Values.k8sServices.service1Url }}
    service2_url: {{ .Values.k8sServices.service2Url }}
    version: 1.2.3

metadata:
  name: test
  labels:
    app: {{ .Values.image.app }}
```

<a name=h4></a>
#### 4. templates/deployment.yaml    
**What?** For deployment/instantiation of [pod](#pod). Remember 1 pod can have multiple containers. Each contianer=1Application
- Contains
  - Service account names
  - init containers
  - DB path username password
  - Ports for Http endpoints
  - [volume details](/System-Design/Concepts/All_About_Containers#sd)
```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: {{ .Values.image.app }}
  labels:
    app: {{ .Values.image.app }}

spec:
      serviceAccountName: {{ .Values.serviceAccount.name }}
      initContainers:
        - name: init
          image: "{{ .Values.common.registry }}{{ .Values.image.initRepository }}:{{ .Values.image.initTag }}"
          imagePullPolicy: {{ .Values.image.pullPolicy }}
          env:
            - name: DEPENDENCY_JOBS
              value: {{ .Release.Namespace }}:{{ .Release.Name }}-db-create-{{ .Values.image.dbTag }}
          command:
            - kubernetes-entrypoint
      containers:
        - name: {{ .Release.Name }}
          securityContext:
            {{- toYaml .Values.securityContext | nindent 12 }}
          image: {{ .Values.image.repository }}{{ .Values.image.folder }}/{{ .Values.image.imageLabel }}:{{ .Values.jamsVersion.imageTag }}
          imagePullPolicy: {{ .Values.image.pullPolicy }}
          env:
            - name: DATABASE_HOST
              valueFrom:
                secretKeyRef:
                  name: {{ .Release.Name }}-database
                  key: host
            - name: DATABASE_NAME
              valueFrom:
                secretKeyRef:
                  name: {{ .Release.Name }}-database
                  key: name
            - name: DATABASE_USER
              valueFrom:
                secretKeyRef:
                  name: {{ .Release.Name }}-database
                  key: user
            - name: DATABASE_PASSWORD
              valueFrom:
                secretKeyRef:
                  name: {{ .Release.Name }}-database
                  key: password
            - name: DATABASE_SSL_MODE
              valueFrom:
                secretKeyRef:
                  name: {{ .Release.Name }}-database
                  key: sslmode
          ports:
            - containerPort: {{ .Values.batQueryAPI.port }}
              protocol: TCP
              name: {{ .Values.batQueryAPI.name }}

          volumeMounts:
            - name: jams-cfg-vol
              mountPath: /etc/jams/config

      volumes:
        - name: jams-cfg-vol
          configMap:
            name: jams-config
```

### Install/upgrade/rollback application using helm chart_
```c
$ helm install app1{chartname}
$ helm upgrade app1{chartname}      //Upgrade the microservice instead of install
$ helm rollback app1{chartname}     //rollback to older version
```

<a name=kcmd></a>
### Kubernets commands (kubectl -h)
<a name=ser></a>
#### Services
```c
//ssh to kubernets VM running microservices
# kubectl get svc -A                        //List all services on this VM
$ kubectl get service --all-namespaces      //IP Addresses of all services in cluster in all namespaces
NAMESPACE     NAME                       TYPE        CLUSTER-IP      EXTERNAL-IP   PORT(S)         AGE
default       kubernetes                 ClusterIP   10.32.0.1       <none>        443/TCP         6d
kube-system   csi-attacher-doplugin      ClusterIP   10.32.159.128   <none>        12345/TCP       6d
kube-system   csi-provisioner-doplugin   ClusterIP   10.32.61.61     <none>        12345/TCP       6d
kube-system   kube-dns                   ClusterIP   10.32.0.10      <none>        53/UDP,53/TCP   6d
kube-system   kubernetes-dashboard       ClusterIP   10.32.226.209   <none>        443/TCP 
$ kubectl -n name_space get service         //Get all services within namespace
```
<a name=pc></a>
#### Pods
```c
$ kubectl get pods -A                             //List all pods
NAMESPACE               POD-NAME                  READY   STATUS      RESTARTS   AGE
nsa                     pod1                      1/1     Running     0          48d      //2 pods in namespace=nsa
nsa                     pod2                      0/2     Completed   0          7d3h
nsb                     pod1                      0/2     Completed   0          7d3h
nsb                     pod2                      0/2     Completed   0          7d3h

$ kubectl get pods -A | grep kafka                //All pods named kafka*
Namespace              Pod-name         READY   STATUS      RESTARTS   AGE
n1                      kafka-0         2/2     Running     0          38d
n1                      kafka-1         2/2     Running     0          38d
n1                      kafka-2         2/2     Running     0          38d

$ kubectl -n namespace get pods                 //All pods in namespace

//////////Commands from inside the POD//////////////
$ kubectl exec -it testing{pod_name} -n namespace /bin/bash   //Go inside POD

root@testing:/opt/# ping namespace.service_name               //Pinging service

```
<a name=lc></a>
#### Logs of Container in Pod
```c
$ kubectl logs -h                             //Print the logs for a container in a pod

$ kubectl get pods -A | grep kafka            //Get All pods named kafka*
namespace               pods
ns1                     kafka-a     2/2     Running     0          46d
ns1                     kafka-b     2/2     Running     0          46d
ns1                     kafka-c     2/2     Running     0          46d

$ kubectl logs kafka-c -n ns1                 //In pod kafka-c, 3 containers are running.
error: a container name must be specified for pod kafka-c, choose one of: [prometheus-jmx-exporter kafka-broker]

//Get logs of container kafka-broker
$ kubectl logs kafka-2 -n ns1 kafka-broker> t.txt    //kubectl logs podname namespace containerName

//Live tail
$ kubectl logs kafka-2 -n ns1 kafka-broker --follow
```
