- [1. Anti_Pattern](#Anti_Pattern)
- [2. Creational, Structural, Behavioral](#comp)
  - [2.1 Creational](#cre)
  - [2.2 Structural](#str)
  - [2.3 Behavioral](#beh)
- [3. Design Principles](#dp)

<a name=comp></a>
## 2. Creational, Structural, Behavioral

<a name=cre></a>
### [2.1 Creational](Creational)
- Provides way for creating Objects, while hiding creation Logic. Types
  - Builder
    - _1. Domino's/McD to create Children Meals:_ Meal consists of {Main Item, side Item, Drink, Toy}
  - Facade
  - Abstract Factory
  - Factory method/ Factory Pattern
    - _1. Toy Factory:_ In toy factory toys are made by injecting plastic into molds of desired shape.
    - _2. Pizza store_
    - _[3. Logistics Management](https://refactoring.guru/design-patterns/factory-method)_
  - Flyweight
    - _1. PSTN Network_
  - Prototype
  - Proxy
  - Singleton
    - _1. Office of President_
    - _2. Printer Queue(only 1 job run at a time)_
    - _3. Only 1 DB object_ should be created per system & make connection, Duplicate connections may consume resources & slow down system
  - Visitor

<a name=str></a>
### [2.2 Structural](Structural)
- How objects are composed? Is 1 object composed of other, is there inheritance relation etc? This is about structure. They Identify relationship between objects. Types:
  - Adapter/Wrapper
    - _1. Socket on Wall:_ Connecting new adapter to socket
  - Bridge
    - _1._ House hold switch for On/Off the light
  - Composite
    - Arithmetic Expressions evaluation: 2+3 and (2+3) + (4x6)
  - Decorator
    - _1. Coffee House Design_
  - Filter/Criteria
  - Proxy

<a name=beh></a>
### [2.3 Behavioral](Behavioral)
- Communication/Interaction with other classes/objects. Types
  - Chain of Responsibility
  - Command
  - Interpretor
  - Iterator.
    - _1. Musicians:_ They read musical notes for pitch of sound and duration
  - Mediator
    - _1._ Online Auction
    - _2._ Air traffic Control
  - Observer
  - State
    - _1. Vending Machine:_ it has states depending on inventory, amount of currency deposited, item selected etc
  - Strategy
    - _1. Modes of transport to Airport:_ Several options are present: Driving own car, taking taxi, City bus etc., Duck Behavior: 1st Example Head 1st Design Patterns
  - Template
  - Visitor

<a name=dp></a>
## 3. Design Principles(CREATE DIFFERENT OBJECTS FOR MINUTE THINGS)
> FIL: Favour Comp over Inheritance, Interface, Loose coupling
- _a._ Identify aspect of application that varies and separate it from what remains same.
- **b. Program to Interface:** Always create a base class(ie class containing Pure Virtual function) and override in derived classes. Even when you think there is no specific functionality for derv just create a wrapper.
- **c. Favor Composition(HAS-A) over Inheritance:** Composition/Aggregation can create objects dynamically(add new behavior) while Inheritance does static.
- _d._ Loose coupled designs is better.
- _e. Classes should be closed for modifications, but open for extensions._
  - Extension: Existing classes can be extended/coupled with any new behavior.
  - Modifications: Coders have spent day & night for making code bug free & fast. We cannot get code changes in existing now.
- _f. Principle of Least Knowledge_: Keep circle of friends small: Do not couple large number of classes together ie dependencies between classes should be minimum else change in 1 will break the code.
- _g._ Encapsulate what varies.
- _h. Manish_: Think yourself as Library developer. Library will expose getter,setter functions. All classes are independent. 3rd person is provided `*.so` and header file and he can use it.

### Applications
|Application|Design Pattern|
|---|---|
|Whether Display Device|Behavioural(Observer DP)|
|Online Auction System|Behavioural(Observer DP + Mediator DP)|
