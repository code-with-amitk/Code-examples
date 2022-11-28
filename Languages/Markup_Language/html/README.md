**html / hypertext markup language**
- [Tags](#t)
- [Attributes](#a)
- [Formatting elements](#f)
- [CSS, Cascading Style Sheets](#css)

## html
doctype: 	Tells about type of page
  
<a name=t></a>
### Tags
#### html
Root element of page
#### title
Tile of Page
#### body
Contents of page
#### h1,h2,h3:	Headings
Search engines use the headings to index the structure and content of your web pages
#### p
Paragraph. Starts with newline & is block of text.
#### a
links
#### img
Defines images
#### `<br>`
line break, Newline
#### `<hr>`
Horizontal Rules. used to separate content. Add a line
#### `<pre>`
Defines preformatted text. text inside a `<pre>` element is displayed in a fixed-width font (usually Courier), and it preserves both spaces and line breaks

<a name=a></a>
### Attributes
provide additional information about HTML elements. Specified in in the start tag. comes in key=value pair
#### alt
alt="Girl with a jacket". specifies an alternate text for an image
#### style
To add color, font, size, and more. https://www.w3schools.com/html/html_styles.asp
```html
				<p style="color:red;font-size:300%;"> .. </p>
				<body style="background-color:powderblue;">		//Background of page
```
#### lang
lang attribute inside the `<html>` tag, to declare the language of the Web page. To assist search engines and browsers
```html
				<html lang="en">
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
#### 3. External
`<link>` element to link to an external CSS file
