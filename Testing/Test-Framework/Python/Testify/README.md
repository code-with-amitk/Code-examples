**Testify**
- [Testify vs unittest](#vs)
- [Installation](#i)

### [Testify](https://github.com/Yelp/Testify)
Testify is a replacement for Python's unittest module and nose. It is modeled after unittest, and existing unittest classes are fully supported.

<a name=vs></a>
#### [Testify vs unittest](https://github.com/Yelp/Testify)
||Testify|unittest|
|---|---|---|
|1. setup and teardown fixture methods|class-level|yes||
|2. Enhanced test discovery|yes, similar to nose||
|3. Pretty test runner output|y||
|4. Extensible plugin system for adding additional functionality around reporting|y||
|5. Have other handy testing utilities, including turtle (for mocking), code coverage integration|y||

<a name=i></a>
### Installation
```c
> pip install testify
Collecting testify
  Downloading testify-0.11.0-py2.py3-none-any.whl (55 kB)
     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 55.9/55.9 kB 1.5 MB/s eta 0:00:00
Requirement already satisfied: six>=1.7.3 in c:\users\amitk\appdata\local\programs\python\python310\lib\site-packages (from 
testify) (1.16.0)
```
