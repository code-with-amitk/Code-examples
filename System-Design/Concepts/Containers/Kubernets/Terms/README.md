- [Ambassador API Gateway](#aagw)
- [Kubernets, Resource & Objects](#ko)
  - Types of k8 Resources
    - [ClusterRole](#cr)
    - ConfigMap
    - Deployment
    - Job
    - POD
    - RBAC
    - Services
    - Secrets
    - ServiceAccount
- [Namespace](#ns)
- [Nodeport](#np)

<a name=aagw></a>
## Ambassador API Gateway
- This is Kubernetes-native API Gateway for controlling and managing traffic between microservices within a Kubernetes cluster. Built on top of Envoy Proxy.
- It integrates with Kubernetes Service objects to route traffic to the appropriate microservices based on the service name and port.
- **Advatanges**
  - _1. Supports Multiple Protocols:_ HTTP/1.1, HTTP/2, WebSocket, gRPC, and OpenAPI/Swagger
  - _2. Other Functions:_ traffic splitting, load balancing, rate limiting, and authentication.

<a name=ko></a>
## [Kubernets Resources,Objects](https://kubernetes.io/docs/concepts/overview/working-with-objects/kubernetes-objects/)
- **Kubernets Resource = C++ Class** Resource is a blueprint for creating objects.
- **kubernets Object = C++ Object** is Instance created from resource(using yaml,json file), having behaviour, state, metadata, and configuration.

<a name=t></a>
## Types of k8 Resources/Objects
### 1. ClusterRole 
Defines set of permissions or access control rules for resources across an entire Kubernetes cluster. it applies to all namespaces in the cluster.
```yaml
$ test.yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRole
metadata:                       //Metadata of clusterRole
  name: my-cluster-role
  annotations:                  //Annotations: any number of key-value pairs, and can be used to provide additional context
    my-annotation: "example"
    namespace:     "test"
rules:
- apiGroups: [""]
  resources: ["pods"]
  verbs: ["get", "list", "watch"]

```

### [2. ConfigMap. kind: configmap](https://kubernetes.io/docs/concepts/configuration/configmap/#configmap-object)
- Object storing configuration of [POD](#ka)
- Unlike most Kubernetes objects(Eg: [Deployment](#dep) that have a spec), a ConfigMap has data and binaryData fields. Both the data field and the binaryData are optional
- A Kubernetes resource that stores configuration data in key-value pairs.
##### Creating a configmap
We can copy
```yaml
# cat test.properties
name=Amit
age=25
life=Great
worry=None

# kubectl create configmap amit-configmap --from-file=test.properties   //Create configmap

# kubectl get configmaps amit-configmap -o yaml                         //View configmap. 
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

### [3. Deployment](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)
Provide declrative updates for pods. A higher-level resource that manages the creation and scaling of replica sets, which in turn manage pods.
```yaml
//test.yaml
apiVersion: apps/v1       #(Required) Which version of the Kubernetes API you're using to create this object
kind: Deployment          #(Required) What kind of object you want to create
metadata:                 #(Required) Data that helps uniquely identify the object
  name: nginx-deployment
spec:                     #(Required) What state you desire for the object
  selector:
    matchLabels:
      app: nginx
  replicas: 2 # tells deployment to run 2 pods matching the template

$ kubectl apply -f test.yaml
```

### [4. Job](https://kubernetes.io/docs/concepts/workloads/controllers/job/)
This object runs a specific task to completion. will create 1 or more pods and execute continously until job completes.
```yaml
apiVersion: batch/v1
kind: Job
metadata:
  name: pi                #Name of Job
spec:
  template:
    spec:
      serviceAccountName: "Test"    // Name of ServiceAccount that should be used by the pod that is created to run the Job
      containers:                   //Container configuration for job
      - name: pi                    // Container name to be created by this Job
        image: perl:5.34.0
        env:                        //environment variables to set for the container.
          - name: DATABASE_HOST     //this env variable is set using a SecretKeyRef
            valueFrom:
              secretKeyRef:
                name: {{ .Release.Name }}-test-db
                key: host
      restartPolicy: Never
  backoffLimit: 4
```

### 4. POD
A basic unit of deployment in Kubernetes that runs one or more containers.

### [5. RBAC (Role-based Access Control)](https://kubernetes.io/docs/reference/access-authn-authz/rbac/)
- Roles are provided to indivisual users in organization. These roles actually defines access to computer(or n/w resource) in organization.
- We need to start apiserver with authorization-mode.
```c
$ kube-apiserver --authorization-mode=Example,RBAC --other-options --more-options
```
- The RBAC API declares 4 kinds of Kubernetes object:
  - _1. Role:_ define a role within a namespace
  - _2. ClusterRole:_ define a role clusterwise
  - _3. RoleBinding:_ grants the permissions defined in a role to a user or set of users
  - _4. ClusterRoleBinding:_

#### 1. Role
- Example: Role granting Read access to pods
```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  namespace: default
  name: pod-reader
rules:
- apiGroups: [""] # "" indicates the core API group
  resources: ["pods"]
  verbs: ["get", "watch", "list"]
```

#### 2. RoleBinding
- Grants the permissions defined in a role to Subjects. Subjects can be user or set of users.
- Example
  - user:jane can read pods in default namespace
```yml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: read-pods
  namespace: default
subjects:
- kind: User
  name: jane            #can read pods in default namespace
  apiGroup: rbac.authorization.k8s.io
roleRef:                                  # "roleRef" specifies the binding to a Role / ClusterRole
  kind: Role                              # this must be Role or ClusterRole
  name: pod-reader                        # You need to already have a Role named "pod-reader" in that namespace.
  apiGroup: rbac.authorization.k8s.io
```

### 6. ServiceAccount
A object that provides an identity for processes running inside a pod.

### 7. Services
- In Kubernetes, Service(or microservice) is logical set of Pods. Service exposes REST endpoints(eg: POST) & other services interact by calling these endpoints.
##### Service Object
- **What?** To define a logical set of Pods and a policy for accessing them.
- **What's present in Object?** _1. IP address/"cluster IP:_ Other services to access the this pod.
  - _0. apiVersion:_ The version of the Kubernetes API that is used to create the Service object.
    - Format: `group/version`. This is a REQUIRED field in all kubernets objects.
    - Version
      - apiVersion: v1    //refers to the core Kubernetes API
      - `apiVersion: ambassador/v1 & getambassador.io/v2`     //refer to custom APIs defined by the Ambassador API Gateway.Provide additional functionality specific to  [Ambassador API Gateway](#aagw).
  - _1. Name of service:_
  - _2.  selector:_ This is used to define the set of Pods that the Service will target. Selects Pods with the label "app=MyApp"
  - _3. Service Stable IP Address._ It also exposes port 80 on the Service's stable IP address
  - _4. targetport:_ Port 80 is mapped to port 8080 on the Pods
  - _5. type:_ Defines type of the Service, which can be ClusterIP, NodePort, LoadBalancer, or ExternalName.
    - _ClusterIP:_ Service which exposes a set of Pods internally to the cluster, using a stable IP address.
```yml
apiVersion: v1                              //0
kind: Service
metadata:
  name: {{ .Values.image.app }}-metrics     //1
spec:
  selector:
    app: MyApp                              //2
  ports:
    - name: http
      protocol: TCP
      port: 80                              //3
      targetPort: 8080                      //4
  type: LoadBalancer                        //5
```

### [8. Secrets](https://kubernetes.io/docs/concepts/configuration/secret/)
- Kubernets on AWS, Secrets is used to store sensitive information(Eg: passwords, API keys, and other credentials), that should not be exposed in plaintext within Kubernetes manifests or configuration files.
- *Why secrets object?* Secrets can be created independently of the Pods that use them, now there is no risk of the Secret data being exposed during the creating, viewing, and editing Pods
#### Creating Secrets
##### 1. Using Kubernetes command line interface (CLI) OR 
##### 2. Using the AWS Management Console. 
##### 3. Using yaml file
```c
// This yaml file stores sensitive data(eg: passwords or API keys), in an encrypted format within a Kubernetes cluster

kind: Secret
metaData:
  name: {{ $name }}           //will be replaced with a specific name at deployment time
  annotations:                    //Annotations that indicate these secret should be created before the installation of helm chart, and deleted after chart is uninstalled.
     "helm.sh/hook": pre-install
     "helm.sh/hook-weight": "-2"
     "helm.sh/hook-delete-policy": before-hook-creation
type: opaque                    //type of secret. Opaque means the data stored in the secret is an arbitrary byte array and the Secret does not have a predefined structure.
data:                           //key-value pairs of sensitive data that will be stored within the secret.
  host: {{ .Values.test.host | b464enc }}       //key=host, value=take from values.yaml and encoded in base64 format using the b64enc function
 
  {{ - $previous := {lookup = "v1" "Secret" .Release.Namespace $name }}   //key=password
  {{ - if .Values.identityDB.password }}                               
  password: {{ .Values.identityDB.password | b64enc }}           //if values is in values.yaml file store after encoding in base64 format using the b64enc function
{{ - end - }}
```
#### Access the secrets
##### 1. Mounted as a volume within a pod OR 
##### 2. Provided as environment variable inside container
a. Secret Created
```c
# k get -n namespace secret
jams_database

# k get -n namespace secret jams_database -o yaml   // contents inside secret
data:
 host: kaslknaldk
 name: 9u2ioihas019
 password: end823985
 user: 4062ksndjsdf92
 
# echo end823985 | base64 --decode                  // Decrypt content
test123    
```
b. Accessed using manifest by application
```yaml
templates/job-db-create.yaml
  - name: DB_PASSWORD
    valueFrom:
      secretKeyRef:
        name: {{ .Release.Name }}-database
        key: password
```

<a name=ns></a>
## Namespaces
- Namespace divides cluster into smaller units to isolate services,volumes and manage.
- Namespace contains pods.
- 3 predefined namespaces:
  - _a. Default_ 
  - _b. Kube-system:_ resources created by kubernets
  - _c. Kube-public:_ reserved for future
```c
$ kubectl create namespace test                       //Creating new namespace
$ kubectl --namespace=test  run ngnix --image=nginx   //Deploy namespace
```

<a name=np></a>
## Nodeport
- When we create a NodePort service in Kubernetes, Kubernetes will dynamically allocate a port (in the range of 30000-32767) for a Application running container. Eg:30001
- Then this port=30001 is mapped to targetPort=8080 internally.
- **Why NodePort?** 2 Applications can use same internal ports. Eg: App1 uses 8080 & App2 uses 8080. And with NodePort both can be accessed using external port without port change on application level.
```yaml
apiVersion: v1
kind: Service
metadata:
  name: jams-server         //Application using Nodeport. Kubernets will assign an IP=30001
spec:
  selector:
    app: my-app             //Run application on pods with Label = my-app
  type: NodePort
  ports:
    - protocol: TCP
      port: 80
      targetPort: 8080      //30001 is mapped to 8080 internally.

```
