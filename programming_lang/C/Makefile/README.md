## Makefile

### Sections in Makefile
1. Target
2. Dependency
3. Rules

### Meanings in Makefile
- **PHONY target** not real name of a file, it is just a name for a recipe to be executed.
- **.PRECIOUS** 
  - if make is killed or interrupted during the execution of their recipes, the target is not deleted. 
  - Also, if the target is an intermediate file, it will not be deleted after it is no longer needed
  - Basically, .PRECIOUS to preserve intermediate files.
- **include** Suspend reading current Makefile and read other makefile before continuing.  
- **$(call variable,param1,param2,…)** Used for creating function(named variable) with parameters(param1,param2..)
   - Here BOOST_CHECK variable is assigned to function.
   
  
### SPECIAL CHARACTERS
| character | Meaning |
| --- | --- |
| $@ | name of the file being generated |
| $% | target member name. When target is foo.a(bar.o) ‘$%’ is bar.o |
| := | Simple assignment. Example `CC :=${GCC} ${FLAGS}` is expanded to `gcc -W` |

### SWITCHES
| switch | Name | Meaning |
| --- | --- | --- |
| -D | 
