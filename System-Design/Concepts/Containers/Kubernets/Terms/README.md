- [Kubernets, Resource & Objects](#ko)
  - Types of k8 objects
    - [1. configmap. kind: configmap](#cm)
    - [2. deployment. kind: deployment](#dep)
    - [3. Job. kind: Job](#job)
    - [4. RBAC](#rbac)
    - [5. secrets. kind: secrets](#sec)
    - [6. service. kind: service](#ser)
- [Namespace](#ns)


## [Kubernets Resources,Objects](https://kubernetes.io/docs/concepts/overview/working-with-objects/kubernetes-objects/)
- **Kubernets Resource = C++ Class** Resource is a blueprint for creating objects.
- **kubernets Object = C++ Object** is Instance created from resource(using yaml,json file), having behaviour, state, metadata, and configuration.

### Types of k8 Resources
#### 1. POD
A basic unit of deployment in Kubernetes that runs one or more containers.

#### 2. Services
- In Kubernetes, Service/microservice = `logical set of Pods`.
- Application is not aware to which pod its communicating, even at t=1 and t=n number of pods serving application(s) need maybe different.
- Service exposes REST endpoints(eg: POST) & application interacts with service by calling these endpoints.
##### Defining a service object = service-object-amit1
  - Kubernetes will assign this Service a IP address/"cluster IP", which is used by the Service proxies
  - The controller will scans all Pods, those matching selector POST/REST Requests are sent to them.
```yml
apiVersion: v1
kind: Service
metadata:
  name: service-object-amit1
spec:
  selector:
    app.kubernetes.io/name: MyApp   //Every pod has this label
  ports:
    - protocol: TCP
      port: 80
      targetPort: 9376        //Every pod listens on this TCP port
```
#### 3. Deployment
A higher-level resource that manages the creation and scaling of replica sets, which in turn manage pods.
#### 4. [1. ConfigMap. kind: configmap](https://kubernetes.io/docs/concepts/configuration/configmap/#configmap-object)
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

#### [5. Secrets](https://kubernetes.io/docs/concepts/configuration/secret/)
- Object that contains a small amount of sensitive data such as a password, a token, or a key.
- The other way is to put this sensitive data into application using configmap, but using a Secret means that you don't need to include confidential data in your application code
- **Why secrets object?**
  - Secrets can be created independently of the Pods that use them, now there is no risk of the Secret data being exposed during the creating, viewing, and editing Pods
#### 6. ClusterRole 
Defines set of permissions or access control rules for resources across an entire Kubernetes cluster. it applies to all namespaces in the cluster.
#### [7. RBAC (Role-based Access Control)](https://kubernetes.io/docs/reference/access-authn-authz/rbac/)
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

##### 1. Role
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

##### 3. RoleBinding
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
#### 8. ServiceAccount
A resource that provides an identity for a pod or a set of pods to access other resources in the cluster.
#### [9. Deployment. kind: deployment](https://kubernetes.io/docs/concepts/workloads/controllers/deployment/)
Provide declrative updates for pods.
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
#### [11. Job, kind: Job](https://kubernetes.io/docs/concepts/workloads/controllers/job/)
- This object will create 1 or more pods and execute continously until job completes.
- **Job Completion:** As job successful completes. Deletion of Job happens and clean up the Pods.
- **Job suspention:** Suspending a Job will delete its active Pods until the Job is resumed again.
- **Example job:** computes π to 2000 places and prints it out.
```yaml
apiVersion: batch/v1
kind: Job
metadata:
  name: pi                #Name of Job
spec:
  template:
    spec:
      containers:
      - name: pi
        image: perl:5.34.0
        command: ["perl",  "-Mbignum=bpi", "-wle", "print bpi(2000)"]
      restartPolicy: Never
  backoffLimit: 4
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
