# Makefile or makefile or GNUMakefile

## A. STRUCTURE OF Makefile
- makefile consists of a set of `RULES`.
	- Rules consists of 3 parts 
		1. Target: target and pre-requisites are separated by a colon (:)
		2. List of pre-requisites 
		3. A command: The command must be preceded by a tab (NOT spaces)
- To complete a target:
	1. Pre-requsites must exist, if does not exist, rules are checked to create pre-requisites.
	2. Once pre-requisites are created, command is executed.

[See Hello-World example to Understand this](https://github.com/amitkumar50/Code-examples/blob/master/programming_lang/C/Makefile/Examples/hello-world/README.md)	
```
target: pre-req-1 pre-req-2 ...
	command
```

## B. More on Makefile
### B1. PHONY/Artificial Targets
- These are not real name of a file, it is just a name for a recipe to be executed. Example: clean, all, install.

### B2. VARIABLES
- Variable carries different values. A variable begins with a `$`.
- **Types of variables**
	- ***Multicharacter variables*** are enclosed within parentheses `(...)` or braces `{...}`. Eg: $(CC), $(CC_FLAGS)
	- ***Singlecharacter variables*** do not need the parentheses. Eg: $@, $^
- **Automatic Variables** These are ***automatically(note automatically)*** set by make whenever rule is matched.

| Automatic Variable | Meaning |
| --- | --- |
| $@ | Target Filename, name of the file being generated |
| $* | Target filename without extension |
| $< | 1st Pre-requisite filename |
| $^ | Filename of all Pre-requisites seperated by spaces(discard Duplicates) |
| $+ | similar to $^, but includes duplicates |
| $? | names of all prerequisites that are newer than the target, separated by spaces |
| $% | target member name. When target is foo.a(bar.o) ‘$%’ is bar.o |
| @ | Silent, @rm means rm will be executed but silently ie not output on screen |
| := | Simple assignment. Example `CC :=${GCC} ${FLAGS}` is expanded to `gcc -W` |

### B3 .PRECIOUS
  - if make is killed or interrupted during the execution of their recipes, the target is not deleted. 
  - Also, if the target is an intermediate file, it will not be deleted after it is no longer needed
  - Basically, .PRECIOUS to preserve intermediate files.
### B4. include 
	- Suspend reading current Makefile and read other makefile before continuing.
	
### B5. override
	- This is for setting the variable. Example: (override variable = value)
### B6. $(call variable,param1,param2,…)
	- Used for creating function(named variable) with parameters(param1,param2..)
   - Here BOOST_CHECK variable is assigned to function.
### B7. **User variables** Defined by Users. Examples:
   - CPPFLAGS
   - LDLIBS: flags to give to compilers when they are supposed to invoke the linker, ld , such as -L . Libraries ( -lfoo ) should be added to the LDLIBS.
   

### SWITCHES
| switch | Name | Meaning |
| --- | --- | --- |
| -Dmacro | Predefine name| (#man gcc) option Predefine name as a macro, with definition 1 |
| -O | Optimize | (#man gcc) Can have values 1,2,3,4 |
| -g | Debugging info | (#man gcc) Produce debugging information. -g0:no debug |

### FILES

| Extension | Meaning |
| --- | --- |
| .d | Dependency file contains make dependencies(which are automatically detected). Header files which are required for C/C++ source file are added into this |
