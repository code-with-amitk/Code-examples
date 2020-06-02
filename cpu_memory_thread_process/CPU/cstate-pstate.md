## P-State?
 - These are frequency & voltage operating points.
 - High Frequency means
    - high CPU I/O Rate means
      - High Processor performance means
        - high battery consumption
 - if we Reduce frequency to 1/2
  - CPU I/O Rate is reduced to 1/2 
    - performance 1/2ed and
      - less battery consumption

## Power consumption
P ~ f V²	//f=frequency, V=voltage

## Processor states:
### C-State(power down state): 
State in which CPU is at idle, powered down.
#### Types of C-States
- CC-States(Core C states): 1 CPU have multipe cores. This is C state of core.
- C0(active): Everything is powered on, processor executing code. P-state is relevant here.
- C1(Halt): Nothing is executing. Any P-state is not relevant here.
- C2(Stop-Clock): similar to C1 but it takes longer time to go back to C0
- C3(Sleep): will take considerably longer time to go to C0.
- ..
- C8

### P-state(processing state): 
CPU is executing at specific frequency,voltage.
#### Types of P-States
- PC-States(Core P states): 
- P0: CPU running at max freq -> max cycles -> max power,voltage consumed.
- P1: 
