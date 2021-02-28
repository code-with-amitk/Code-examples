## FrameBuffer
- if we have 1024x768 resolution screen. Frame buffer is a 2-D array of same size in RAM(or in video memory). Each location in array corresponds to pixel on screen.
- Whichever pixel we want to illuminate, that is set to `1` inside Framebuffer.
- Example: Let's consider pixel 100x100 need to be illuminated.
  - In framebuffer `fb[100][100]=1`
  - CPU scans the framebuffer, once it finds value=1. Fills it in register.
  - DAC(Digital Analog Controller) is used to control the electron gun's movement.
  - Electron-Gun will emit the light on screen at position 100x100
  
![ImgURL](https://i.ibb.co/CvTJwFb/framebuffer.png)  
