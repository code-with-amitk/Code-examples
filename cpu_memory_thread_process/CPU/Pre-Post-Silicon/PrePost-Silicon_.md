- Both are Verification and Validation checks for the correctness of the design

## A. Terms
- **Tape-out or tapeout** is the final result of the design process for integrated circuits or printed circuit boards before they are sent for manufacturing. 

## B. Post/Pre Silicon Validation
- **Post Silicon Validation**
  - *What* Validation is executed on silicon chip in a real environment.
  - *How* When a design passes from pre-silicon verification, few initial prototypes of the chips are fabricated and are used as test objects.
  - *Issues* Very low observability of the system since only access to the input and output pins on the hardware. No access to the internal signals of the design. 
- **Pre Silicon Verification/Emulation**
  - *What*
    - Before placing silicon on the board(ie before creating chip), Designs are developed in **Verilog or HDL** and run on Simulators. 
    - Everything can be simulated, clock speed, power consumption etc.
    - software development can be completed before silicon. This is :heart_eyes: software development using Emulation.
  - *How it performed* Creating a bug-free design in the first attempt is nearly impossible. So, several verification stages are instrumented to capture the bugs in the design, rectify issues.  
  
## C. Pre-Silicon Emulation Detailed
![ImgURL](https://i.ibb.co/dGgM2pN/pre-silicon.png)
- **Verification**
  - *Goal:* Functional correctness before tapeout
  - *Methods*
    - Simulation with prototypes

  
