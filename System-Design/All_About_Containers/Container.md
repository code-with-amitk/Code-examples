## Containerization 
- Packaging software code and all its dependencies in a bundle.

## Containers
- **Advantages**
  - lightweight. All containers share same kernel but donot have any overhead over machine.
  - Reduces the chance that malicious code present in one container impacting other containers or invade the host system.
  - Abstract from host OS
  - Portable. abstraction from the host operating system makes containerized applications portable ie able to run on any OS,VM.
- **Containers vs VM**

|  | Containers | VM |
| --- | --- | --- | 
| size | Smaller | Bigger wrt containers |
| Capabiity | Smaller(uses smaller resources) | bigger |
| What | Pacakaged Software | Copy of OS |

- Each container runs inside docker host.
- This can be thought of as a VM inside base OS but this is not VM.

## Image?
- Container is created from image. 
- An image describes everything that is needed to create a container; it is a template for containers.

## Registries?
- Images are stored in a registry
