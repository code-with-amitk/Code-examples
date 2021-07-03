- [1. Anti_Pattern](#Anti_Pattern)
- [2. Creational, Structural, Behavioral](#comp)
  - [2.1 Creational](#cre)
  - [2.2 Structural](#str)
  - [2.3 Behavioral](#beh)
- [3. Design Principles](#dp)

<a name=comp></a>
## 2. Creational, Structural, Behavioral

<a name=cre></a>
### 2.1 Creational
- Provides way for creating Objects, while hiding creation Logic. Types
  - Builder
  - Facade
  - Abstract Factory
  - Factory method/ Factory Pattern
  - Flyweight
  - Prototype
  - Proxy
  - Singleton
  - Visitor

<a name=str></a>
### 2.1 Structural
- How objects are composed? Is 1 object composed of other, is there inheritance relation etc? This is about structure. They Identify relationship between objects. Types:
  - Adapter/Wrapper
  - Bridge
  - Composite
  - Decorator
  - Filter/Criteria
  - Proxy

<a name=beh></a>
### 2.3 Behavioral
- Communication/Interaction with other classes/objects. Types
  - Chain of Responsibility
  - Command
  - Interpretor
  - Iterator
  - Observer
  - State
  - Strategy
  - Template
  - Visitor

<a name=dp></a>
## 3. Design Principles(CREATE DIFFERENT OBJECTS FOR MINUTE THINGS)
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
