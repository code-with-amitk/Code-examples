## Advantages of Virtualization
  - *1.* For companies(like Amazon or Microsoft), which runs 1000s of servers(all different OS), installing seperate machine for every Task would eat their Pocket.
  - *2. Easy Migrations:* Migrating OS/application to VM is much easier wrt OS
  - *3.* Software development:* if programmer wants to check his application works on Windows 10, centos, mac etc. Installing all OS on 1 is easy instead of all on different machines.

## Disadvatages
- *1. Increased Memory usage:* Each VM requires seperate memory, book-keeping of how much memory and address assigned is additional overhead.
- *2. Processor Overhead:* Processor has to switch between VM's, increased process switching.
- *3. Performance Overhead:* VM cannot perform as same speed as standalone machine.
