## Containers
- **What?** 
  - Isolated(Isolation is achieved using kernel namespace, [cgroups](/Operating_Systems/Linux/Resource_Control)) processes running on single host. Isolated from other processes.
  - Only 1 Application can run inside container and all its dependent libraries. Each container has its own: Network interface, its own IP address, its own file system, All containers share the kernel of the host.
  - *Issues without container?* 
    - When an company develops an S/W-Application, its tightly coupled with Libraries provided by particular OS Version. If OS update happens, libraries would get updated and Application may break, as it depends on particular OS version libraries.
- *Containerization?* Packaging software code and all its dependencies in a bundle.
- *[Advantages, Disadvantages of Containers](Advantages_Disadv_of_Containers.md)*
- *[Container Image?](../Docker/Docker_Images)* Container is created from image. Image describes everything that's needed to create a container; it is a template for containers.
- *[Container Registry?](../Docker/Registry)* Images are stored in a registries
- [Creating, Running Container and Running Application in Container](../Docker/InstallDocker_RunContainer)
- **[Containers vs VM](Container_vs_VM.md)**
- *[How Containers communicate with each other as well world: Docker Networking](/System-Design/Concepts/All_About_Containers/Docker)*

<img src=TraditionalOS_vs_Containers.jpg width=500 />
