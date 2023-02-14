**Files inside Helm Chart**
- [chart.yaml.j2](#c)
- [values.yaml.j2](#v)
- [templates/configmap-jams.yaml](#cm)
- [templates/deployment.yaml](#d)

## Files inside Helm Chart
<a name=c></a>
### chart.yaml.j2           //Contains meta information of this chart
```yaml
$ cat chart.yaml.j2
  version: 0.1.0          //Chart version
  appVersion: 1.16.0      //Version number of the application being deployed
  
  //chart is either Application or Library Chart.
  //Application: Collection of templates that can be packaged into versioned archives
  //Library: Provide useful utilities or functions for chart developer. Library charts do not define any templates and therefore cannot be deployed.
  type: application
  
  maintainers:
  - email: amit@google.com
    name: Amit
  name: jams 
```

<a name=v></a>
### values.yaml.j2          //Defines default values to be passed to templated files
- number of replicas
- repository for image
- database's username, password
- Other microservices URLs
- Kafka topics on which this service will listen
- autoscaling and resource limits
```yaml
$ cat values.yaml.j2

replicaCount: 1                                   //By default 1 pod will come up

image:                                            //image section tells from where image will be downloaded
  repository: nginx
  pullPolicy: Always
  
imagePullSecrets: []
nameOverride: "cherry-awesome-app"
fullnameOverride: "cherry-chart"

serviceAccount:                                   //Service to be run using this serviceAccount on pod.
 # Specifies whether a service account should be created
  create: true
  # Annotations to add to the service account
  annotations: {}
  # The name of the service account to use.
  # If not set and create is true, a name is generated using the fullname template
  Name: cherrybomb

podSecurityContext: {}
  # fsGroup: 2000

securityContext: {}
  # capabilities:
  #   drop:
  #   - ALL
  # readOnlyRootFilesystem: true
  # runAsNonRoot: true
  # runAsUser: 1000
  
service:                        //Networking options
  type: NodePort                //NodePort: informs all services in kubernets, that this service is listning on port=80
  port: 80

resources:                      //Maximum amount of resources a Helm chart can request
   limits:
     cpu: 100m
     memory: 128Mi
   requests:
     cpu: 100m
     memory: 128Mi
     
nodeSelector: {}            //Assign part of your application to specific node in your K8 cluster

tolerations: []             //Tolerations, tainting, and affinities work together to ensure that pods run on separate nodes

affinity: {}

database:
  enabled: true
  host: abc.db.com
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

<a name=cm></a>
### templates/configmap-jams.yaml                    
- Contains information related to configuration of this service. This is shared across all [PODS](#pod)
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

<a name=d></a>
### templates/deployment.yaml
- For deployment/instantiation of [pod](#pod). Remember 1 pod can have multiple containers. Each contianer=1Application
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
