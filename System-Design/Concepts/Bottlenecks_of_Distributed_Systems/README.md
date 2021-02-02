## Bottlenecks
### 1. Admission Control
  - **What?** Robust mechanism is needed to authenticate a node before allowing admission into distributed system. (using: kerberos)
  
### 2. Communication Control
  - **1. Rekey** Node should validate(at proper intervals) before communicating with another group member or intruder. (IKE rekey)
  - **2. Group Communication:** Node-1 should and cannot talk to other group to whom its not member of.
