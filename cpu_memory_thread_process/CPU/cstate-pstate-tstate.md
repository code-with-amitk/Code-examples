## ACPI(Advanced Configuration and Power Interface)
- This is Open standard using which Operating system can:
  1. Discover & configure Hardware components
  2. Perform power management. This brings power management under OS control. (Eg: putting unused components on sleep)
  3. Perform status monitoring
- ACPI replaces APM & PnP specifications.
- How it works?
 - ACPI advertises available components to OS kernel using methods provided thru [firmware(UEFI or BIOS)](https://github.com/amitkumar50/Code-examples/blob/master/cpu_memory_thread_process/CPU/firmware_UEFI.md)

## 1. Processor Power Management Technologies
- ACPI divided power management technologies into 2 categories.

### 1.1 P-State(Execution Power Saving states)?
- **What** 
  - This is a map <voltage,frequency> pairs based on which speed and power consumption of the [coprocessor](https://github.com/amitkumar50/Code-examples/blob/master/cpu_memory_thread_process/CPU/processor_coprocessor.md) is decided.
  - Provides way to scale Frequency & voltage on which processor is running, with aim of reducing power consumption.
  -  The coprocessor's **PM SW(status word)** handles the transition from one P-state to another. 
    - The PM SW periodically monitors the processor utilization.
    - If that utilization is less than a certain threshold, it increases the P-state, ie it enters to next higher power efficiency state
  
- **Goal** 
  - Reducing Power Consumption Without Impacting Performance
  
- **Frequency & Speed & power relation**  
  - High Frequency -> high CPU I/O Rate -> High Processor performance -> high power consumption
  - Reduced frequency to 1/2 -> CPU I/O Rate is reduced to 1/2 -> performance 1/2ed -> less power consumption

- **Why Application Developer should bother about power, He wants speed?**
  - More power consumption -> More cost of cooling 
  - if we can get power consumption down without losing performance, this means we can pack more processors in same power budget.

- **Types of P States**

| P-State | CPU Utilization |
| --- | --- |
| P0 | 100%. CPU running fastest |

#### Power consumption
P ~ f V²	//f=frequency, V=voltage

### 1.2 C-State(Idle Power Saving states)
- **What** 
  - State in which CPU is at idle or turned off certain functions.
- **Types of C-States**

| C-State | Name | Meaning |
| --- | --- | --- |
| C0 | Active | Processor executing |
| C1 | Halt | Nothing executing |
| C2 | Stop-clock | similar to C1 but it takes longer time to go back to C0 |
| C3 | Sleep | will take considerably longer time to go to C0 |
| C8 |

### 1.3 PC-State(Pacakge Idle States)
- **What**
  - ***Pacakge*** is complete circuit on the board including coprocessors(Each coprocessor can have upto 60 cores).
  - These are idle power conservation states for the entire package. 
  
### 1.4 T-State(Throttling State)
- **What** 
  - This was old state existed before C,P States. This use to save processor from burning down.
- **How it worked?** 
  - when things went very bad, such as when the cooling fan failed while the processor was running at max. Temperature sensor senses the junction temperature was reaching a level that could cause damage the processor, the HW power manager would place the processor in different T-States depending upon temperature.
  - The normal run state of the processor was T0.
- **How its different from P, C States?**
  - Note that in contrast to P-states, the voltage and frequency are not changed. 
  - In T-states the application runs slower not because the processor is running slower, but because application is suspended for some percent of the time. 
