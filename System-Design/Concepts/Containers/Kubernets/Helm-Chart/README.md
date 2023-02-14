**Helm Chart**
- [What is helm](#what)
- **Install/Upgrade/Rollback application on kubernets Cluster using helm chart**
  - [1. Create Helm Chart](#hc1)
  - [2. Download, Install minikube/Cluster](#hc2)
  - [3. Install application on cluster using helm](#hc3)
  - [4. Access the application on cluster](#hc4)

<a name=what></a>
## Helm Chart
- This is collection of yaml files/[jinja templates](/Languages/Templating_Language/Jinja2) used to install/upgrade service in [kubernets cluster](..).
- Format of helm chart
```c
mychart
|-- Chart.yaml
|-- charts
|-- templates
|   |-- NOTES.txt
|   |-- _helpers.tpl
|   |-- deployment.yaml
|   |-- ingress.yaml
|   `-- service.yaml
`-- values.yaml
```
### [Files inside Helm chart](Files_in_HelmChart)
```c
    chart.yaml.j2
    values.yaml.j2
    templates/configmap-jams.yaml
    templates/deployment.yaml
```

## Install/Upgrade/Rollback application on kubernets Cluster using helm
- **1. Login to kubernets cluster and check helm:**
```c
# which helm
/usr/local/bin/helm
```

- **2. Create helm chart**
```c
# helm create mychart     //This is helm chart for ngnix
Creating mychart

# cd mychart/
# ls -ltr
total 8
-rw-r--r--. 1 root root 1874 Feb 13 23:58 values.yaml
drwxr-xr-x. 3 root root  162 Feb 13 23:58 templates
-rw-r--r--. 1 root root 1143 Feb 13 23:58 Chart.yaml
drwxr-xr-x. 2 root root    6 Feb 13 23:58 charts
```

- **3. Run kubernets Cluster or [run minikube](../)**
```c
$ kubectl get nodes
NAME                                             STATUS   ROLES                  AGE   VERSION
nylab-vlan118-dhcp-set3-653.englab.juniper.net   Ready    control-plane,master   53d   v1.21.1
```

- **4. Install/Upgrade/Rollback application on kubernets cluster using helm**
```c
# helm install --dry-run --debug ./mychart --generate-name

$ helm install --dry-run --debug ./mychart --set service.internalPort=8080

$ helm upgrade app1{chartname}      //Upgrade the microservice instead of install
$ helm rollback app1{chartname}     //rollback to older version
$ helm delete --purge {chartname}   //Delete chart

$ helm install my-cherry-chart buildachart/ --values buildachart/values.yaml
NAME: my-cherry-chart
LAST DEPLOYED: Mon Mar  7 03:09:47 2022
NAMESPACE: default
STATUS: deployed
REVISION: 1
NOTES:
1. Get the application URL by running these commands:
  export NODE_PORT=$(kubectl get --namespace default -o jsonpath="{.spec.ports[0].nodePort}" services cherry-chart)
  export NODE_IP=$(kubectl get nodes --namespace default -o jsonpath="{.items[0].status.addresses[0].address}")
  echo http://$NODE_IP:$NODE_PORT
http://1.2.3.4:8888

//Check installation status
# helm history my-cherry-chart
REVISION        UPDATED                         STATUS          CHART                   APP VERSION     DESCRIPTION
1               Mon Mar  7 03:09:47 2022        deployed        buildachart-0.1.0       1.16.0          Install complete

# helm list --all
```

### 4. Access the application on cluster
```c
Open URL: http://1.2.3.4:8888
```
