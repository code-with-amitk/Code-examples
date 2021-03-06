## Containers
- **What?** Isolated partition of OS holding only 1 Application and all its dependent libraries. Each container has its own: 
  - Network interface, its own IP address, its own file system, All containers share the kernel of the host.
- **Containerization?** Packaging software code and all its dependencies in a bundle.
- **[Advantages, Disadvantages of Containers](Advantages_Disadv_of_Containers.md)**
- **Issues without container?** When an company develops an S/W-Application, its tightly coupled with Libraries provided by particular OS Version. If OS update happens, libraries would get updated and Application may break, as it depends on particular OS version libraries.
- **[Containers vs VM](Container_vs_VM.md)**

<img src="https://image.slidesharecdn.com/dockerug-magnumandkolla-150628004034-lva1-app6892/95/openstacking-containers-13-638.jpg?cb=1435452205" width=500 />

## Image?
- Container is created from image. 
- An image describes everything that is needed to create a container; it is a template for containers.

## Registries?
- Images are stored in a registry
