## Dumping RAM/Physical Memory to buffer

```C
void dump_to_buffer(void *data, unsigned int len){
  char *buffer = malloc(sizeof(char)*(len+1));
  unsigned long i;
  for(i=0;i<len;i++){       //Dumps every byte by byte
    buffer[i] = ((unsigned char*)data)[i];
  }
  buffer[i]=`\0`;
}

int main(){
  uint64_t ma;    //Unsigned long for storing machine address
  <<<Code gets machine address>>
  dump_to_buffer(&ma, 1024);
}
```
