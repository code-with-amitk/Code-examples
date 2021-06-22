## Bridge Networking
- [What](#What)
- [Types_of_Bridge_Networking](#Types_of_Bridge_Networking)
-     - [User_defined_Bridge_and_Default_Bridge](#User_defined_Bridge_and_Default_Bridge)
    - [Default_Bridge_Configuration](#Default_Bridge_Configuration)

### What
- This is default network driver. Used when multiple containers want to communicate on the **same Docker host**.
- Bridge in Docker This is software bridge which allows Containers on same host to communicate with each other.

### Types_of_Bridge_Networking
#### 1. User Defined Bridge
- Can only connect using IP Address or hostname
- Isolation: provides a scoped network in which only containers attached to that network are able to communicate

#### 2. Default Bridge
- This is created by default, but its better to use user defined bridge.
- Can only connect using IP Address.
- Isolation is not better.
- **Configuration Example](Examples/Default_Bridge):** Run 2 different Alpine containers on same docker host and commmunicate between them.
