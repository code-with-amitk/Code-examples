## [Designing](https://www.cs.uaf.edu/courses/cs441/notes/protocols/)
- *1.* Decide on [Endianess](/Languages/Programming_Languages/C/Bitwise) to be used stay to it. or Header can include endianess information.
- *2.* Understand object sizes such as long=4 or 8 bytes, or varying field [alignment requirements, padding](https://sites.google.com/site/amitinterviewpreparation/c-1).
- *3.* Use [PUP, PackUnpack design pattern](/Languages/Programming_Languages/c++/Design_Pattens/Behavioral/PUP_Pack_Unpack)
- *4.* We cannot send std::string, std::vector on network as such.
  - [std::string](/Languages/Programming_Languages/c++/Libraries_FileHandling/Strings) stores pointer internally.
  - Same as std::vector, std::map
```c
//////Crashes////////
  std::string str="amit";
	skt_send (s,&str,sizeof(str));

//////CORRECT WAY//////////
  //Send side:
	  std::string str="amit";
	  int length = str.length();
	  skt_send (s,&length,sizeof(length)); // OK because length is an integer
	  skt_send (s,&str[0],length); // OK because now we're sending the string *data*

  // Receive side:
	  std::string str="";
	  int length=0;
	  skt_recv (s,&length,sizeof(length)); // OK because length is an integer
	  str.resize (length);
	  skt_recv (s,&str[0],length); // OK because we reallocated the string
```
- *5.* **Overall**
  - Total up the size of data to be sent, allocate once and send.  This is the fastest way to send network data.
  - Read and write the objects from disk.
  - Monitor objects for changes, using a checksum.
  - Randomly inject bit errors (to determine noise).
  - Convert C++ objects to and from XML or JSON serialized representations.
  - Build an HTML web page listing the object values, and allow browser-based changes to any object field.
