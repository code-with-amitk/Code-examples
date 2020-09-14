## Inheritance 
- **What?** Creating new class(decendent/derived) from existing class(ansector/base).

### Rules of Inheritance?
- All member variables(public,protected,pvt) of base are inherited inside derv class. See Memory layout of derv class object.
- Inheriting Base member variables inside derv:

|Type|How|
|---|---|
|Public|<ul><li>all public members of the base class becomes public members in derv</li></ul>|
|protected|<ul><li>*Member Variables:* all protected members of the base class becomes protected members in derv</li></ul><ul><li>*Functions* Function present in protected section cannot be called using Object</li></ul>|

c. private:
        - private members of base class does not go into private section of derv class.
        - private members of the base are never accessible unless friended.
        How to access private data members inside derv? Using public function in base and calling same from derv.

3: Instance of derv class can invoke any public function of base class.

4. Functions from base class are also inherited inside derived class.

5: SAME-NAMED-FUNCTION_IN_BASE_AND_DERV(FUNCTION-OVERRIDING)
 - Base & derv can have same named function. But with derv Object, derv class function is called.
 - (function overriding) Same named function having different body inside derv class.
