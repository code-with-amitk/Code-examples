**[Design Guidelines](#what)**
- [Separation of Concerns for Binary Projects](#soc)

## Design Guidelines
- Rust community has developed a process to to write well organized code

### Separation of Concerns for Binary Projects
- _When?_ Splitting the separate concerns of a binary program when main starts getting large.
- _Steps_
  - Split your program into a main.rs and a lib.rs and move your program’s logic to lib.rs.
  - main.rs should do 
    - Setting up any other configuration
    - Calling a run function in lib.rs. Handling the error if run returns an error
