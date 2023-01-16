**Lettuce**
- [Lettuce vs Behave](#vs)
- [Why to use behave not Lettuce](#w)

### Lettuce
This is also a BDD framework as [Behave](../Behave)

<a name=vs></a>
#### Lettuce vs Behave
|Lettuce | Behave|
|---|---|---|
|Decorators|Single decorator for step definitions||
|context variable(world)|This is a shared holder of attributes. It never gets cleaned up during the run.||
|Hooks|Hooks are declared using decorators rather than as simple functions.||
|Tags|No support for tags.||
|Test case files|Step definition code files can be anywhere in the feature directory hierarchy.||

<a name=w></a>
#### Why to use behave not Lettuce
- Lack of tags
- The hooks functionality was patchy. For instance it was very hard to clean up the world variable between scenario outlines. Behave clears the scenario-level context between outlines automatically.
- Lettuce’s handling of stdout would occasionally cause it to crash mid-run in such a way that cleanup hooks were never run
- Lettuce uses import hackery so .pyc files are left around and the module namespace is polluted.
