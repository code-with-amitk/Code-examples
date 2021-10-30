- **Scrum Terms**
  - [1. Refactoring](#rf)
  - [2. Sprint](#sp)
  - [3. User Stories](#us)
  - [4. Epic](#ep)
  - [5. Task](#ta)
  - [6. Scrum Roles](#sr)
  - [7. Scrum Task Board](#st)
  - [8. Product Backlog, Sprint Backlog](#ps)
  - [9. Sprint Planning](#spl)
- **[Agile](#ag)**
  - [1. Agile Iterations](#ai)
  - [2. Burnout, Burnup, Burndown chart](#bc)
  - [3. Spike](#sp)
  - [4. Velocity](#v)
- **TDD, Test Driven Development**
  - [What](#tdd)

## Scrum
- Scrum is one of the most popular frameworks for implementing Agile. Scrum and agile are not same things.
- With scrum, the product is built in a series of fixed-length iterations called sprints that give teams a framework for shipping software on a regular cadence.

<a name=rf></a>
#### 1. Refactoring
To improve the performance or readability, the existing code is modified; this is re-factoring. During re-factoring the code functionality remains same.

<a name=sp></a>
#### 2. Sprint
This is basic unit of development.
- _Sprint starts with:_ a planning meeting, where the tasks for the sprint are identified and an estimated commitment for the sprint goal is made.
- _Sprint ends with:_ a review or retrospective meeting where the progress is reviewed and lessons for the next sprint are identified. During each sprint, the team creates finished portions of a product.

**Zero Sprint:** This is first step or pre-preparation step that comes just before the first sprint. It includes all activities such as setting a development environment, preparing backlog, etc.

<a name=us></a>
#### 3. User Stories
Features customers might want to see in their software. Typically no more than a couple days work, they form the basis of our Agile plans.
<a name=ta></a>
#### 4. Task 
User stories are broken down into different tasks.
<a name=ep></a>
#### 5. Epic 
A customer described software feature that is itemized in the product backlog is known as epic. Epics are sub-divided into stories.

<a name=sr></a>
#### 6. Scrum Roles
- **Product Owner** They are focused on understanding business and market requirements, then prioritizing the work to be done by the engineering team accordingly.
- **Scrum Master** They coach the team, the product owner, and the business on the scrum process and look for ways to fine-tune their practice of it.
- **Scrum Team** These are cross-functional teams. Includes developers, testers, designers, and ops engineers in addition to developers.

<a name=st></a>
#### 7. Scrum Task Board
- This is visual display of the progress of the Scrum team during a sprint. It presents a snapshot of the current sprint backlog allowing everyone to see which tasks remain to be started, which are in progress and which are done.
- Consider the following layout of the task board:
```c
Stories
To Do
In Progress
Testing
Done
```

<a name=ps></a>
#### 8. Product Backlog, Sprint Backlog
- **Product Backlog** is an ordered list of everything that is known to be needed in the product. It is the single source of requirements for any changes to be made to the product.
- **Sprint Backlog** is the set of Product Backlog items selected for the Sprint during the Sprint Planning, plus a plan for delivering the product Increment and realizing the Sprint Goal.

<a name=spl></a>
#### 9. Sprint Planning
 All work that needed to be done in Sprint is planned in Sprint Planning.
<a name=ag></a>
## Agile
- Agile is a time boxed, iterative approach(framework) for software delivery that builds software incrementally, instead of trying to deliver it all at once near the end.
- It works by breaking projects down into little bits of user functionality called [user stories](#us), prioritizing them, and then continuously delivering them in short two week cycles called **Agile iterations**.
- Agile refers to any process that aligns with the concepts of the Agile Manifesto.

<a name=ai></a>
#### 1. Agile iteration
- An Agile iteration is a short 1 to 2 week period where a team takes most important user stories, builds them completely and deliver as running-tested-software to the customer. Analysis, design, coding, testing happen during an iteration.

<a name=bc></a>
#### 2. Burnout, Burnup, Burndown chart
- **Burnout:** The burn-down chart shows the remaining work to complete before the timebox (iteration) ends.
- **Burnup:** It shows the progress of stories done over time
- **Burndown:** It shows how much work was left.

<a name=sp></a>
#### 3. Spike
This is too large and complex user story in software development that cannot be estimated until the development team runs a timeboxed investigation.

<a name=v></a>
#### 4. Velocity
- Velocity is a metric that is calculated by addition of all efforts estimates related with user stories completed in an iteration. 
- It mesures how much work Agile can complete in a [sprint](#sp) and how much time will it need to finish a project.

<a name=tdd></a>
## TDD, Test Driven Development
Developer:
- first writes an automated test case which describes new function or improvement and then creates small codes to pass that test, and
- Later re-factors the new code to meet the acceptable standards.
