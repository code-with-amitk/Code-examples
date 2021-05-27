### int close(fd)
- Closes [both directions](/Networking/OSI-Layers/Layer-4/Protocols/TCP/State_Transition_Diagram/Tear_Down_Process) of data transfer. No reading, no writing.
- if server is recieving recv() and client calls close(), In TCP State diagram:
  - Client moved to [FIN_WAIT](/Networking/OSI-Layers/Layer-4/Protocols/TCP/State_Transition_Diagram) state.
  - Server moved to CLOSE_WAIT

