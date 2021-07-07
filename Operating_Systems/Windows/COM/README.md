- [1. What is COM](#com)
- [2. Players providing COM](#comp)

<a name=com></a>
## 1. COM / Component Object Model
- This is platform(or binary standard) for creating software components/Objects/COM Components those can interact with each other, satisfying below criterion.
  - Platform Independent: Object-1 can be on Linux, Object-2 on Windows.
  - Distributed: Interacting Objects can be far apart on internet and they can talk to each other as on 1 machine.
  - Encapsulation: Only provide abstract interfaces
  - Language Independent: Object-1(written in java) can interact with Object-2(written in c++).
  - Self Descriable: Object will expose a method, which tells what properties(variables) and methods it has.
  - Reusable: As Java exposes libraries and methods which can be reused, so it not about re-inventing the wheel.
- *Binary standard* a standard that applies after a program has been translated to binary machine code.

<a name=comp></a>
## 2. Players providing COM
- **A. Microsoft:** provides OLE, COM/DCOM, ActiveX, COM+. Same things but targetted towards different applications.
  - Java versions of these: OLE=>Javabeans, COM=>RMI(remote method invocation), ActiveX=>EJB
- **B. OMG(Object management group):** provides Corba(Common Object resource broker architecture), IIOP
