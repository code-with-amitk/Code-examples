## CPU Fetch Execute Decode Cycle
- **What?**
  - Coder write, complie & object-code is stored on hard-disk. When program is to be executed, Object-code is copied to RAM. And instructions are placed contiguously on RAM.  
    CODER (z=x+y)test.c->Preprocessor>Complier>Assembler>Linker>a.exe  -copied-> HARD-DISK
    IP/PC is loaded with address of 1st instruction to executed, LOAD: ALU copies contents of RAM to Register,  STORE: ALU copies content of Register to RAM
# ./a.out  - instructions copied->                 RAM                                        <------               CPU        ------------>
                                                                                                                     Registers[IP         rbx]        ALU
                                                                                                                                 0x50
                                                                 LOAD rbx, $10      <-Read contents 0x50-        
                                                                 0x50
                                                                                                                                                 10
                                                                                                                                0x89
                                                                MUL rbx $14        <-Read 0x89-----------
                                                                                                                                                 140
