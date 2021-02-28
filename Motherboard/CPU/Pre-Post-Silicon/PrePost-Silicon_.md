- Both are Verification and Validation checks for the correctness of the design.

## A. Terms
- **Tape-out or tapeout** is the final result of the design process for integrated circuits or printed circuit boards before they are sent for manufacturing. 
- **Post Silicon Validation**
  - *What* Validation is executed on silicon chip in a real environment.
  - *How* When a design passes from pre-silicon verification, few initial prototypes of the chips are fabricated and are used as test objects.
  - *Issues* Very low observability of the system since only access to the input and output pins on the hardware. No access to the internal signals of the design. 
- **Pre Silicon Verification/Emulation**
  - *What*
    - Before placing silicon on the board(ie before creating chip), *Software Designs are developed in :red_circle:VerilogorHDL and run on Simulators*.
    - Simulators:
      - VEH, SOC emulators
      - SimNow, FPGA etc
    - Everything can be simulated, clock speed, power consumption etc.
    - software development can be completed before silicon. This is :red_circle: software development using Emulation.
  - *Why Pre-silicon:*
    - Software is verified before bring up.
    - HW SW defects are detected earlier.
  - *How it performed* Creating a bug-free design in the first attempt is nearly impossible. So, several verification stages are instrumented to capture the bugs in the design, rectify issues.  
  
## C. Pre-Silicon Emulation/Verfication
![ImgURL](https://i.ibb.co/dGgM2pN/pre-silicon.png)
- **Verification**
  - *Goal:* Functional correctness before tapeout
  - *Methods*
    - Simulation with prototypes

  
