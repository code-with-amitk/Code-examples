## Architecture of Distributed Systems
- **1. LAYERED:** Components are organized in a layered fashion making upcall/downcall. Eg: TCP-IP Stack
- **2. OBJECT BASED/SOA:** Each object/Node is connected using Procedure call mechanism. Client machine have proxy/stub application running which communicates with Server running on other machine.
- **3. RESOURCE-CENTERED/REST:** Node/Resource is identified by single naming scheme. All services provide same interface. Stateless, no state maintained.
- **4. EVENT-BASED/PUBLISH-SUBSCRIBE:** Process1 publishes a notification describing the occurrence of an event. Process2 subscribed to kind of notification gets the message.


<img src="https://i.ibb.co/GkVPV73/architecture-types-of-distributed-systems.png" width=1000 />
