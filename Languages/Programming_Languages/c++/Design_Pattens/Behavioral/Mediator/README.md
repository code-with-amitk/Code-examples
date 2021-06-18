## Mediator Design Pattern
- **What?** The pattern restricts direct communications between the objects and forces them to collaborate only via a mediator object. 
- **Why?** If the objects interact with each other directly, the system components are tightly-coupled that makes higher maintainability cost and hard to extend.
- How?
```c
object-1               object-2
       \               /
        Mediator-Object
            |
         Object-3
```

### Applications
- [Online Auction](Online_Auction)
