## Kernel vs User Mode / Kernel Space vs User Space

||Kernel Mode|User Mode|
|---|---|---|
|What|Priviledged space, where priviledged application run. Has strong security/access checks|Non-priviledged mode, user application runs|
|Applications|Kernel runs here|Application runs in user space (Eg: shells, command line, GUI)|
|Access Method|Using system calls(400+) or H/W Interrupt||
|[Sizes on 1TB system]()|4 GB|966 GB|
