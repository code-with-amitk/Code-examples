## Task
- Dump byte/word/dword as done by hexdump.

### Code
```c++
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<memory>
using namespace std;

class HexDump {
  const void* pBuffer;
  uint64_t Size;
  size_t type;  //Byte=0,word=1,dword=2

public:
  ostream& Dump(ostream& os);
  void DumpByte(ostream& os, const unsigned char *buf);
  void DumpWord(ostream& os, const unsigned char *buf);
  void DumpDWord(ostream& os, const unsigned char *buf);
  void SetContent(const void* a, uint64_t b, size_t c){
    pBuffer = a;
    Size = b;
    type = c;
  }
  friend ostream& operator << (ostream& out, HexDump& oHexDump) {
    return oHexDump.Dump(out);
  }
};
void HexDump::DumpByte(ostream& os, const unsigned char *buf) {
  os << std::setw(2) << std::setfill('0') << std::hex
     << static_cast<unsigned>(*buf) << ' ';
}
void HexDump::DumpWord(ostream& os, const unsigned char *buf) {
  os << std::setw(2) << std::setfill('0') << std::hex
     << static_cast<unsigned>(*(buf-1));
  os << std::setw(2) << std::setfill('0') << std::hex
     << static_cast<unsigned>(*buf) << ' ' << ' ';
}
ostream& HexDump::Dump(ostream& os) {
  bool bAddress = false;
  uint8_t* chTemp = new uint8_t[16];
  uint64_t j=0, n=0;
  const uint8_t *buf{reinterpret_cast<const uint8_t *>(pBuffer)};

  for (int i = 0; i<Size;  ++i, ++buf) {
      n = i+1;
      if(i == 0 or bAddress) {
        os << (void*)&buf[i] << ": ";
        bAddress = false;
      }
      if (type == 0) {
        DumpByte(os, buf);
        if(isalnum(*buf))
          chTemp[j]=*buf;
        else
          chTemp[j]='.';
        j++;
      } else if (type == 1 and n%2 == 0 and n>1) {
        DumpWord(os,buf);
      } else if(type == 2 and n%4 == 0 and n>1) {

        DumpDWord(os,buf);
      }
      if (n%16 == 0 and i!=0) {
        if (type == 0){
          //string str (reinterpret_cast<const uint8_t*>(chTemp),16);
          //os << str;
        }
        j = 0;
        os << endl;
        bAddress = true;
      }
  }
  os <<"\n";
}
int returnByteArray(uint8_t* k){
  //Created Byte Array//
  for(int i=0;i<16;i++){  *k++ = 0xff; }
  for(int i=0;i<16;i++){  *k++ = 0x0a; }
  for(int i=0;i<16;i++){  *k++ = 0x00; }
  for(int i=0;i<16;i++){  *k++ = 0xcd; }
  return 0;
}

int main(){

  //Created Byte Array//
  uint8_t* p = new uint8_t[64];   //uint8_t is 0-255. char is -127 to 128
  uint8_t* k = p;
  memset(p,'\0',64);

  returnByteArray(p);

  cout<<"Created Byte Array=\n";
  for (uint8_t i=0;i<32;i++)
    cout << std::hex << static_cast<unsigned>(p[i]) <<" ";
  cout<<"\n";
  for (uint8_t i=33;i<64;i++)
    cout << std::hex << static_cast<unsigned>(p[i]) <<" ";
  cout<<"\n\n";

  //cout<<HexDump(reinterpret_cast<const void*>(k),64,0);
  HexDump oHexDump;
  oHexDump.SetContent(reinterpret_cast<const void*>(k),64,2);
  cout<<oHexDump;
}
```

### Output
```c++
# g++ test.cpp
# ./a.out
0x7fffc7fb0e70: ffff  ffff  ffff  ffff  ffff  ffff  ffff  ffff
0x7fffc7fb0e90: 0a0a  0a0a  0a0a  0a0a  0a0a  0a0a  0a0a  0a0a
0x7fffc7fb0eb0: 0000  0000  0000  0000  0000  0000  0000  0000
0x7fffc7fb0ed0: cdcd  cdcd  cdcd  cdcd  cdcd  cdcd  cdcd  cdcd

# ./a.out
0x7fffec390e70: ffff  ffff  ffff  ffff  ffff  ffff  ffff  ffff
0x7fffec390e90: 0a0a  0a0a  0a0a  0a0a  0a0a  0a0a  0a0a  0a0a
0x7fffec390eb0: 0000  0000  0000  0000  0000  0000  0000  0000
0x7fffec390ed0: cdcd  cdcd  cdcd  cdcd  cdcd  cdcd  cdcd  cdcd

# ./a.out
0x7ffff243de70: ffffffff    ffffffff    ffffffff    ffffffff
0x7ffff243de90: 0a0a0a0a    0a0a0a0a    0a0a0a0a    0a0a0a0a
0x7ffff243deb0: 00000000    00000000    00000000    00000000
0x7ffff243ded0: cdcdcdcd    cdcdcdcd    cdcdcdcd    cdcdcdcd
```
