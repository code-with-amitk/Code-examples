## Long Pooling vs Web Sockets

||Normal Pooling|Long Pooling|Web Sockets|
|---|---|---|---|
|What|<ul><li>Web client repeatedly pools web server for data</li></ul><ul><li>Implemented using XMLHttpRequest or JSON</li></ul>|<ul><li>server holds client’s connection open for as long as possible</li></ul><ul><li>Data is delivered to web client once becomes available or threshold timer expired</li></ul>|<ul><li>Full duplex bidirectional data transfer</li></ul><ul><li>Enhanced version of Http,can work over TCP</li></ul>|
|Disadv/Adv|lot of BW and resource wastage|Fd is holded for long time, may block server|This is best alternative among others.|
