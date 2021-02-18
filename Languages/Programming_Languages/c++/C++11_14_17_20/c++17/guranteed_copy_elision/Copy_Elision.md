## Copy Elision
- **What** 
  - Compiler optimisation technique that eliminates unnecessary copying of objects. 
  - This mandatory omitting copy and move constructor by compiler even user asked to perform copy/move operation because copy/move creates unnecessary temporary objects.
- **How it works?**
  - The objects are constructed directly into the storage where they would otherwise be copied/moved to.
- **How to avoid copy elision?**  By using `-fno-elide-constructors` switch
