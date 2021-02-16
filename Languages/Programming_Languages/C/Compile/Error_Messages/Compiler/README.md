## Compiler Errors

- **1. qmake command not found**
```c
# update-alternatives --install /usr/bin/qmake qmake /usr/bin/qmake-qt4 10
# update-alternatives --set qmake /usr/bin/qmake-qt4
```
- **2. <CL/opencl.h> no such file or directory**
```c
[CentOS]# yum install epel-release; yum provides '*/libOpenCL.so'; yum install ocl-icd-devel; yum install ocl*
[Ubuntu]# apt install --fix-broken -y; apt install opencl-headers -y
```
