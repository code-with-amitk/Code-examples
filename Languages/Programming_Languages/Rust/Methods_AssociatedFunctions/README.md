## Methods
- **What?** Methods makes structure/enum/trait object similar to classes, ie we can operate of struct data.
- Similar to [functions](..), Methods are:
  - Declared using `fn`
  - Return values
  - Takes parameter
- **Different from function:**
  - Methods are defined in a context([struct](..), enum or trait object)
  - 1st Parameter is always `self`, which is instance of the struct the method is being called on.
- **[Example Code](Code)**

## Associated Functions
- **What?** 
  - Defined inside impl block, But do not take self as argument
  - As name depicts, they are associated with functions.
- **Usage?** For returning object of type struct
- **[Example Code](Code)**
