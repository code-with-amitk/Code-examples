**Problem: Take a image file(abba.png), Draw rectangle around faces on the image**
- [Steps](#s)
- [Code](#c)

<a name=s></a>
### Steps

| Steps/Functions | What it does | Returns |
| --- | --- | --- |
| 1. import cv2 | import opencv library | |
| 2. `<CascadeClassifier object>	=	cv.CascadeClassifier(filename)` | <ul><li>Load a cascade classifier from xml file</li></ul> <ul><li>Remember, the cascade is just an XML file that contains the data to detect faces</li></ul> | Classifier object |
| 3. `cv2.imread(filename[, flags])` | <ul><li>Load an image from the specified file</li></ul> <ul><li>We will detect **faces** from this image file</li></ul> | Image that is loaded from specified file |
| 4. `dst	=	cv.cvtColor(	src, code[, dst[, dstCn]]`	)| <ul><li>Converts image from one color space to another</li></ul> <ul><li>COLOR_BGR2GRAY=convert from RGB/BGR to grayscale</li></ul> <ul><li>Many operations in OpenCV are done in grayscale</li></ul>| |
| 5. `CascadeClassifier::detectMultiScale` | <ul><li>Detects objects of different sizes in the input image.</li></ul> | <ul><li>List of rectangles, in which it believes it found a face</li></ul> <ul><li>This function returns 4 values: `x`, `y` location of the rectangle, rectangle’s width and height `w , h`|
| 6. `cv2.rectangle()` | draw a rectangle on any image |  returns an image |

<a name=c></a>
### Complete source code
> [CODE-ON-GITHUB](https://github.com/shantnu/FaceDetect/)
```py
import cv2                                            //1
import sys

faceCascadeObject = 
  cv2.CascadeClassifier("haarcascade_frontalface_default.xml") //2

image = cv2.imread(sys.argv[1])                       //3 Parameter: Image file
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)        //4

faces = faceCascade.detectMultiScale(       //5
    gray,                                   //grayscale image
    scaleFactor=1.1,                        //some faces may be closer to camera, they would appear bigger than faces at back. scale factor compensates for this.
    minNeighbors=5,                         //how many objects are detected near the current one using moving Window
    minSize=(30, 30),                       //gives the size of each window
    flags = cv2.cv.CV_HAAR_SCALE_IMAGE
)

print("Found {0} faces!".format(len(faces)))

# Draw a rectangle around the faces
for (x, y, w, h) in faces:
    cv2.rectangle(                    //6
      image,                          //It is the image on which rectangle is to be drawn.
      (x, y),                         //Starting coordinates of rectangle. (X coordinate value, Y coordinate value).
      (x+w, y+h),                     //Ending coordinates of rectangle. (X coordinate value, Y coordinate value).
      (0, 255, 0),                    //Color of border line of rectangle. For BGR, we pass a tuple. eg: (255, 0, 0) for blue color.
      2)                              //Thickness of the rectangle border line in px.

cv2.imshow("Faces found", image)
cv2.waitKey(0)
```
