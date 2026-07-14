- [AST vs Prefix Tree](#vs)
- [How an AST is Constructed](#how)
  - [Example (x = 2 + 3)](#ex1)
  - [Example (Policy Rule)](#ex2)

<a name=vs></a>
## AST vs Prefix Tree
Prefix tree(Trie) and an abstract syntax tree (AST) are completely different data structures used for entirely different purposes.

||Prefix Tree|AST|
|---|---|---|
|Nodes|Individual characters or string|construct occurring in the code, such as a loop, variable declaration|
|Path|Concatenating nodes forms a specific word or key|Parent-child links represent structural nesting and scope|
|Domain|Dictionaries, routing tables|Compilers, interpreters, linters, static code analysis|
|Example|Insert "cat", "car". root=c. Under c, the path branches at ca into t and r|x = 2 + 3. root is =. left child=x, right child=+|

<a name=how></a>
## How an AST is Constructed
```
[Source Code] ──► 1. Lexical Analysis (Scanner) ──► [Tokens] ──► 2. Syntax Analysis (Parser) ──► [AST]
```
- Lexical Analysis (Scanning): The scanner breaks a raw text string into chunks called tokens (like keywords, identifiers, or operators).
- Syntax Analysis (Parsing): The parser reads these tokens and groups them hierarchically based on the language's grammar rules.
- **Evaluation** Operators with higher priority (like AND, *) sit lower in the tree so they are evaluated first. Operators with lower priority (like IF/THEN, =) sit closer to the root.

<a name=ex1></a>
### Example (x = 2 + 3)
```c
Tree Creation

x = 2 + 3
Tokens: [Identifier: x], [Operator: =], [Integer: 2], [Operator: +], [Integer: 3]

Operator Precedence: Operators with higher priority (AND, *) sit lower in the tree so they are evaluated first. Operators with lower priority (like IF/THEN, =) sit closer to the root.
        [Assignment: =]
          /        \
   [ID: x]          [Operator: +]
                       /       \
                [Int: 2]       [Int: 3]

Tree Evaluation: From bottom
```

<a name=ex2></a>
### Example (Policy Rule)
>  IF User == "Alice" AND App == "Jira" AND Action == "Download" THEN PolicyAction = Block

```c
Tree Creation
Tokenize: Keywords(IF, AND, THEN), BlockIdentifiers/Variables(User, Application, Action), Operators(: ==), Literals("Alice", "Jira", "Download")

              [Conditional: IF-THEN]
                     /            \
                  [AND]        [Block]
                  /              \
             [ AND]              [==]
               /     \            /    \
             [==]    [==]    Action "Download"
             /  \     /  \
        User "Alice" App "Jira"
```
