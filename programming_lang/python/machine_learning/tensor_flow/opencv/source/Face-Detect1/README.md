## Complete source code
```
import cv2                                            //1
import sys

faceCascade = cv2.CascadeClassifier("haarcascade_frontalface_default.xml")    //2

# Read the image
image = cv2.imread(sys.argv[1])                       //2
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

## Steps
  1. import opencv library
  2. Load a cascade classifier from a file. This classifier is used for parsing the image.
     - Remember, the cascade is just an XML file that contains the data to detect faces.
```
class CascadeClassifier{
public:
  CascadeClassifier(const string& filename){      //filename – Name of the file from which the classifier is loaded.
  }
}
```
  3. Get Image file from command line. We will detect **faces** from this image file.
     - Pass the xml file into `CascadeClassifier` function.
  4. 
