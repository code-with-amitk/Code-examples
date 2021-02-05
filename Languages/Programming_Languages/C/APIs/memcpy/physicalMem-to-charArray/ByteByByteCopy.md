## Dumping RAM/Physical Memory to buffer

## Logic
1. Machine Address is unsigned long long(8 byte). `unsinged long ma = 18294175360`
2. Make a `void *` point towards local variable storing machine address

|ActualContent->| 0A| 43 | FF| .. | 
| --- | --- | --- | --- | --- |
|MachineAdd->| 18294175360 | 18294175361 | 18294175362 | 18294175363 |

Local Variable
| 18294175360 |
| --- |
| uint_64 ma |
> Address of Local variable = 404

| 404 |
| --- |
| void `*`data |

3. Typecast the machine address to `unsigned char *`.
   - This means now machine address would be used as index in character array.
   - Access the contents at Machine address using `((unsigned char*)machine-address)[i]`
   
### Code
```C
void dump_to_buffer(void *data, unsigned int len){

  unsigned long i;
  char *buffer = malloc(sizeof(char)*(len+1));
  
  for(i=0;i<len;i++){                            //Dumps every byte by byte
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
