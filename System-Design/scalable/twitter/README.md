## Twitter Design

### A. REQUIREMENTS
#### A1. FUNCTIONAL
  1. **Followers**
     - Can see the tweets(text,videos,photos) of people they follow on their timeline.
     - Can mark any tweet as favourite.
     - Can reply to tweets
  2. **Followed**
     - Post tweet < 150 characters.
  3. **Search**
     - Both followers, followed can search any person.     
     
#### A2. NON-FUNCTIONAL
  - S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
    - Scalable, Secure, SOA
    - Logging, Load, Latency
    - Cache(Invalidation, negative cache)
    - Available, Accurate, Analyze, Authenticate
    - Reliable, Redundant(Using DB)
    - Fast

### BOE Calculations (should be done after HLD)
  - Total world population = 8 Billion = 8x10<sup>9</sup>
  - **Daily Active Twitter users**
    - 40% have internet connection = 32x10<sup>8</sup>
    - Out of 40% only 10% active are Twitter users = 32x10<sup>7</sup> = 320 Million user
    - Let's 10% be daily active user. 320 Million user = 32 Million users.
  - **Storage Requirements**
    - ***For Storage of Text Tweets***
      - 10% of user does 1 tweet per day. 32x10<sup>5</sup>
      - Let's each tweet has 150 characters. 1 character takes 2 bytes of storage. 300 bytes/tweet.
      - 32x10<sup>5</sup> x 300 = 9x10<sup>8</sup> / day
      - 27x10<sup>9</sup>/month
      - 324x10<sup>9</sup>/year
      - 1x10<sup>12</sup>/year = 1 TB/5 years
    - ***For Storage of Photo Tweets***
      - Let's assume every 5th tweet has photo on it. Photo size = 200kb
      - Total photo tweets = 32x10<sup>5</sup> / 5 = 64x10<sup>4</sup> photo tweets per day
      - 64x10<sup>4</sup> x 30 x 12 x 5 x 200kb= 6000 TB / 5 years = 6 Trillion bytes
    - ***For Storage of Video Tweets***
      - Let video takes 2MB of data and every 10th is a video tweet.
      - Video tweets per day = 32x10<sup>4</sup> / day
      - 32x10<sup>4</sup> x 30 x 12 x 5 x 2MB = 1 Quadtrillion = 10<sup>15</sup> bytes / 5 years
      

### B. HLD
#### B1. 3 users(A,B,C) Design
  - 3 files. User A writes to file-a. Changes are pushed to user-B,C.
  - 
