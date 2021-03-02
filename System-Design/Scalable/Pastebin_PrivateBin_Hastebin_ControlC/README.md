**What is Pastebin?**
  - Users can paste/store any data(text,images), generate random URL, then share with other users.
  - This is **read heavy** application. Ratio 10:1 read:write.

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
  - showing some public pastes in last 60 min on right in scroll pane.
  - Analytics, e.g., how many times a paste was accessed?
  - Our service should also be accessible through REST APIs by other services.

## 2. BOE

|World Population|InternetUsers(60%)|Pastebin users writes/month(1% of Internet users)|Writes/day|Read/day = 10 x Writes|
|---|---|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.01 = 42 Million|1.5 Million writes/day|15 Million Reads/day|

- **Traffic Estimates:** 
  - Writes per sec = 1.5/24x3600 = 17 writes/sec
  - Reads per sec = 170 reads/sec

- **Storage Estimates:** Each paste/write on Average = 10KB.
  - Per day storage = 1.5M x 10KB = 15GB. For 5 years = 15x30x12x5 = 27TB

- **Bandwidth Estimates:** 
  - Per second incoming data Writes = 17x10KB = 170KB/sec
  - Per second outgoing data Reads = 170x10kB = 1.7MB/sec

- **Cache Estimates:** Assuming 80-20 rule. Most people generates 20% of pastes. 1.5M x.2 x 10KB = 3GB/day

## 3. System APIs
- SOAP or REST APIs to expose the functionality of our service.
```html
string WritePaste(api_dev_key, paste_data, custom_url(optional) string user_name, string paste_name(optional), string expire_date(optional))
  api_dev_key (string): The API developer key of a registered account. This will be used to, among other things, throttle users based on their allocated quota.
  paste_data (string): Textual data of the paste.
  custom_url (string): Optional custom URL.
  user_name (string): Optional user name to be used to generate URL.
  paste_name (string): Optional name of the paste
  expire_date (string): Optional expiration date for the paste.
Return: shorturl or 
  
DeletePaste (api_dev_key, api_paste_key)  
getPaste(api_dev_key, api_paste_key)  
  “api_paste_key” is a string representing the Paste Key of the paste to be retrieved
```

## 4. DB Design
- Use 2 Tables, 1 for storing Pastes & other for user's data.
```html
TABLE-1
| userID | Location of paste | shortURL(key)(varchar) | creationDate(dateime) | expirationTime(datetime) |
|--------|-------------------|------------------------|-----------------------|--------------------------|

TABLE-2: User Table
| userID | email(varchar) | creationDate | lastLogin |
|--------|----------------|--------------|-----------|
```
