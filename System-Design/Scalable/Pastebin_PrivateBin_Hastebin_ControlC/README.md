**What is Pastebin?**
  - Users can paste/store any data(text,images), generate random URL, then share with other users.

## [To Cover](/System-Design/Scalable)

## 1. Requirements
- **1. Functional** 
  - Users can paste(text)/upload(images) and get a unique URL to access it. Data>10MB should not be allowed(to stop abuse of service).
  - Data and links will expire after a specific timespan automatically; users should also be able to specify expiration time.
  - Custom URLs should be allowed, but with limited length(to stop abuse of service).
- **2. Non-Functional:** highly 
  - *Highly Reliable.* System should be highly reliable, any data uploaded should not be lost.
  - *Highly available*
  - *Low latency*
  - *short URL* should not be gussable
- **3. Extended:**
  - Analytics, e.g., how many times a paste was accessed?
  - Our service should also be accessible through REST APIs by other services.

## 2. BOE


