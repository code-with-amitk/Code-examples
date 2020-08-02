# Dev(developer), Ops(Operations or deployment)
- **How Metrics are measured**
  - **Dev teams** Amount of new changes they can deliver. This builds their reputation.
  - **Operations team** How stable software is in production.
    - But dont you think these are OPPOSITE. So, what happens? Dev team continually creates new features/changes/bug fixes and throws them over the wall to operations. The operations team perfects its best defense to prevent change.

# A1. Problem in Traditional development model(SDLC)
- Code Broke in Production!!
   - Dev(4 moths) --> testing(2 months) --> Production(Code Broke)**Why?** 
     - Because code bases running on prod and dev were hugely different. it might be no one's fault
     - Different tools, management models used by development-team and operations-team.

# A2. Solution(Devops) 
## What is Devops?
- Close these gaps by aligning approaches, tools.
- Bringing Agile approaches to all parts of the software delivery process.
- streaming feedback from production to development and improving the cycle time. (i.e., the time from inception to delivery)
- **Success of Devops** is in culture of trust b/w different depts, culture of sharing ideas, issues, processes, tools, and goals.
  - Development: Programmers do not code alone; rather, everyone helps them to understand what to code
  - Quality: Testers are not solely responsible for quality; rather, the whole team works together to maintain quality.
## Why Devops?
1. Deliver High quality software more quickly, which is more aligned with customer's requirements and basic conditions.

# B. Terms
- **Cyle Time** Amount of time required from the start of the development process to the beginning of revenue generation.
- **System Capacity** Maximum throughput system can sustain for a given workload while maintaining an acceptable response time.
- **DOD(Definition of Done)** No development job is finished until complete testing/depoyed on target systems, in a defined quality, monitoring is avaliable.
- **lead time** Amount of time between an input for a request to the system and the completion of that order
- **MTTR(Mean time to repair)** Time taken to resolve a system or network issue
- **MTTD(Mean time to detect)** Issue detection by the operations team.
- **Resilience** Ability of system to adjust itself during changes or disturbances, so that it can sustain required operations.
expected and unexpected conditions

# C. Devops Building Blocks/Fundamental of Devops
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
