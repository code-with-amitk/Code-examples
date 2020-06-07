## Command Pattern
- It encapsulates a request as an object.
- A abstraction exists between an object that invokes a command, and the object that performs it.
- Hence letting you parameterize other objects with different requests, queue or log requests, and support undoable operations.

### Components of Command DP
- Receiver — The Object that will receive and execute the command
- Invoker — Which will send the command to the receiver
- Command Object — Itself, which implements an execute, or action method, and contains all required information
- Client — The main application or module which is aware of the Receiver, Invoker and Commands

> It has been decided that a Client should not call it’s receiver directly, but via an abstraction layer.
