### Home Theater
- **Problem** We have all components for creating a home theater: DvDPlayer, Tuner, Screen, CDPlayer, Projector, TheaterLights, PopcornPopper, Amplifier
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
- **Solution**
  - create a new class HomeTheaterFacade, which exposes a 2 simple methods such as `startHomeTheater(), stopHomeTheater()`
  - These 2 methods will call all the subsystem APIs internally and user Only have 2 buttons on Facade Remote:
    - SwitchOnHomeTheater
    - SwitchOffHomeTheater

![ImgURL](https://i.ibb.co/7pKbWGM/facade-dp.png)
