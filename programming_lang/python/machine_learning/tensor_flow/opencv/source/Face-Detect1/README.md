## Task
- Take a image file(abba.png)
- 

## A. Steps

| Steps/Functions | What it does | Parameter(s) | Return | Syntax |
| --- | --- | --- | --- | --- |
| 1. import cv2 | import opencv library | | | |
| 2. object = cv2.CascadeClassifier(cascadeFile.xml) | <ul><li>Load a cascade classifier from xml file</li></ul> <ul><li>Remember, the cascade is just an XML file that contains the data to detect faces</li></ul> | Classifier object | <CascadeClassifier object>	=	cv.CascadeClassifier(	filename	) |
| 3. cv2.imread(imageFile.png) | <ul><li>Load an image from the specified file</li></ul> <ul><li>We will detect **faces** from this image file</li></ul> | imageFile | Image that is loaded from specified file | 
  
## B. Complete source code
```
import cv2                                            //1
import sys

faceCascadeObject = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")    //2

# Read the image
image = cv2.imread(sys.argv[1])                       //3
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Detect faces in the image
faces = faceCascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30, 30),
    flags = cv2.cv.CV_HAAR_SCALE_IMAGE
)

print("Found {0} faces!".format(len(faces)))

# Draw a rectangle around the faces
for (x, y, w, h) in faces:
    cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)

cv2.imshow("Faces found", image)
cv2.waitKey(0)
```


