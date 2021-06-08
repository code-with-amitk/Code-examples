## Hub & Spoke
- **What?**
  - Many company networks have 1 corporate office with many branch offices.
  - If branch office need to access the resource, they connect to corporate office.
```html
BranchOffice-1(SPOKE) ---------------
                                    \/
BranchOffice-2(SPOKE) --------> CorporateOffice(HUB)
                                    /\
BranchOffice-3(SPOKE) ---------------
```
- **Disadvantages?**
  - *1. Overloaded Hub resulting in lag, [Latency](/System-Design/Concepts/Terms) Issues* 
    - If Spoke=branchOffice-1 want to connect to Spoke=BranchOffice-2 it need to go thru Hub.
    - Big issue for applications eg: VoIP, Video Confrencing
