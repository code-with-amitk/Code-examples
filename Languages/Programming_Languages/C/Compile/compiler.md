## Compiler
  
```c
        source-code                                  expanded-code                  
                                 ------------------                          ---------------------------------------------------------COMPILER---------------------------------------------------------------   assembly-code
            a.c            -> | Pre-processor |     - a.i ->             | lexical-analyzer > syntax-analyzer > semantic-analyzer > intermediate-code-generator > code-optimizer > code-generator  | - a.s ->
            b.c           ->  ------------------      -b.i->          ----------------------------------------------------------------------------------------------------------------------------------------   -b.s-> 
```
## 1. Lexical Analyser/Scanner
- This reads stream of chars making up the source code and groups into tokens, including keywords, identifiers, integers, operators and special symbols, etc.
- **TOKENS/LEXEMES?** These are sequence of alphanumeric characters. There are some predefined rules for every lexeme to be identified as a valid token. In programming language, keywords, constants, identifiers, strings, numbers, operators and punctuations symbols can be considered as tokens. 
	- TOOLS: lex, flex

## 2. Syntax Analyzer/Parser
- It takes the token produced by lexical analyzer as input and generates a parse tree (or syntax tree). parser checks if the expression made by the tokens is syntactically correct.

## 3. Semantic Analyzer
## 4. Intermidiate Code Generator
## 5. Code Optimizer
- **WHAT?** improve on the intermediate code to generate a code that runs faster and occupies less space. Example:
```c++
This Code
	a = intofloat(10)
  b = c * a
  d = e + b
	f = d
			
Will become:
	b = c * 10.0
  f = e+b
```

## 6. Code Generator
- **WHAT?** Takes inputs from phase-5 and generates machine code. All memory locations and registers are selected and allotted during this phase.
	- `a = b + 60.0`  Would be possibly translated to registers.
```asm
	MOV a, R1
	MUL #60.0, R2
	ADDF R1, R2
```
