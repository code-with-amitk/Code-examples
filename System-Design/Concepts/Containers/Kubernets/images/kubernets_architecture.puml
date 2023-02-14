@startuml

package "Master Node" {
  [Controller]
  [Scheduler]
  [API_service]
  [etcd]
}

package "WORKER_NODE-1" {
  [Kubelet Kubectl_Proxy]
    package "POD" {
        frame "Container-2(docker)" {
            [Application-2, libs]
        }
        frame "Container-1(docker)" {
            [Application-1, libs]
        }
    }
}

package "WORKER_NODE-2" {
  [Kubelet Kubectl_Proxy]
    package "POD" { 
        
    }
}

[API_service] --> [Kubelet Kubectl_Proxy]

@enduml
