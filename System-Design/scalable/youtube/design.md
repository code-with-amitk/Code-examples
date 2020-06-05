Million=10^6. Billion=10^9. Trillion=10^12, Quadtrillion=10^15

## 1. REQUIREMENT COLLECTION
  - **Functional**
    - Users can upload, view, search
    - Service can do stat collection: no of vistors, views, likes, dislikes.
    - User can like/dislike the videos.
  - **Non-functional**
    - Reliable
    - Available
    - Fast(No lag)
    
## 2. CAPACITY ESTIMATIONS/BOE CALCULATIONS
  - Read/Write or View/Upload = 200/1
    - Read = Views: 50k/sec
    - Uploads = 250/sec. 15000/min = 15k/min. 900k/hour. 27 Million/month. 9 Billion/Year. 50 Billion/5 years.
  - Storage Requirements
    - 1 sec video need 1 MB
    - 250 sec = 250 MB
    - 5 year = 50*10^9*10^6 = 50*10^15 = 50 Quadtrillion bytes
      - But this will change when video compression is done at storage
    - 

  
  
