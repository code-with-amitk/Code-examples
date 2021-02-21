## Caching
- **Why?** 
  - User(s) often request same Web page that they have used before and page contents(eg: images, CSS, scripts) donot change so often. 
  - Its network BW consumption and time wastage to fetch these resources again when browser has a copy.
- **What?** 
  - Caching less frequently changing pages. Eg: Information about Gods(good candidate for caching, as not change often).
  - Not caching more frequently changing pages. Eg: New-site pages would change often(not good candidate for caching).

### Cache Design
- Conditional GET is sent with [Request Header (if Modified)](./Request_Response_Header.md)
```http

<-------------------Web Browser------->
  User    front-end   Cache(Hard-Disk)                
   - page1 ->
            --- Find page-1 ->
                       Cache Valid?
            <-- Page-1 ------
                       Else                                          WEB-SERVER
                          -------------- Conditional GET ----------> (Program)  //Cache asks is my copy valid(using REQUEST HEADER)?
                          <-----------  Page Not Modified   -------- 
                          <---- Modified Page(Expires Header=1 day)-      //Expires header tells Http when to fetch the page again.
```

