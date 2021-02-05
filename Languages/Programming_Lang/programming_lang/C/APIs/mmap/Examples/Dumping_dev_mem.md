## Reading from /dev/mem
- **What is /dev/mem**
  - This is a character device file that is an image of the main/Phsical memory of the computer.
  - ie when we read */dev/mem* we are reading/writing to System's main Memory!!
  - But many linux distributions have stopped providing /dev/mem due to security concerns.
- **Why reading from System memory**
  - System's startup(BIOS), PCI Configuration Space(ACPI,XSDT,MCFG tables) are stored on physical memory.
  - if process want to read PCI config space it should read /dev/mem.

### Code
- Tasks
  - Maps 128KB starting at (offset=917504) from "/dev/mem" to memory `*ptr`
  - Dump and print contents of `ptr`

```c++
using uint64 = unsigned long long;
uint64 ullPhysicalAddress = 0xe0000;  //917504  Multiple of 4KB
uint64 ullLength = 131'072;           //128KB = 1024*128

int fd;
void openDevMem(){
  fd = open("/dev/mem", O_RDWR|O_SYNC);       //TBD:Error checking
}

void mapMemory(uint64& ullMappedVirtualAdd, uint64& ullMappedVirtualAddLen){

  //Aligning start address to 4KB alignment. Since pages are 4KB
  uint64 ullStartMappingFrom = ullPhysicalAddress & ~(4096 -1);
  
  //Aligning length in 4kb boundary
  uint64 ullLengthOfMapping = ((ullPhysicalAddress + ullLength + 4096-1) & ~(4096 -1) - ullPhysicalAddress;
  
  void *ptr = mmap(0, ullLengthOfMapping, PORT_READ|PORT_WRITE, MAP_SHARED, fd, ullStartMappingFrom);
  
  if (ptr != MAP_FAILED){
    ullMappedVirtualAdd = (uint64)ptr + (ullPhysicalAddress & ~(4096 -1));  
    ullMappedVirtualAddLen = ullLengthOfMapping;
  }
}

int main(){
  uint64 ullMappedVirtualAdd, ullMappedVirtualAddLen;
  openDevMem();
  mapMemory((uint64 &)(ullMappedVirtualAdd),(uint64 &)(ullMappedVirtualAddLen));
  
  //Convert to char* Dump or use
  char *pcStart = (char*) ullMappedVirtualAdd;
}
```
