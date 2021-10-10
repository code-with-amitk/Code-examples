- [Continuous Integration](#ci)
- [Continious Delivery](#cd)
  - [Phases of CD](#p)

<a name=ci></a>
## Continuous Integration
This is development practice that requires:
- developers to integrate code into a shared repository several times a day.
- Each check-in is then verified by an automated build, allowing teams to detect problems early.

<a name=cd></a>
## CD(Continious Delivery)
A approach where software is continuously brought into production with the help of a continuous delivery pipeline.

<a name=p></a>
### A. Phases of CD
![ImgUrl](https://i.ibb.co/pjDPbK2/ms.png)

A1. Commit Phase
- software compilation, unit tests, and static code analysis

A2. Acceptance test Phase
- Assure the correctness of the software regarding domain logic.

A3. Capacity tests/Load Tests

A4. Explorative tests
  - Examine new functionalities
  
A5. Production Phase
  - Software bought in production
