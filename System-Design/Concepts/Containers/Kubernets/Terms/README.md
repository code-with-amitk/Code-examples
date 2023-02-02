- [Kubernets Objects](#ko)
  - Types of k8 objects
    - [1. deployment](#dep)
    - [2. configmap](#cm)
    - [3. service](#ser)
    - [4. RBAC](#rbac)

## [Kubernets Objects](https://kubernetes.io/docs/concepts/overview/working-with-objects/kubernetes-objects/)
A Kubernetes object always exist once we create them. k8 objects stores:
- Containerized applications configuration, Resources available to those applications, Policies of those applications(restart,upgrades etc)
### Types of k8 objects
<a name=dep></a>
#### 1. Deployment
Represent an application running on your cluster
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
<a name=cm></a>
#### [2. ConfigMap](https://kubernetes.io/docs/concepts/configuration/configmap/#configmap-object)
- Object storing configuration of [POD](#ka)
- Unlike most Kubernetes objects(Eg: [Deployment](#dep) that have a spec), a ConfigMap has data and binaryData fields. Both the data field and the binaryData are optional
#### Creating a configmap
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

<a name=ser></a>
#### 3. Services
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

<a name=rbac></a>
#### [4. RBAC (Role-based Access Control)](https://kubernetes.io/docs/reference/access-authn-authz/rbac/)
- Roles are provided to indivisual users in organization. These roles actually defines access to computer(or n/w resource) in organization.
- We need to start apiserver with authorization-mode.
```c
$ kube-apiserver --authorization-mode=Example,RBAC --other-options --more-options
```
- The RBAC API declares 4 kinds of Kubernetes object:
  - _1. Role:_ define a role within a namespace
  - _2. ClusterRole:_ define a role clusterwise
  - _3. RoleBinding:_
  - _4. ClusterRoleBinding:_

##### Role
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

