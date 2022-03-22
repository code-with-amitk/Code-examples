**Software Architecture**
- [1. Layered Architecture / n-tier architecture pattern](#l)

## Software Architectures
<a name=l></a>
### 1. Layered Architecture / n-tier architecture pattern
- Components are organized into layers, each layer performing a specific role within the application.
- **Seperation of Concerns:** Components within a specific layer deal only with logic that pertains to that layer.
- **Closed layers** means that as a request moves from layer to layer. For example, a request originating from the presentation layer must first go through the business layer and then to the persistence layer before finally hitting the database layer. 
  - **Open Layer:** There might be times when we want to add a layer accessible to all the layers(Eg: Logging).
- Although the layered architecture pattern does not specify the number and types of layers but most layered architectures consist of 4 standard layers:

|Layer|Responsiblity|
|---|---|
|1. Presentation|Handle all user interface and browser communication logic|
|2. Business|Execute specific business rules associated with the request|
|3. Persistance|For creating DB queries, updating the Databases|
|4. Database|For storing db|

<img src=layered_arch.PNG width=400 />

#### 
