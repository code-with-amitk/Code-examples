**Web Crawler**

### Web Crawler
- This is a software program that crawls/reads all pages on www.
- Crawler is seeded with few(100's) of pages, on which it finds hyperlinks and traverses to other pages.
- While traversing it creates index of page-url and keywords present on page. it also downloads pages(not images,videos).
  - CRAWLER can be thought of librarian(of huge pile of books(not arranged in order)) maintaning the catalog depicting location of book and excerpt of content.
  - Or Crawler is similar to index at back of book telling page number and content.

### Requirements
#### Functional
1. Should crawl urls (To start 10 URLs are provided).
  - goto a URL, find other URLs inside it, make a hashmap.
3. Should not stuck in loop (incase of cyclic graph)
#### [Non-Functional](/System-Design/Scalable)

### BOE
### API Design
### DB Schema
### HLD
