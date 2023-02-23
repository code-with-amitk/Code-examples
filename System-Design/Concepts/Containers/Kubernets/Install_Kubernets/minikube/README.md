- Installation
  - [Ubuntu](#u)
  - [Windows](#w)
- [Install postgres on minikube](#ip)


### Installation
<a name=u></a>
#### Ubuntu 20.04
```c
# sudo -s
# cat /etc/os-release
NAME="Ubuntu"
VERSION="20.04.2 LTS (Focal Fossa)"

// Install kubectl
# sudo snap install kubectl --classic

// Install minikube
# sudo install minikube-linux-amd64 /usr/local/bin/minikube

// Install docker driver
# sudo apt-get install docker.io

// Start minikube
# minikube start --driver=docker --force
* Done! kubectl is now configured to use "minikube" cluster and "default" namespace by default

# kubectl get nodes
NAME       STATUS   ROLES           AGE     VERSION
minikube   Ready    control-plane   2m36s   v1.26.1

# minikube status
type: Control Plane
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
```

<a name=w></a>
#### Windows
```ps
//1. Run on powershell
New-Item -Path 'c:\' -Name 'minikube' -ItemType Directory -Force
Invoke-WebRequest -OutFile 'c:\minikube\minikube.exe' -Uri 'https://github.com/kubernetes/minikube/releases/latest/download/minikube-windows-amd64.exe' -UseBasicParsing

//2. Add the binary in to your PATH.
//Make sure to run PowerShell as Administrator.

$oldPath = [Environment]::GetEnvironmentVariable('Path', [EnvironmentVariableTarget]::Machine)
if ($oldPath.Split(';') -inotcontains 'C:\minikube'){ `
  [Environment]::SetEnvironmentVariable('Path', $('{0};C:\minikube' -f $oldPath), [EnvironmentVariableTarget]::Machine) `
}

cmd> minikube start
cmd> minikube kubectl -- get po -A
NAMESPACE              NAME                                        READY   STATUS    RESTARTS        AGE
kube-system            coredns-64897985d-hwhgc                     1/1     Running   0               2d17h
kube-system            etcd-minikube                               1/1     Running   0               2d17h
kube-system            kube-apiserver-minikube                     1/1     Running   10 (112m ago)   2d17h
kube-system            kube-controller-manager-minikube            1/1     Running   0               2d17h
kube-system            kube-proxy-6cq9t                            1/1     Running   0               2d17h
kube-system            kube-scheduler-minikube                     1/1     Running   0               2d17h
kube-system            storage-provisioner                         1/1     Running   19 (105m ago)   2d17h
kubernetes-dashboard   dashboard-metrics-scraper-58549894f-qwp9k   1/1     Running   0               2d17h
kubernetes-dashboard   kubernetes-dashboard-ccd587f44-9gdfz        1/1     Running   15 (106m ago)   2d17h

cmd> minikube status
minikube
type: Control Plane
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
```

<a name=ip></a>
### postgres on minikube
- https://itnext.io/basic-postgres-database-in-kubernetes-23c7834d91ef
- [helm install](/System-Design/Concepts/Containers/Kubernets/Helm-Chart/README.md#iu)
```c
# helm version
version.BuildInfo{Version:"v3.7.0", GitCommit:"eeac83883cb4014fe60267ec6373570374ce770b", GitTreeState:"clean", GoVersion:"go1.16.8"}

# helm repo add bitnami https://charts.bitnami.com/bitnami
"bitnami" has been added to your repositories

# helm install postgres bitnami/postgresql

# helm list
NAME            NAMESPACE       REVISION        UPDATED                                 STATUS          CHART                   APP VERSION
postgres        default         1               2023-02-15 17:52:37.484586898 +0530 IST deployed        postgresql-12.1.15      15.2.0 

// Validate postgres is running fine?
# helm get notes postgres
NOTES:
CHART NAME: postgresql
CHART VERSION: 12.1.15
APP VERSION: 15.2.0

** Please be patient while the chart is being deployed **

PostgreSQL can be accessed via port 5432 on the following DNS names from within your cluster:

    postgres-postgresql.default.svc.cluster.local - Read/Write connection

To get the password for "postgres" run:

    export POSTGRES_PASSWORD=$(kubectl get secret --namespace default postgres-postgresql -o jsonpath="{.data.postgres-password}" | base64 -d)

To connect to your database run the following command:

    kubectl run postgres-postgresql-client --rm --tty -i --restart='Never' --namespace default --image docker.io/bitnami/postgresql:15.2.0-debian-11-r0 --env="PGPASSWORD=$POSTGRES_PASSWORD" \
      --command -- psql --host postgres-postgresql -U postgres -d postgres -p 5432

    > NOTE: If you access the container using bash, make sure that you execute "/opt/bitnami/scripts/postgresql/entrypoint.sh /bin/bash" in order to avoid the error "psql: local user with ID 1001} does not exist"

To connect to your database from outside the cluster execute the following commands:

    kubectl port-forward --namespace default svc/postgres-postgresql 5432:5432 &
    PGPASSWORD="$POSTGRES_PASSWORD" psql --host 127.0.0.1 -U postgres -d postgres -p 5432

# kubectl get all -o wide
NAME                        READY   STATUS    RESTARTS   AGE    IP           NODE       NOMINATED NODE   READINESS GATES
pod/postgres-postgresql-0   1/1     Running   0          9m6s   10.244.0.3   minikube   <none>           <none>

NAME                             TYPE        CLUSTER-IP     EXTERNAL-IP   PORT(S)    AGE     SELECTOR
service/kubernetes               ClusterIP   <>             <none>        443/TCP    5h50m   <none>
service/postgres-postgresql      ClusterIP   <>             <none>        5432/TCP   9m6s    app.kubernetes.io/component=primary,app.kubernetes.io/instance=postgres,app.kubernetes.io/name=postgresql
service/postgres-postgresql-hl   ClusterIP   None           <none>        5432/TCP   9m6s    app.kubernetes.io/component=primary,app.kubernetes.io/instance=postgres,app.kubernetes.io/name=postgresql

NAME                                   READY   AGE    CONTAINERS   IMAGES
statefulset.apps/postgres-postgresql   1/1     9m6s   postgresql   docker.io/bitnami/postgresql:15.2.0-debian-11-r0
```
