Page Rank
- Terms: Backlinks


## Page Rank
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
u = Page
Bu = Pages point to u
Fu = Pages to which u points. Nu = Number of links from u to all other pages.
c = constant normalization factor

Page Rank = c x sumof ( Rv )
                       ----
                        Nv
```

### Terms
#### Backlinks / incoming links
- Backlinks (also known as “inbound links”, “incoming links” or “one way links”) are links from one website to a page on another website.
- More the backlinks up it will be on search results on google.
