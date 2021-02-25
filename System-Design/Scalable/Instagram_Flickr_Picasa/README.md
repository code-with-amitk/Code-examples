## [To Cover](/System-Design/Scalable)

**What is Instagram?** 
  - Photo,Video sharing service here users can upload photos to share them with other users.
  - Content can be shared publicly or privately.
  - **News Feed** consist of top photos of all the people the user follows.
  - **Read Heavy** This is read heavy system Read:Write=100:1

## Requirements
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

## BOE
