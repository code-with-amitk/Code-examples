- **Continuous Integration**
  - [Practices in CI](#p)
- **Continious Delivery**
  - [Phases of CD](#p)
- **[Continious Delivery](#cdd)**
- [Blue, Green, Rolling Deployment](#bgr)

<a name=ci></a>
## Continuous Integration
- Developers checkin the code into a shared repository several times a day.
- Each check-in is then verified by an automated build, allowing teams to detect problems early.

<a name=p></a>
### Practices in CI
```c
1. Maintain a code repository                     >
2. Everyone commits to the baseline every day     >
3. Automate the build(self test)                  >
4. Test in a clone of the production environment  >
   Every commit (to baseline) should be built        
   Keep the build fast
5. Get latest deliverables(using artifacts) 
Automate deployment
```

<a name=cd></a>
## CD(Continious Delivery)
After CI, new changes are released to customers quickly in a sustainable way. Here software is continuously brought into production with the help of a continuous delivery pipeline.
- Automated testing is taken care in [CI](#ci)
- Automated release process and you can deploy your application at any point of time by clicking on a button, taken care in CD.

<a name=p></a>
### A. Phases of CD
```c
COMMIT --> TESTS --> BUILD --> PUSH_to_Aritifactory --> DEPLOYED
```
- _1. Commit:_ Code is commited to repository
- _2. Acceptance/Capacity/Load tests:_ Assure the correctness of the software regarding domain logic. 
  - _2a. Explorative tests:_ Examine new functionalities
- _3. Build:_ Build the code, ie produce a exe.
- _4. Push to Artifactory:_
- _5. Deploy to Prod Machine:_

<a name=cdd></a>
## Continuous Deployment
- This is 1 step further than [continuous delivery](#cd). 
- With this practice, every change that passes all stages of your production pipeline is released to your customers. 
- There's no human intervention, and only a failed test will prevent a new change to be deployed to production

<a name=bgr></a>
## Blue Green Deployment
- Technique for reducing downtime and risk by running two identical production environments called Blue and Green. 
- At any time, only one of the environments is live, with the live environment serving all production traffic. For this example, Blue is currently live and Green is idle.
- On One of enviornment new build is deployed tested, and when tests are good, Router is switched to make this as production env.

### Rolling Deployment
Unlike BG, We have only ONE complete environment. The code is deployed in the subset of instances of the same environment and moves to another subset after completion.
