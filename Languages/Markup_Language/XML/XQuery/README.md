## XQuery
- **What?** Querying XML document data using query statements. Xquery us similar to SQL in DB.
- **XQuery Example:**
```xml
for $x in doc("books.xml")/bookstore/book
where $x/price>30
order by $x/title
return $x/title
```
