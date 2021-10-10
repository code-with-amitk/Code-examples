**React**
- [Terms](#t)
- **React Elements**
  - [Render element to DOM](#r1)
- [Libraries](#lib)


## React
React is a declarative & flexible frontend JS library for building 
  - frontend large scale, data driven UIs.
  - Andriod, ios apps, Desktop applications
  - Virtual Reality Application using react VR.

<a name=t></a>
### Terms
- **Component:** This is Small,Isolated piece of code that takes parameters/props/properties as input, return hierarchy of views to display. Each react component can operate independently, this allows you to build complex UIs from simple components.
- **DOM API** is a collection of objects that JavaScript can use to interact with the browser to modify the DOM.

## React Element
<a name=r1></a>
#### Render element to DOM
```js
var ch1 = React.createElement("h1", null, "Chapter-1")                          //1: Create element without properties
var ch2 = React.createElement("h1", {id:"t", 'data-type:"title"}, "Chapter-2")  //2: Create element with properties
//h1=Type of element. Heading element
//id,data-type: These are properties of element
//Chapter-1=element's children

During rendering react will convert this to actual DOM object.
<h1 >Chapter-1" </h1>
<h1 data-reactroot id="t" data-type="title"> Chapter-2 </h1>    //data-reactroot will always appear as an attribute of the root element.

ReactDOM.render(ch1, document.getElementById('react-container'))    //3. Render element to DOM

<body>
 <div id="react-container">
 <h1>Chapter-1</h1>
 </div>
</body>
```

<a name=r2></a>
#### pros.children
- data-reactroot: This is tree's root
- 
```js
React.createElement(
 "parent",                                  //This is root element
 null,
 React.createElement("li", null, "child1"), //These are 3 children
 React.createElement("li", null, "child2"),
 React.createElement("li", null, "child3"),
)

arr[] = [child1, child2, child3]          //React creates an array of these child elements and sets the value of props.children to that array.
pros.children = arr
```

<a name=lib></a>
### Libraries
**1. React library** To create views. 
**2. ReactDOM library** To render the UI in the browser.
