**html / hypertext markup language**
- [Tags](#t)
- [Attributes](#a)
- [Formatting elements](#f)
- [CSS, Cascading Style Sheets](#css)

## html
doctype: 	Tells about type of page
  
<a name=t></a>
### Tags
#### a
links
#### body
Contents of page
#### `<br>`
line break, Newline
#### div
defines a division or a section in an HTML document. [div example](https://www.w3schools.com/tags/tryit.asp?filename=tryhtml_div_test)
#### `<hr>`
Horizontal Rules. used to separate content. Add a line
#### h1,h2,h3:	Headings
Search engines use the headings to index the structure and content of your web pages
#### html
Root element of page
#### img
Defines images
#### label
defines a label for several elements. provide a usability improvement for mouse users
#### p
Paragraph. Starts with newline & is block of text.
#### `<pre>`
Defines preformatted text. text inside a `<pre>` element is displayed in a fixed-width font (usually Courier), and it preserves both spaces and line breaks
#### span
used to color a part of a text. [Example](https://www.w3schools.com/tags/tryit.asp?filename=tryhtml_span)
#### title
Tile of Page

<a name=a></a>
### Attributes
provide additional information about HTML elements. Specified in in the start tag. comes in key=value pair
#### alt
alt="Girl with a jacket". specifies an alternate text for an image
#### class
Used to specify a class for an HTML element.
```c
```
#### lang
lang attribute inside the `<html>` tag, to declare the language of the Web page. To assist search engines and browsers
```html
				<html lang="en">
```
#### style
To add color, font, size, and more. https://www.w3schools.com/html/html_styles.asp
```html
				<p style="color:red;font-size:300%;"> .. </p>
				<body style="background-color:powderblue;">		//Background of page
```
#### title
Defines some extra information about an element. The value of the title attribute will be displayed as a tooltip when you mouse over the element
```html
				<p title="I'm a tooltip">This is a paragraph.</p>
```

<a name=f></a>
### Formatting elements
#### `<b>` 
Bold text
#### `<strong>`
Important text
#### `<i>` 
Italic text
#### `<em>` 
Emphasized text
#### `<mark>` 
Marked text
#### `<small>`
Smaller text
#### `<del>` 
Deleted text
#### `<ins>` 
Inserted text
#### `<sub>`
Subscript text
#### `<sup>`
Superscript text

<a name=css></a>
### Cascading Style Sheets (CSS)
- Used to format the layout of a webpage
- With CSS, you can control the color, font, the size of text, the spacing between elements
- CSS can be added to HTML documents in 3 ways:
#### 1. Inline
using the style attribute inside HTML elements
```c
<h1 style="color:blue;">A Blue Heading</h1>
<p style="color:red;">A red paragraph.</p>
```
#### 2. Internal
- using `<style>` element in the `<head>` section. Example:
```c
<!DOCTYPE html>
<html>
<head>
<style>
body {background-color: powderblue;}
h1   {color: blue;}
p    {color: red;}
</style>
</head>
<body>	
```
#### 3. External (`<link>` in `<head>`)
- An external style sheet is used to define the style for many HTML pages.
- To use an external style sheet, add a `<link>` to it in the `<head>` section of each HTML page
```c
<!DOCTYPE html>
<html>
  <head>
    <link rel="stylesheet" href="styles.css">
  </head>
  
  <body>
    <h1>This is a heading</h1>
    <p>This is a paragraph.</p>
  </body>
</html>
```
- style.css
```c
body {
  background-color: powderblue;
}
h1 {
  color: blue;
}
p {
  color: red;
  border: 2px solid powderblue;		<!--CSS border property defines a border around an HTML element-->
  padding: 30px;			<!--defines a padding (space) between the text and the border-->
  margin: 50px;				<!--defines a margin (space) outside the border-->
  
}
```
