## Quality
- **What** 
  - Behavior of the software in production and the cycle time.
  -  Quality can’t be injected into the application post mortem.
- **Quality Types**
  - *a. Internal Quality* This is quality of the design and code.
    -  if internal quality is poor, the external quality will also suffer because application will raise an increasing number of bugs.
  - *b. External Quality* This is measured by what you see while using the application.
- **How to improve Quality**
  - Quality code & design & Improve constantly and forever the system of production.
  - Break down barriers between departments.
  - Pass all automated tests, continuous delivery(delivery pipeline, from development to production).
- **Quality Gates**
  -  A quality gate is a milestone during delivery where special quality requirements are checked. Quality gate is a potential bottleneck that delays features from being delivered to the customer.
  
## Tests Types
### 1. Unit Test
- Test single class, no dependencies on other resources (e.g., databases), other subsystems, or other components. Can run unit tests in developer workspaces.
### 2. Integration Test
- 2 or more units/modules are integrated and tested. Should be  triggered on the build server only as takes long time.
### 3. Exploratory test
- To be performed by humans, Eg: testing UI.
### 4. Service Test
- These are integration tests which connect multiple components and test the system as a whole without touching the UI. 
### 5. UI Testing 
- Tests the application, the middleware and the infrastructure.
### 6. Smoke Test
- Testing only main scenarios are available or not and whether the users can navigate through the happy paths (main scenarios).
