- **What is Creational DP?** Provides way for creating Objects, while hiding creation Logic.

|Name|What|Applications|
|---|---|---|
|[Builder](Builder)|Avoid Telescopic Constructor Anti-Pattern|Domino's/McD to create Children Meals:  Meal consists of {Main Item, side Item, Drink, Toy}|
|[Facade](Facade)||Consumer ordering from catalog|
|Abstract Factory|Creation of Super-Factory that creates other factories.||
|Factory method/ Factory Pattern|Creating object without calling object creation code.Localize Object creation code, prevent distribution of entire system|Toy Factory: In toy factory toys are made by injecting plastic into molds of desired shape.|
|Flyweight|To reduce number of Objects of created.  It uses already existing Objects and only creates new whenever no matching object is found|PSTN Network|
|Prototype|It creates Duplicate Objects{creates clone} while keeping Performance in Mind||
|Proxy|This class represents functionality of other class|Cheque or DD: These can be used in places of cash| 
|[Singleton](Singleton)|Only 1 instance/object of class can be created|<ul><li>Office of President</li></ul> <ul><li>Printer Queue(only 1 job run at a time)</li></ul> <ul><li>Only 1 DB object should be created per system & make connection, Duplicate connections may consume resources & slow down system</li></ul>|
|Visitor|Separation of Data Structures from Data||
