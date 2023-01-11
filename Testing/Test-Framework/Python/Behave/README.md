**Behave**
- [How Behave works](#h)

### Behave / BDD(Behaviour-driven Development)
#### BDD?
- [Agile software development technique](System-Design/Concepts/Scrum/README.md#ag) that encourages collaboration between developers, QA and non-technical or business participants in a software project
- BDD focuses on obtaining a clear understanding of desired software behavior through discussion with stakeholders.
- It extends TDD by writing test cases in a natural language that non-programmers can read. 
- [BDD Practices](https://behave.readthedocs.io/en/stable/philosophy.html#bdd-practices)

<a name=h></a>
### How Behave works?
- We need to have below directory structure, where:
  - _1. feature file:_ contains Plain text(english) sentences filled by Non-Technical people(PLM or Project Manager).
    -  This file contains keywords (Feature, Scenario, Given, When, Then)
      -  Given: Pre-requisite
      -  When: take key actions the user (or external system) performs.
      -  Then: outcomes
  -  _2. steps directory:_ Contains actual test cases to be executed
    -  _2a. python file:_ Python file inside steps directory contains actual **tests which corresponds to keywords present in feature file**.
```c
Test
  |- mytest.feature
    |- steps
      |- mytest.py
```
<a name=e1></a>
#### Example-1
