**Page Rank**
- [Terms: Backlinks, Rank Sink Problem, Dangling links](#t)


## [Page Rank](http://ilpubs.stanford.edu:8090/422/1/1999-66.pdf)
- This is ranking of every page. This decides on which place google places the page on search. Roughly 150 Billion pages are present while they have around 1.5 billion links to other pages.
- **Structure of page:**
```c
Pages A,B have backlinks to C.
--Page-A--
|        |
|     ---------------
|--------|           \/
                    
--Page-B--          Page C
|        |           /\
|     ---------------
|--------|           
```
#### Page Rank Formula
```c
u(11) = Page
Bu(0..10) = Pages point to u 
Fu(12..20) = Pages to which u points. Nu = Number of links from u to all other pages.
c = constant normalization factor

R1/N1. (Rank of page-1)/(Number of links from page1 to all other pages)
R2/N2. (Rank of page-2)/(Number of links from page2 to all other pages)

Page Rank = c (R1/N1 + R2/N2 ... + R10/N10).
```
Page Rank: (Summation of ranks of all pages pointing to target page) / (Number of links on src pages)

### Terms
#### Backlinks / incoming links
- Backlinks (also known as “inbound links”, “incoming links” or “one way links”) are links from one website to a page on another website.
- More the backlinks up it will be on search results on google.
#### Dangling links
Hyperlinks which does not point to anywhere.
#### Rank Sink Problem
if there are 2 pages which point to each other and does not point to any other page, then how page rank is calculated?
```c
Page1 --->  Page2
      <---
```
