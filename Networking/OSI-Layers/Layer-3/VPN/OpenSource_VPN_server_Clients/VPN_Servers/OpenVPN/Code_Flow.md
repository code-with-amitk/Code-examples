## Code flow of openvpn server
```c
1. Generate Diffie-Hellman Parameters using openssl to be used by openssl to perform DH key exchange.(# openssl dhparam -out dh2048.pem 2048). Provide in server.conf
    |- DH is public/pvt keypair generation method. dh2048.pem contains prime number to be used for going a head with DH key exchange.
2. Select a cipher = AES-256-CBC
    |- AES is secret key method. later on openvpn server and client will negotiate this cipher inside DH key exchanged.
3. Initialize variables:
    proto = udp, local_port = 1194, connect_retry_seconds = 5, 
    ca_file = '/root/openvpn-2.4.8/certs_keys/CA.crt', priv_key_file = '/root/openvpn-2.4.8/certs_keys/CA.key'
openvpn_main()
 srandom(seed)    //Used for random no generation, while openssl uses complex method
    init_options(){mode=POINT_TO_POINT, proto=udp,retry_sec=5,max_retry=300,conn_timeout=120,
```
