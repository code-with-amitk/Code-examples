## Process States
- When a process executes, it passes through different states.
  - **a. Start:** Initial state when a process is first started/created.
  - **b. Ready:** The process is waiting to be assigned to a processor. 
  - **c. Running(Flag R):** Once the process has been assigned to a processor by the OS scheduler state changes to running.
  - **d. Waiting/Sleeping(Flag S):** Process moves into the waiting state if it needs to wait for a resource, eg: waiting for user input or file.
  - **e. Terminated or Exit:** Once the process finishes its execution, or it is terminated by the OS. Here it waits to be removed from main memory.
