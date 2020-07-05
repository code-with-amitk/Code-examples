# OPENCV

## Basic Information
  - **What** opensource library for image processing, recognizance.
  - **How it works**
    - OpenCV uses machine learning algorithms to search for faces within a picture
    - There are thousands of small patterns and features that must be matched. 
  - **Classifiers** 
    - Breaking bigger task of face recognizance into smaller tasks. These smaller tasks are called classifiers.
    - For a face, we can have 6000+ Classifiers.
    - The algorithm starts at the top left of a picture and moves down across small blocks of data, 
      looking at each block and matching, constantly asking, “Is this a face?”
  - **Cascades/Stages**
    - Cascade dictionary meaning is waterfall.
    - Breaking the problem of detecting faces into multiple stages. There canbe 30-50 cascades.
    - The cascades themselves are **just a bunch of XML files** that contain OpenCV data used to detect objects.
    
## Installation
### Ubuntu
```
# sudo apt update
# sudo apt install python3-pip
# sudo apt install python3-opencv
```
    
