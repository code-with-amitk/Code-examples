**sidecar/istio**

### sidecar / istio / service mesh
- In kubernets istio (or service mesh) is advanced platform which provides networking, security capabilities to microservices.
- It places a seperate container (called sidecar or Envoy) inside the pod along side with existing application service.

#### Usage of sidecar / Envoy
- it acts as intermediary between microservice and rest of the system.
- Istio sidecar intercepts all communication between microservice and rest of services and provide routing, policy enforcement, telemetry, TLS to traffic
