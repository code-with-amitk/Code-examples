- [What is UUID](#what)
- [GUID vs SID](#vs)

<a name=what></a>
## UUID / Universally Unique Identifier / GUID / Globally Unique Identifier
- 128 bit(16 byte) string which is Unique identifier of a object. GUID never changes, even when the object is renamed or moved. Every object is assigned a GUID.

<a name=sid></a>
## GUID vs SID? 
- SID may sometimes change but GUID never.

<a name=format></a>
## GUID Format
```c
24121598  -   1599    -           4a09         -                   8f5d                -  a2d75d747829
time-low  - time-mid  - time-high-and-version  - clock-seq-and-reserved clock-seq-low  -  node
time_low(The low field of the timestamp) 
time_mid(Middle filed of timestamp)
time_hi_and_version(The high field of the timestamp multiplexed with the version number)
clock_seq_hi_and_reserved(The high field of the clock sequence multiplexed with the variant)
clock_seq_low(The low field of the clock sequence), mode(Spatially unique node identifier)
node: 
    Ver-3 and 5: Algo is defined here: https://tools.ietf.org/html/rfc4122#section-4.3
    Ver-4: is a randomly or pseudo-randomly generated 48-bit value
```
