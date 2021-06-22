## Docker Networking
- [What_is_Docker_Networking](#What_is_Docker_Networking)
- [Types_of_Docker_Networking](#Types_of_Docker_Networks)


## What_is_Docker_Networking
- Connecting [Docker](../../Docker) [Containers](../../Containers) with each other and with outside world as well.
- Docker’s networking subsystem is pluggable using drivers forming networks.

## Types_of_Docker_Networking

|Network|Description|
|---|---|
|[1.Bridge](Bridge_Network)|default network driver|
|2.Host|Use [Host Networking](Host_Networking) directly|
|3.Overlay|Containers running on **different Docker hosts** want to communicate OR when multiple applications work together using [swarm services]().|
|4.macvlan|Assign a MAC address to a container, making it appear as a physical device|
|[5.None](None_Networking)|disable all networking. This is not available for swarm services.|
|6.Network Plugins|integrate Docker with specialized network stacks/3rd party stacks.|
