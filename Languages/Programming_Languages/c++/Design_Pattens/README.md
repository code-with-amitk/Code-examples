- [Anti_Pattern](Anti_Pattern)
- **Creational, Structural, Behavioral**
  - [Creational: Creating Object](#c)
  - [Structural: How object is composed](#s)
  - [Behavioral: Communication b/w objects](#b)
- [Design Principles](#dp)

## Creational, Structural, Behavioral

<a name=c></a>
### [Creational](Creational)
Provides way for creating Objects, while hiding creation Logic. Types
```console
  DP                  Applications
Builder           Domino's/McD to create Children Meals
Facade
Abstract Factory
Factory method    1. Toy Factory: In toy factory toys are made by injecting plastic into molds of desired shape.
                  2. Pizza store
                  3. Logistics Management: (https://refactoring.guru/design-patterns/factory-method
Flyweight         PSTN Network
Prototype
Proxy
Singleton         1. Office of President
                  2. Printer Queue(only 1 job run at a time)_
                  3. Only 1 DB object should be created per system
Visitor
```

<a name=s></a>
### [Structural](Structural)
How objects are composed? Is 1 object composed of other, is there inheritance relation etc? This is about structure. They Identify relationship between objects. Types:
```console
Adapter/Wrapper       1. Socket on Wall: Connecting new adapter to socket
Bridge                1. House hold switch for On/Off the light
Composite             1. Arithmetic Expressions evaluation: 2+3 and (2+3) + (4x6)
Decorator             1. Coffee House Design
Filter/Criteria
Proxy
```

<a name=b></a>
### [Behavioral](Behavioral)
Communication/Interaction with other classes/objects. Types:
|DP|Applications|
|---|---|
|Chain of Responsibility|
|Command|1. Home automation system, using remote control|
|Interpretor||
|Iterator|1. Musicians: They read musical notes for pitch of sound and duration|
|Mediator|1. Online Auction 2. Air traffic Control|
|Observer||
|State|1. Vending Machine: Amount of currency deposited, item selected. State defined.|
|Strategy|1. Modes of transport to Airport: Several options are present: Driving own car, taking taxi, City bus etc., Duck Behavior: 1st Example Head 1st Design Patterns|
|Template|1. Beverage Maker Machine|
|Visitor||

<a name=dp></a>
## 3. Design Principles(CREATE DIFFERENT OBJECTS FOR MINUTE THINGS)
> FIL: Favour Comp over Inheritance, Interface, Loose coupling
- _a._ Identify aspect of application that varies and separate it from what remains same.
- **b. Program to Interface:** Always create a base class(ie class containing Pure Virtual function) and override in derived classes. Even when you think there is no specific functionality for derv just create a wrapper.
- **c. Favor Composition(HAS-A) over Inheritance:** Composition/Aggregation can create objects dynamically(add new behavior) while Inheritance does static.
- _d._ Loose coupled designs is better.
- _e. [Open-Closed SOLID Principle](/Languages/Programming_Languages/c++/OOPS_Principles)
- _f. Principle of Least Knowledge_: Keep circle of friends small: Do not couple large number of classes together ie dependencies between classes should be minimum else change in 1 will break the code.
- _g._ Encapsulate what varies.
- _h. Manish_: Think yourself as Library developer. Library will expose getter,setter functions. All classes are independent. 3rd person is provided `*.so` and header file and he can use it.

### Applications
|Application|Design Pattern|
|---|---|
|Whether Display Device|Behavioural(Observer DP)|
|Online Auction System|Behavioural(Observer DP + Mediator DP)|
