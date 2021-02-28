## Advantages of HTTP
- *1. Flexible.* Whenever there are additional capabilities needed by an application, HTTP has the capability to extend. These can include Flash players and Acrobat reader.
- *2. Less connections.* With [HTTP2 and HTTP3](HTTPv1_v2_v3.md) multiple requests can be sent in 1 packet.
- *3. Network BW:* Less dues to less connections as [HTTP2, HTTP3](HTTPv1_v2_v3.mdd) sends multiple requests in 1 connection.
- *4. Error reporting:* Reports errors without closing the TCP connection.

## Disadvantages of HTTP
- *1.* Can only be used for point to point connection.
- *2.* Does not have push capabilities as in [Long Pooling or server sent Events](/Networking/OSI-Layers/Layer5/WebServer_to_WebClient_Connection_Methods).
- *3.* [HTTPv2](HTTPv1_v2_v3.md) does not offer reliable exchange (without retry logic).
