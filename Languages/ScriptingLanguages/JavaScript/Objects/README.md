## Objects
- **1. JS uses functions as classes** JS does not have class statement.
```js
function makePerson(first, last) {                //Class 
  return {
    first: first,                               //members
    last: last,
    fullName: function() {
      return this.first + ' ' + this.last;
    },
    fullNameReversed: function() {
      return this.last + ', ' + this.first;
    }
  };
}

var s = makePerson('Simon', 'Willison');                  //Created Object
s.fullName(); // "Simon Willison"
s.fullNameReversed(); // "Willison, Simon"
```
