## IPv4 and v6 Data Structure
```c
typedef enum { 
    IP_VERSION_4,
    IP_VERSION_6,
    
    IP_VERSION_LAST /* this must be the last IP_VERSION */
} ip_version_type;

typedef struct in6_addr {
    union {
        uint64_t _S6_u64[2];
        uint32_t _S6_u32[4];
        uint16_t _S6_u16[8];
        uint8_t _S6_u8[16];
    } _S6_un;
} in6_addr_t;

typedef struct test    in46_addr_t_ {
    ip_version_type ip_version;
    union {
        in_addr_t  v4;                 //typedef uint32_t           in_addr_t;
        in6_addr_t v6;    
    } u;
} in46_addr_t;
```
