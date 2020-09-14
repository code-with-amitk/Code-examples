## Inheritance 
- **What?** Creating new class(decendent/derived) from existing class(ansector/base).

### Rules of Inheritance?
- All member variables(public,protected,pvt) of base are inherited inside derv class. See Memory layout of derv class object.
- Inheriting Base member variables inside derv:

|Type|Member Variable|Function|
|---|---|---|
|Public|<ul><li>*Public member Variables* Of base class becomes public members in derv</li></ul>|<ul><li>*Public member Functions* Derv class can invoke any public fun of base</li></ul><ul><li>*Public member Functions* are also inherited inside Derv class</li></ul>|
|protected|<ul><li>*Member Variables:* all protected members of the base class becomes protected members in derv</li></ul>|<ul><li>*Functions* Function present in protected section cannot be called using Object</li></ul>|
|Private|<ul><li>*Private Member Varaibles:* Not inherited in derv class. Can only be accessed if friended.</li></ul><ul><li>*How to access private data members inside derv?* Using public function in base and calling same from derv</li></ul>|

- SAME-NAMED-FUNCTION_IN_BASE_AND_DERV(FUNCTION-OVERRIDING)
 - Base & derv can have same named function. But with derv Object, derv class function is called.
 - (function overriding) Same named function having different body inside derv class.
