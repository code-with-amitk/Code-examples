**32 bit system**:    Page-No(20 bits) + Offset(12 bits)    //anywhere offset is always 12 bit

- To access every bit of 64 kilibytes memory, we would need 16 bits. 2<sup>16</sup> = 65535 = 64KB
- 1 page=4KB=4096 bytes. 64x1024/4x1024 = 16 Pages. 64KB will have 16 pages.
- 2<sup>4</sup> = 16. With 4 bits we can access every 16 page.
- 2<sup>12</sup> = 4096. With 12 bits we can access every bit in page.
- **How Physical Address is converted to Virtual Address?**
  - Offset(12 bits) are copied as such. From Page-No(4 bit), frame number is constructed.
  
![ImgURL](https://i.ibb.co/86bzCf4/MMU-opearation.png)  
