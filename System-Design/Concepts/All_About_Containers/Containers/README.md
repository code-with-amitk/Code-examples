## Contiainers
- [What](#What)
- [Issues_Without_Containers](#Issues_Without_Containers)
- [Containerization](#Containerization)
- [Advantages_Disadv_of_Containers](#Advantages_Disadv_of_Containers)
- [Container_vs_VM](#Container_vs_VM)
- [Contianer_Related](#Contianer_Related)
  - [Contianer_Image](#Contianer_Image)
  - [Container_Registry](#Container_Registry)
  - [Create_Run_Container](#Create_Run_Container)
  - [How_Containers_Communicate_With_Each_Other](#How_Containers_Communicate_With_Each_Other)

### What 
  - Isolated(Isolation is achieved using kernel namespace, [cgroups](/Operating_Systems/Linux/Resource_Control)) processes running on single host. Isolated from other processes.
  - Only 1 Application can run inside container and all its dependent libraries. Each container has its own: Network interface, its own IP address, its own file system, All containers share the kernel of the host.

<img src=TraditionalOS_vs_Containers.jpg width=500 />

### Issues_without_Container 
  - When an company develops an S/W-Application, its tightly coupled with Libraries provided by particular OS Version. 
  - If OS update happens, libraries would get updated and Application may break, as it depends on particular OS version libraries.

### Containerization
  - Packaging software code and all its dependencies in a bundle.

### Advantages, Disadvantages of Containers
**Advantages**

- *1. lightweight* Use less memory. 
  - Simple web application running inside container takes 100MB space.
- *2. Secure:* Reduces the chance that malicious code present in one container impacting other containers or invade the host system.
- *3. Portable:* abstraction from the host operating system makes containerized applications portable ie able to run on any OS,VM.

**Disadvantages**

- Some application may not be suited for a containerized environment. Ex: applications accessing low-level hardware information.

### Container_vs_VM
|  | Containers | VM |
| --- | --- | --- | 
| size | Smaller | Bigger wrt containers |
| Capabiity | Smaller(uses smaller resources) | bigger |
| What | Pacakaged Software | Copy of OS |

- Each container runs inside [Docker](../Docker) host.
- This can be thought of as a VM inside base OS but this is not VM.

## Contianer_Related
### [Contianer_Image](../Docker/Docker_Images) 
- Container is created from image. Image describes everything that's needed to create a container; it is a template for containers.

### [Container_Registry](../Docker/Registry) 
- Images are stored in a registries

### Create_Run_Container
  - [Create and Run Container, Running Application in Container](../Docker/InstallDocker_RunContainer)

### [How_Containers_Communicate_With_Each_Other](/System-Design/Concepts/All_About_Containers/Docker)


