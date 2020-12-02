## What is fake account?
- *1.* Amit has opened account with name as Tushar. Amit uploads fake pic/no pic. 

## 1. Fake account at time of creation:
### 1a. How to identify
- *1.* Registration using default values
- *2.* 5+ registration from same IP address
- *3.* Any of security attacks
### 1b. How to stop
- This detection can be done at CDN(waf or sheild).

## 2. Exisiting Fake account: (monitoring traffic)
### 2a. How to identify
- *1.* User uploading vulgur/voilent/controversial videos/images on his account
- *2.* sending 100's of friend requests/min(maybe bot)
- *3.* constantly updating timeline(may be bot)
- *4.* forged/corped pictures. half cutted/vulgar profile pictures.
- *5.* The profile has very few pictures or no actual picture of a person at all.
- *6.* It was created recently – in the past year or two. Unless the person is very young, most of us opened our Facebook accounts in 2006-2007.
- *7.* Little or no contacts in common. When the profile has nothing in common with you such as friends or even a professional interest, and they are trying to add you, it’s likely for malicious reasons.
- *8.* When a profile adds you but once you accept them, there is no more interaction with that user. He/she wanted and will avoid talking to you in the hopes you forget about it. so that he can monitor your activities.

### 2b. Reauthenticating Existing Fake Account
- *1.* Upload very clear picture of face. AI(opencv) will detect and compare in DB. DB will store Hash of images. Authenticating images are not stored.
- *2.* Provide Identity proof: Driving license, Green card, Electricity Bill, Bank statement etc
