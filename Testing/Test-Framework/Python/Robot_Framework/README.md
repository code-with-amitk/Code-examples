**Robot Framework**
- [RF vs Pytest](#vs)
- [Architecture](#arc)
- [Test Cases](Test_Cases)
- [Terms: Test Libraries, Resource files, Variable Files](#t)

### Robot Framework
- RF is an open source framework which is mostly used for automation. This framework can also be used for robotic process Automation(RPA).
- Robot framework capabilities can be multiplied by hooking libraries written in (python, java, c++ & many other languages).
  - Kone(company) uses RF heavily for testing it's embedded systems which are used in elevators and escalators.

<a name=vs></a>
### [Robot Framework vs Pytest](https://www.fleekitsolutions.com/pytest-vs-robot-automation-testing/)
||RF|Pytest|
|---|---|---|
|Type of Tests|Acceptance Testing and Acceptance Test-Driven Development (ATDD)|Functional or API Testing|
|Technical Skills needed|low|comparatively high|
|Can test|Desktop applications, Web applications, Mobile applications, and SOAP-based services.||
|When?|If you are a beginner having less experience in the automation domain, go for RF|If you have a good programming skill and want to build complex automation, go for Pytest|

<a name=arc></a>
### [Architecture](https://robotframework.org/robotframework/latest/RobotFrameworkUserGuide.html#high-level-architecture)



<a name=t></a>
### Terms
In addition to test cases(test case file, test suite directory) there can be:
- **Test libraries:** containing the lowest-level keywords.
- **Resource files:** with variables and higher-level user keywords.
- **Variable files:** to provide more flexible ways to create variables than resource files.
