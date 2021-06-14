## Fake account?
- **What** Amit has opened account with name as Tushar. Amit uploads fake pic/no pic. 

### 1. Fake account at time of creation:
- **1a. How to identify** 
  - *1.* Registration using default values
  - *2.* 5+ registration from same IP address
  - *3.* Any of security attacks
- **1b. How to stop** This detection can be done at CDN(waf or sheild).

### 2. Exisiting Fake account: (monitoring traffic)
- **2a. How to identify**
  - *1.* User uploading vulgur/voilent/controversial videos/images on his account
  - *2.* sending 100's of friend requests/min(maybe bot)
  - *3.* constantly updating timeline(may be bot)
  - *4.* forged/corped pictures. half cutted/vulgar profile pictures.
  - *5.* The profile has very few pictures or no actual picture of a person at all.
  - *6.* It was created recently – in the past year or two. Unless the person is very young, most of us opened our Facebook accounts in 2006-2007.
  - *7.* Little or no contacts in common. When the profile has nothing in common with you such as friends or even a professional interest, and they are trying to add you, it’s likely for malicious reasons.
  - *8.* When a profile adds you but once you accept them, there is no more interaction with that user. He/she wanted and will avoid talking to you in the hopes you forget about it. so that he can monitor your activities.

- **2b. Reauthenticating Existing Fake Account**
  - *1.* Upload very clear picture of face. AI(opencv) will detect and compare in DB. DB will store Hash of images. Authenticating images are not stored.
  - *2.* Provide Identity proof: Driving license, Green card, Electricity Bill, Bank statement etc

## Design
### 1. Fake account creation
- *1a.* At CDN(waf, shield) detectes Malicious activity & Block IP address.
### 2. Existing Fake account
- *2a.* User/Bot logs into account
- *2b.* KDC(Key distribution center) validate password-Hash, provides TGT. Authentication successful.
- *2c.* User/Bot uploads obscene Photo
- *2d.* Via CDN Unique-user-id, obscene-photo.jpg sent to Application/Web server
- *2d.* UserId, photo.jpg stored at Temporary Object Store (amazon S3)
- *2d.* Message sent back to user " After checking, Will upload"
- *2e.* AI algorithm runs on Object store periodically and detects Obscene
- *2f.* userId, obscene-photo.jpg stored at specified directory `/usr/local/obscene/userId,photo.jpg
- *2g.* Fetcher service fetches userId,obscene-photo.jpg and places on MOM(message oriented middleware)
- *2h.* Updater picks userId, obscene.jpg from MOM & updates SQL DB
- *2i.* Updater also updates system logs.
- *2k.* Combine & Derive(Sagemaker) does prediction or he's normal user
- *2j.* Notification service sends following message to user photo.jpg is obscene, Please authenticate you are not Bot.

![ImgURL](fb-fakeaccount-detect.png)
