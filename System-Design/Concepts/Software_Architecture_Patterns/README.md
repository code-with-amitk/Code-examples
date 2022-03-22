**Software Architecture / Software Design Pattern**
- [1. Layered Architecture / n-tier architecture pattern](#l)
- [Comparison of Architectures](#c)

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

#### Architecture sinkhole anti-pattern
- **What**
  - Situation where requests flow through multiple layers of architecture as simple pass-through processing with little or no logic performed within each layer.
  - Every layered architecture will have at least some scenarios that fall into the architecture sinkhole anti-pattern.
- **80-20 rule**
  - if around 20% of the requests as simple pass-through processing and 80% of the requests having some business logic associated with the request, then its ok.
  - if its reverse then you need to look at some other software design pattern.

<a name=c></a>
### Comparison of Architectures

|Metric|Agility(ability to respond quickly to a constantly changing environment)|Ease of deployment(One small change to a component can require a redeployment of the entire application)|Testability(To test 1 layer, other layers can be mocked or stubbed)|Performance()|Scalability|Ease of development|
|---|---|---|---|---|---|---|
|1.Layered Architecture|Low|Low|high|Low(Bcoz multiple layers need to be traversed)|Low(tightly coupled and monolithic implementation)|High(not overly complex to implement)|
