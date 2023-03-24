- **Containers**
  - [Container vs VM](#vs)
  - [Run Application in Container](Run_Application_in_Container)
- [Docker](Docker)
- [Container Orchestration/Kubernets](Kubernets)


# Container
- **What?** 
  - This is a self contained package that contains everything that your binary/application need to run.
  - Only 1 Application can run inside container and all its dependent libraries. Each container has its own: Network interface, IP address, file system, All containers share the kernel of the host.

<img src=images/container.png width=1200 />

```c
    |-----------------------|
    | binary(*.exe),        |
    | runtime(tokio-1.2),   |
    | libraries(utc.so...), |
    | other packages        |
    |------Container--------|
```
- **Issues without containers?**
  - Applications is comprised of a language runtime, libraries(internal, _shared(eg: ibc and libssl)_), and your source code.
    - These external/shared libraries are shared components in the OS that you have installed on (/var/lib/..)
  - Problem occur when an application-1 developed have dependency on a shared library(libcv1) that isn’t available on production OS or different version is available(libcv2)
  - Also, multiple applications on a 1 machine require all programs to share same versions of shared libraries on production system, which makes application tightly coupled.
- **Containerization** means Packaging software code and all its dependencies in a bundle.
- **Isolated**(Isolation is achieved using kernel namespace, [cgroups](/Operating_Systems/Linux/Resource_Control)) processes running on single host. Isolated from other processes.

<img src=TraditionalOS_vs_Containers.jpg width=400/>

<a name=vs></a>
#### Container vs VM
```c
                 Container   |     VM
-----------|-----------------|--------------------  
size       |    smaller      | Bigger wrt container
capability |    smaller      | big
What       | Pacakaged s/w   | Copy of OS 
```

<a name=add></a>
**Advantages**
- *1. lightweight* Use less memory:* Simple web application running inside container takes 100MB space.
- *2. Secure:* Reduces the chance that malicious code present in one container impacting other containers or invade the host system.
- *3. Portable:* abstraction from the host operating system makes containerized applications portable ie able to run on any OS,VM.

**Disadvantages:** Some application may not be suited for a containerized environment. Ex: applications accessing low-level hardware information.



