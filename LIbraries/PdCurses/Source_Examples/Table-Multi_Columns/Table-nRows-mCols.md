## Creating n Row, m cols
- Example code
```c

//1. Take menu items to be displayed. size=4
char *choices[] = {"Value", "GPU1", "GPU2", (char*)NULL};   //Array of Pointer to char

//2. Allocate array of ITEM structures, equal to menu items
ITEM** my_items = (ITEM**) calloc(4, sizeof(ITEM*));

int main(){
  //ITEM *new_item(const char *name, const char *description);
  //What? Allocate new item(pointed by name) for menu. Note: caller must have allocated array either on his stack/heap.
  //Arguments:
  //  const char* name:
  //  const char* des:
  //Return:
  //  struct ITEM*: Pointer to ITEM structure //See Structures.md

  //3. Fill item structures using new_item() API.
  for (i=0; i<4; ++i)
    my_items[i] = new_item(choices[i], choices[i]);
```
