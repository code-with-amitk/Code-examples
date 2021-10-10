**Devops / Dev(developer), Ops(Operations or deployment)**
- **Problems with Waterfall/Traditional development model**
  - [1. Code Broke in Production](#p1)
  - [2. Dev and Operations Teams are not aligned to common Goal](#p2)
- **Solution=devops**
  - **How to Achive devops**
    - [1. Agile Approach](#h1)
    - [2. Collective Feedback](#h2)
    - [3. Kanban](#h3)
- [Terms](#t)
- [Devops Building Blocks/Fundamental of Devops](#bb)

## Devops
Making development and operations(deployment) teams work together using some tools. Eg: 
- Agile
- Deploying smallers builds frequently to production servers.
- [kanban](Tools/Kanban.md)


## Problems with Waterfall/Traditional development model(SDLC)
<a name=p1></a>
#### 1. Code Broke in Production
Because code bases running on prod and dev were hugely different. Different tools, management models used by development-team and operations-team.
```
Dev(4 moths) --> testing(2 months) --> Production(Code Broke)
```

<a name=p2></a>
#### 2. Dev and Operations Teams are not aligned to common Goal
**How Metrics are measured**
- **Dev teams** Amount of new changes they can deliver. This builds their reputation.
- **Operations team** How stable software is in production.
- But dont you think these are OPPOSITE. So, what happens? Dev team continually creates new features/changes/bug fixes and throws them over the wall to operations. The operations team perfects its best defense to prevent change.

# Solution = Devops
- **Devops** is Close these gaps by aligning approaches, tools between dev & operations. 
- **Success of Devops** is in culture of trust b/w different depts, culture of sharing ideas, issues, processes, tools, and goals.
  - Development: Programmers do not code alone; rather, everyone helps them to understand what to code
  - Quality: Testers are not solely responsible for quality; rather, the whole team works together to maintain quality.
  - Shared Incentives: Performance bonus & incentives of each should depends on other dev and ops.
  - Area of Devops: How they can cooperate & work with each other. [See this Page](Area-Matrix.md)

## How to achieve devops
<a name=h1></a>
### [1. Agile Approach]()
Bringing Agile approaches to all parts of the software delivery process.
<a name=h2></a>
### 2. Collective Feedback
Streaming feedback from production to development and improving the cycle time. (i.e., the time from inception to delivery)
<a name=h3></a>
### 3. Kanban
Kanban method encourages continuous, incremental, and evolutionary changes to your current system. Supply is determined according to the actual demand, not according to some theoretical value.
**Kanban Theories**
  - **1. Theory of constraints (TOC)** A chain is no stronger than its weakest link. Means weakest items in the overall chain can cause failure or adversely affect the outcome.
  - **2. Kaizen** means continuous improvement.
**Kanban Properties**
- **1. Visualize the Workflow:** How work is done/related is inherently invisible. Visualizing the flow of work. Method: Use a sticker/card wall with cards and columns.
- **2. Limit WIP(work in progress):** Pull system is implemented on parts or all of the workflow. Each state in the workflow is limited.
- **3. Manage Flow:** flow of work through each state is monitored, measured, and reported.
- **4. Make Process Policies Explicit:** Process should be explained throughly to everyone to discuss problems & gain feedback.
- **5. Improve Collaboratively:** If teams have a shared understanding of theories about work, workflow, process, and risk they can solve problem more quickly.

**[kanban board](https://i.ibb.co/LkRwDQs/kanban-board.png):** Row1 is Expediate Lane. This is reserved for highly urgent items that must go live quickly.


<a name=t></a>
### Terms
- **Cyle Time** Amount of time required from the start of the development process to the beginning of revenue generation.
- **System Capacity** Maximum throughput system can sustain for a given workload while maintaining an acceptable response time.
- **DOD(Definition of Done)** No development job is finished until complete testing/depoyed on target systems, in a defined quality, monitoring is avaliable.
- **lead time** Amount of time between an input for a request to the system and the completion of that order.

- **Quality** Behavior of the software in production and the cycle time. Quality can’t be injected into the application post mortem.
  - **Types of Quality**
    - *a. Internal Quality* This is quality of the design and code. if internal quality is poor, the external quality will also suffer because application will raise an increasing number of bugs.
    - *b. External Quality* This is measured by what you see while using the application.
  - **How to improve Quality**
    - Quality code & design & Improve constantly and forever the system of production. Break down barriers between departments.
    - Pass all automated tests, continuous delivery(delivery pipeline, from development to production).
  - **Quality Gates:** A quality gate is a milestone during delivery where special quality requirements are checked. Quality gate is a potential bottleneck that delays features from being delivered to the customer.
  - **Tests Types**
    - _1. Unit Test:_ Test single class, no dependencies on other resources (e.g., databases), other subsystems, or other components. Can run unit tests in developer workspaces.
    - _2. Integration Test:_ 2 or more units/modules are integrated and tested. Should be  triggered on the build server only as takes long time.
    - _3. Exploratory test:_ To be performed by humans, Eg: testing UI.
    - _4. Service Test:_ These are integration tests which connect multiple components and test the system as a whole without touching the UI. 
    - _5. UI Testing:_ Tests the application, the middleware and the infrastructure.
    - _6. Smoke Test:_ Testing only main scenarios are available or not and whether the users can navigate through the happy paths (main scenarios).

- **MTTR(Mean time to repair)** Time taken to resolve a system or network issue
- **MTTD(Mean time to detect)** Issue detection by the operations team.
- **Resilience** Ability of system to adjust itself during changes or disturbances, so that it can sustain required operations expected and unexpected conditions.

<a name=bb></a>
### Devops Building Blocks/Fundamental of Devops
- **1. Reduce batch size** With reduced bat size, we can deploy more frequently.
- **2. Deploy Freequently, Deploy small**
   - Root causes of production incidents can be undersood quickly.
   - Errors detected easily code change is much smaller. 
- **3. Automatic Build,Test,Release** Creating release candidates automatically. This reduces risks of missing something during the release.
  - *What to automate?* Automatic Building, Automatic testing, Automatic release will increase efficiency.
  - *Why to automate?* To get fast feedback. Do not automate simply because you want to automate but it must result in concrete benefits. 
  - *Issues in Automation?* Compelte system cannot/should not be automated.
    - 1. If an automated system has an error, the full system is often completely unavailable
    - 2. Finding error in automated system is challending task, that cannot be performed by a novice engineer.
    - 3. Strong skills & experience is required to maintain/evelop the system.
- **4. Monitoring Application/UI** Monitoring app should be available with relaease itself, monitoring will check issues on software in production. It should be seen by everyone in team. Monitoring goes hand with `SMOKE TESTS`.
- **5. Decoupling Deployment & Release** This accelerates delivery. Release strategies:
  - *5a. Branch by Abstraction?* Do code change Branch by branch & bring to production.
    - 1. Create an abstraction over part of system that need to change. 
    - 2. Refactor the rest of the system to use the abstraction layer. 
    - 3. Continue coding; the abstraction layer delegates to the old or new code, as required. 
    - 4. Remove the old implementation.
    - 5. Once the old implementation has been completely replaced, remove the abstraction layer
  - *5b. Feature Toggle?* Deliver complete code to production but use data-driven switches to decide which feature is made available during runtime.
    - Advantage? Restore system to a baseline state when a deployment goes wrong.
  - *5c. Dark Launch/Beta Release?* Deploying 1st versions of functionality into production before releasing the functionality to all users.
  - *5d. Blue Green Deployment?* Deploy the version of the application side by side with the old version. Now 2 proudction enviornments are available. Router switch can used to switch between deployments. At any one time, one of them (e.g., the green environment) is live. This is combined with A/B TESTING.
    - *A/B Testing?* 2 versions of software are compared. To determine which version is better, experimentation with both versions are done simultaneously
- **6. Dev & Ops teams should be colocated**
  - Maybe next to each other's desk. 
  - Each should participate in other's Stand up meetings.
  - New ideas experiments, approaches should be encouraged.
