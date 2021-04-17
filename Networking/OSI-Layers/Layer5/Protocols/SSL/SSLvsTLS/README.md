## SSL vs TLS

||SSL(predecessor of TLS)|TLS|
|---|---|---|
|Versions|v2,v3|<ul><li>v1(based on sslv3)</li></ul> <ul><li>v1.2(2008)</li></ul> <ul><li>v1.3(2018 to present): MD5,SHA224 support removed. Handshake messages not encrypted after "Server-hello".</li></ul>|
|Why||Lot of security vulnerabilities were found in SSL|
|Encryption Algo's||Stronger wrt SSL|
|On-Record-Layer|Uses MAC|Uses HMAC|
|Vulnerabilities present|POODLE,DROWN||
