## Containers
- **What?** Isolated partition of OS holding only 1 Application and all its dependent libraries. Each container has its own network interface, its own IP address, its own file system. All containers share the kernel of the host.
- **Containerization?** Packaging software code and all its dependencies in a bundle.
- **Advantages**
  - lightweight. Use less memory.
  - *Secure:* Reduces the chance that malicious code present in one container impacting other containers or invade the host system.
  - *Portable:* abstraction from the host operating system makes containerized applications portable ie able to run on any OS,VM.
- **Disadv:** Some application may not be suited for a containerized environment. Ex: applications accessing low-level hardware information.  
- **Issues without container**
  - When an company develops an S/W-Application, its tightly coupled with Libraries provided by particular OS Version. If OS update happens, libraries would get updated and Application may break, as it depends on particular OS version libraries.
- **Containers vs VM**

|  | Containers | VM |
| --- | --- | --- | 
| size | Smaller | Bigger wrt containers |
| Capabiity | Smaller(uses smaller resources) | bigger |
| What | Pacakaged Software | Copy of OS |

- Each container runs inside docker host.
- This can be thought of as a VM inside base OS but this is not VM.

<img src="https://image.slidesharecdn.com/dockerug-magnumandkolla-150628004034-lva1-app6892/95/openstacking-containers-13-638.jpg?cb=1435452205" width=500 />

## Image?
- Container is created from image. 
- An image describes everything that is needed to create a container; it is a template for containers.

## Registries?
- Images are stored in a registry
