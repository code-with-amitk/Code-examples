
- [Installing Kubernets](Install_Kubernets)
- [Commands](#com)
  - [Connect to postgres pod](#cp) 


## [Kubernets](https://code-with-amitk.github.io/System_Design/Concepts/Kubernets/Architecture.html)
- Architecture

-- Master Node / Control Plane (Daemon in master node)

-- Worker Node(Daemon in Worker node)

* POD
  
<a name=com></a>
## Kubernets commands (kubectl -h)
```c
# kubectl cluster-info

//Get all namespaces on node
# kubectl get namespaces    
NAME              STATUS   AGE
default           Active   4d8h
keycloak          Active   3d22h
kube-node-lease   Active   4d8h
kube-public       Active   4d8h
kube-system       Active   4d8h
```
#### Services inside namespace
```c
# kubectl get services --namespace=default          
```

#### Pods
```c
# kubectl get pods --namespace=default          

// Detailed information of pod, image its running
# kubectl describe pod <pod-name> -n <namespace> | grep Image

// LOGS OF POD
# kubectl logs <pod-name> -n <namespace>

// Commands from inside the POD
$ kubectl exec -t pod-name -n namespace (echo $TEST //command)

// Connect to postgres pod
# k exec -it -n atom-generic-db patroni-0 -- sh
# ls /var
backups  cache  lib  local  lock  log  mail  opt  run  spool  tmp
# find / -name pg_hba.conf
/home/postgres/pgdata/pgroot/data/pg_hba.conf
```

#### Secrets
```c
// Lists all secrets stored in k8
# k get -n namespace secret
jams_database ..

// Contents inside secret
# k get -n namespace secret jams_database -o yaml
data:
 host: kaslknaldk
 name: 9u2ioihas019
 password: end823985
 user: 4062ksndjsdf92
 
 // Decrypt content
# echo end823985 | base64 --decode
test123                           // Plaintext Password
```

<a name=cp></a>
#### Connect to Postgres POD
```c
// Command shows notes provided by the chart of a named release
# helm get notes postgres

// Get postgres password to connect to postgres
# kubectl get secret --namespace default postgres-postgresql -o jsonpath="{.data.postgres-password}" | base64 -d
password

// Port on which postgres is running
# kubectl get svc -A | grep post

// Connect to postgresDB (username=postgres, password=taken from above, database=postgres)
// By default postgres listens on 5432
# kubectl run postgres-postgresql-client --rm --tty -i --restart='Never' --namespace default --image docker.io/bitnami/postgresql:15.2.0-debian-11-r0 --env="PGPASSWORD=<password>" --command -- psql --host postgres-postgresql -U postgres -d postgres -p 5432
postgres=#
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
