## inline namespace
### What
- Members of an inline namespace are treated as if they are members of the enclosing namespace
- inline may appear in front of every namespace name except the first.

### Syntax
```  
inline namespace ns_name { declarations }
```

### Example
```
inline namespace A{
        int a = 10;
}

int main(){
        cout<<A::a;     //10
}
```
