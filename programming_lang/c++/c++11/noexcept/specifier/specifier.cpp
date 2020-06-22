/*	noexcept-specifier.cpp

TYPES OF NOEXCEPT? noexcept exists in two forms since C++11: 
  1. noexcept as specifier and
  2. noexcept as operator

- SPECIFIERS comes after function name.

MEANING? By specifying noexcept it means these functions either:
 A. does not throw an exception and
 B. if they throw we do not care and let the program just crash.

WHY TO USE NOEXCEPT SPECIFIER?
1. Documents the behavior of function. If a function is specified as noexcept, it can be safely used in a non-throwing function.
2. Compiler can optimize noexcept function.

EXAMPLES:These are implicilty non-throwing.
	Default constructor, destructor,Move and copy constructor,Move and copy assignment operator

WHAT HAPPENS WHEN YOU THROW EXCEPTION IN FUNCTION DECLARED NOEXCEPT
- std::terminate calls the currently installed std::terminate_handler which calls std::abort by default.
*/

//noexcept is equal to noexcept(true)
void func1() noexcept;        // does not throw

void func2() noexcept(true);  // does not throw


//throw() is equivalent to noexcept(true) 
void func3() throw();         // does not throw


//noexcept(false) means that the function may throw an exception.
void func4() noexcept(false); // may throw
