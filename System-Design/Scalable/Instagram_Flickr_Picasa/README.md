## [To Cover](/System-Design/Scalable)

**What is Instagram?** 
  - Photo,Video sharing service here users can upload photos to share them with other users.
  - Content can be shared publicly or privately.
  - **News Feed** consist of top photos of all the people the user follows.
  - **Read Heavy** This is read heavy system Read:Write=100:1

## 1. Requirements
- **Functional**
  - *1.* Users should be able to upload/download/view photos.
  - *2.* Users can perform search based on photo/video titles.
  - *3.* Users can follow other users.
  - *4.* Can see news feed.
- **Non-functional**
  - Availabe. Low Latency, Consistent, Reliable(any uploaded photo or video should never be lost)
- **Extended**
  - Adding tags
  - Commenting on photos

## 2. BOE

|World Population|Daily Internet Users(30%)|Instagram Users(20% of Internet users)|(1%)Active users Daily|Each User upload 1 photo daily|Photos/sec|
|---|---|---|---|---|---|
|7x10<sup>9</sup>//Year 2020|7B x .3 =~ 2 Billion|2B x .2 = 400 Million|4 Million|4M Photos uploaded daily|4M/24 x 60 x 60 = 4Photos/sec|

- **Storage Estimates:** 1 Photo size=200KB. 1 day = 4M x 200KB = 800 GB. 5 years = 800G x30x12x5 = 1440TB
- **Traffic Estimates:** Upload = 800GB/day. 800G/24x60x60=9MB/sec incoming

## 3. HLD

**Steps: User uploading his photos**
- *1-6.* Same as [Facebook news feed](/System-Design/Scalable/facebook/News%20Feed).
- *7.* Application server will forward photos to DB Updater(in some other Datacenter).
- *8.* Photos will be stored on [Object Store DB](/System-Design/Concepts/Databases)
