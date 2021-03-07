## Containers
- **What?** Another process on machine that's isolated from other processes. Only 1 Application can run container and all its dependent libraries. Each container has its own: 
  - Network interface, its own IP address, its own file system, All containers share the kernel of the host.
- **Containerization?** Packaging software code and all its dependencies in a bundle.
- **[Advantages, Disadvantages of Containers](Advantages_Disadv_of_Containers.md)**
- **Issues without container?** When an company develops an S/W-Application, its tightly coupled with Libraries provided by particular OS Version. If OS update happens, libraries would get updated and Application may break, as it depends on particular OS version libraries.
- **Container Image?** Container is created from image. An image describes everything that is needed to create a container; it is a template for containers.
- **Container Registry?** Images are stored in a registries
- **[Containers vs VM](Container_vs_VM.md)**

<img src=TraditionalOS_vs_Containers.jpg width=500 />
