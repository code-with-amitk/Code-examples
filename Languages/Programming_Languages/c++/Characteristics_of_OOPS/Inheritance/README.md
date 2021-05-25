## Inheritance / Is-A Relationship
- **What?** Creating new class(decendent/derived) from existing class(ansector/base).

### Rules of Inheritance?
- All member variables(public,protected,pvt) of base are inherited inside derv class. See Memory layout of derv class object.
- Inheriting Base member variables inside derv:

|Inheritance Type|Member Variable|Function|
|---|---|---|
|Public|<ul><li>*Public member Variables* Of base class can be accessed in public section. NOTE: this does not mean derv gets a COPY/REFERENCE of base public variables. Derv can access/display base variables</li></ul>|Derv class can invoke any public fun of base|
|protected|*Member Variables:* all protected members of the base class becomes protected members in derv.|Function present in protected section cannot be called using Object|
|Private|<ul><li>Not inherited in derv class. Can only be accessed if friended.</li></ul><ul><li>*How to access private data members inside derv?* Using public function in base and calling same from derv</li></ul>|

- SAME-NAMED-FUNCTION_IN_BASE_AND_DERV(FUNCTION-OVERRIDING)
 - Base & derv can have same named function. But with derv Object, derv class function is called.
 - (function overriding) Same named function having different body inside derv class.
