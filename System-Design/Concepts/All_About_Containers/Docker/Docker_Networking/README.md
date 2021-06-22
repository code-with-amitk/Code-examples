## Docker Networking
- [What_is_Docker_Networking](#What_is_Docker_Networking)
- [Types_of_Docker_Networking](#Types_of_Docker_Networks)
  - [Bridge](#Bridge)
    - [User_defined_Bridge_and_Default_Bridge](#User_defined_Bridge_and_Default_Bridge)
    - [Default_Bridge_Configuration](#Default_Bridge_Configuration)
  - [Host_Networking](#Host_Networking)
  - [None_Networking](#None_Networking)


## What_is_Docker_Networking
- Connecting [Docker](../../Docker) [Containers](../../Containers) with each other and with outside world as well.
- Docker’s networking subsystem is pluggable using drivers forming networks.

## Types_of_Docker_Networking

|Network|Description|
|---|---|
|[1.Bridge](Bridge_Network)|.|
|2.Host|Use [Host Networking](Host_Networking) directly|
|3.Overlay|Containers running on **different Docker hosts** want to communicate OR when multiple applications work together using [swarm services]().|
|4.macvlan|Assign a MAC address to a container, making it appear as a physical device|
|[5.None](None_Networking)|disable all networking. This is not available for swarm services.|
|6.Network Plugins|integrate Docker with specialized network stacks/3rd party stacks.|

### Bridge
- This is default network driver. Used when multiple containers want to communicate on the **same Docker host**.
- Bridge in Docker This is software bridge which allows Containers on same host to communicate with each other.

#### User_defined_Bridge_and_Default_Bridge
- Default bridge is create by default, but its better to use user defined bridge.

||Default Bridge|User Defined Bridge|
|---|---|---|
|Connecting to other containers|Can only connect using IP Address|Can connect using hostnames|
|Isolation|Not better|provides a scoped network in which only containers attached to that network are able to communicate|

#### [Default_Bridge_Configuration](Bridge_Networking)
