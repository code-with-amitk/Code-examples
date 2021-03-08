## Disadvantages
- *1.* Host networking driver only work on linux not on Windows and MAC. 

## Advantages
- *1.* Expose 1 port and IP access the service. Example:
  - 50 Game servers are running in Docker containers on same hose. Requests are routed using [kubernets](/System-Design/Concepts/All_About_Containers/Container_Orchestration) to free game server.
