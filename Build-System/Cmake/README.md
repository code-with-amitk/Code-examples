## Cmake
- **What** Cmake is NOT a build system but build-system generator. It generates `Makefiles` which can be used for compile the project.
- **Features** cross-platform, open-source, compiler-independent method.

### Steps of Building with cmake
  - **1. Create CMakeList.txt**
    - *1a.* Set CMAKE version number
    - *1b.* Set project-name and project version number(project-name=SUM)
    - *1c.* Set executable name and cpp files.  (EXECUTABLE CPP-FILES)
    - *1d.* Header file
    - *1e.* Set search path for include files.
  - **2. Create header file**
  - **3. Create source code file**
  - **4. Create Build directory and go in**
  - **5. Run cmake from inside of build directory**
  - **6. Make the code using Makefile**
  - **7. Run executable**
