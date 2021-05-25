## Storage Classes in C++
- **What?** Defines the scope/life time of variable/function within a program. 

||STATIC|EXTERN|REGISTER|AUTO|MUTABLE|
|---|---|---|---|---|---|
|Storage area|DS|DS,global|cpu registers|||
|Invalid operation|||getting address|||
|Lifetime|throughout program|throughout program|local to block|||
|Default value|0|cannot be init|garbage|||
