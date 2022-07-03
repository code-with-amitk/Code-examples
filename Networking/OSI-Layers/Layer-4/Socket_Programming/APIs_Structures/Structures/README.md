### addrinfo
This is used to prepare the socket address structures which would be used subsequently.
```c
struct addrinfo{
    int ai_flags;    //AI_PASSIVE, AI_CANONNAME etc.
    int ai_family;    //AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype;    //SOCK_STREAM, SOCK_DGRAM
    int ai_protocol;    //0 for any.
    size_t ai_addrlen;    //size of ai_addr
    struct sockaddr *ai_addr;    //struct sockaddr_in or _in6     
    char *ai_canonname    //Full Cannonical Name
    struct addrinfo *ai_next;    //Linked List next node
};
```
### sockaddr_in, IPv4 only
```c
struct sockaddr_in {
    short int          sin_family;  // Address family, AF_INET
    unsigned short int sin_port;    // Port number
    struct in_addr     sin_addr;    // Internet address
    unsigned char      sin_zero[8]; // Same size as struct sockaddr
}; 
```
### sockaddr_in6
```c
struct sockaddr_in6 {
    u_int16_t       sin6_family;   // address family, AF_INET6
    u_int16_t       sin6_port;     // port number, Network Byte Order
    u_int32_t       sin6_flowinfo; // IPv6 flow information
    struct in6_addr sin6_addr;     // IPv6 address
    u_int32_t       sin6_scope_id; // Scope ID
};
struct in6_addr {
    unsigned char   s6_addr[16];   // IPv6 address
}; 
```
