## PUP / Pack Unpack
- **What?** Used between communicating peers (Eg: client server on internet).
- **How?** There is a single function named "pup" can both send or receive an object.Since it's the same code on both sides, a mismatch between send and receive is much harder.

- **[Example](https://www.cs.uaf.edu/courses/cs441/notes/protocols/)**
```c
class sender {
	SOCKET s;
public:
	sender(SOCKET s_) :s(s_) {}
  
	friend void pup (send_PUPer &p,char &v) { 
    skt_send (p.s,&v,sizeof(v)); 
  }
};

class Reciever {
	SOCKET s;
public:
	Reciever(SOCKET s_) :s(s_) {}
  
	friend void pup(recv_PUPer &p,char &v) { 
    skt_recv (p.s,&v,sizeof(v)); 
  }
};
```
