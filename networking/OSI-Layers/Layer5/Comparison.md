## Long Pooling vs Web Sockets

||Normal Pooling|Long Pooling|Web Sockets|
|---|---|---|---|
|What|Web client repeatedly pools web server for data|<ul><li>server holds client’s connection open for as long as possible</li></ul><ul><li>Data is delivered to web client once becomes available or threshold timer expired</li></ul>||
|Disadv|lot of BW and resource wastage|||
