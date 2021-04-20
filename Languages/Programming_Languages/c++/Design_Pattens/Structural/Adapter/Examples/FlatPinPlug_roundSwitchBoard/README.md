## Example-1
  - FlatPinPlug want to interact with roundSwitchBoard.
  - We need adapter in between.
** How it works?** Adapter will have pointer to object of target class.
```html

                Plug    //Abstract-class                switchBoard//Abstract Class
                /\ /\                                   /\      /\
                |   |                                   --      |
 ---------------    -------------------   ---------------       --------
|Genralization          Genralization |   |Aggregation                  |Genralization
|                                     |   |                             |
flatPinPlug                          Adapter                            flatSwitchBoard
```
- **[Code](Code)**
