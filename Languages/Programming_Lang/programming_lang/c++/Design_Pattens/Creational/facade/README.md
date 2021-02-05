## Facade Design Pattern
- **What**
  - Facade Dictionary meaning? Deceptive outward appearance.
  - Provides a uniﬁed interface to a set of interfaces in system.
  - Facade deﬁnes a higher level interface that makes the subsystem easier to use.
  - Alters the existing complex interface and makes it simple to use.
  - if you need the power of the complex subsystem, it’s still there to use, but you need simple interface, facade is there.
  - You can create any number of facades for given system.
  
## EXAMPLE
### 1. HOME THEATER
  - **PROBLEM**
    - You have all components for creating a home theater
      - DvDPlayer, Tuner, Screen, CDPlayer, Projector, TheaterLights, PopcornPopper, Amplifier
    - Problem here is, if you want to enjoy home theater, these are tasks(methods) to be performed/called:
      - Turn on the popcorn popper Start the popper popping 
      - Dim the lights 
      - Put the screen down 
      - Turn the projector on
      - Turn the sound ampliﬁer on 
      - Set the ampliﬁer to DVD input
      - Start DVD.
      - ***So much of work needed to be done by myself***
        - Work here means method call. To build a home theater we need to call API for each work and that's cumbersome.
      - And when movie is over, all these steps again.
  - SOLUTION
    - create a new class HomeTheaterFacade, which exposes a 2 simple methods such as `startHomeTheater(), stopHomeTheater()`
    - These 2 methods will call all the subsystem APIs internally and user Only have 2 buttons on Facade Remote:
      - SwitchOnHomeTheater
      - SwitchOffHomeTheater

