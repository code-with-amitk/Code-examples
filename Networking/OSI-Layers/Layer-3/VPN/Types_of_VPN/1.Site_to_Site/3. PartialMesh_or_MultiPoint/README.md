## Partial Mesh or MultiPoint VPN
- **What**
  - Combination of [Hub & Spoke](..) and [Full Mesh](..) VPN.
  - Some Branch offices have direct connection to each other while some does not
```html
BranchOffice-1 -----------------
    |                          \/
BranchOffice-2 ----------> Corporate-Office(Hub)
    |                          /\
BranchOffice-3 -----------------
```
- **Advatages**
  - *1. Branch offices can connect to Hub and also amonngt themseleves*
    - This is good for performance reasons since, some office may need to exchange heavy data and overload hub.
