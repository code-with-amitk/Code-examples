**Helm Chart**
- [Files inside helm chart](#fi)
- [Install/Upgrade/Rollback application using helm](#iu)

## Helm Chart
- This is collection of yaml files/[jinja templates](/Languages/Templating_Language/Jinja2) used to install/upgrade service in [kubernets cluster](..).
- When a chart is installed, Helm generates Kubernetes objects based on the templates and deploys them to the cluster
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
<a name=fi></a>
### [Files inside Helm chart](Files_in_HelmChart)
```c
    chart.yaml.j2
    values.yaml.j2
    templates/configmap-jams.yaml
    templates/deployment.yaml
```

<a name=iu></a>
### Install/Upgrade/Rollback application using helm
#### 1. Login to kubernets cluster
```c
# which helm
/usr/local/bin/helm
```

#### 2. helm create
- Create helm chart
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

#### 3. `helm install [RELEASE_NAME] [CHART] [flags]`
- Install/Upgrade/Rollback application in 1 or more containers(inside PODS)
  - How many containers/PODS to be created depends on manifest files 
  - present inside templates/yaml files. How many replicas to run etc 
- `[CHART]` Downloads the Helm chart package from a remote or local repository, unpacks it.
- Generates a set of Kubernetes objects and deploys them to the target cluster.
```c
# helm install --dry-run --debug ./mychart --generate-name  --set service.internalPort=8089

$ helm upgrade app1{chartname}      //Upgrade the microservice instead of install
$ helm rollback app1{chartname}     //rollback to older version
$ helm delete --purge {chartname}   //Delete chart


1. Get the application URL by running these commands:
  export NODE_PORT=$(kubectl get --namespace default -o jsonpath="{.spec.ports[0].nodePort}" services cherry-chart)
  export NODE_IP=$(kubectl get nodes --namespace default -o jsonpath="{.items[0].status.addresses[0].address}")
  echo http://$NODE_IP:$NODE_PORT
http://1.2.3.4:8888
```

#### 4. Check installation status
a. helm list
```c
# helm list --all
```
b. helm history
```c
# helm history mychart
REVISION        UPDATED                         STATUS          CHART                   APP VERSION     DESCRIPTION
1               Mon Mar  7 03:09:47 2022        deployed        buildachart-0.1.0       1.16.0          Install complete
```

#### 5. Access the application on cluster
```c
Open URL: http://1.2.3.4:8888
```
