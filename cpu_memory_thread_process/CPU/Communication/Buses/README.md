## Comparison

|Bus|I<sup>2</sup>C|SMBus(System Management Bus)|PMBus(Power Management Bus)|
|---|---|---|---|
|Developed by|Philips(1982)|Intel(1995)|Intel|
|Wire|2|2|2|
|Latest Rev||SMBus 3.1(2018)|PMBus 1.3|
|What|Oldest|Superset of I<sup>2</sup>C|Superset of SMBus. Defines domain specific commands|
|Max Speed||100Khz|400KHz|
|Max Block Size||32 Bytes|255 Bytes|
|Compared to OSI Layer|Physical Layer|Phy+DL+N/W|Phy+DL+N/W+Transport Layer|
|Addresses|7 bit(1 device can have multiple addresses)|same as I2C||
|Components to connect|sensors, clocks, EEPROM|||
|Working Principle|Slaves,Master. Multimaster supported.|Same as I2C||
|Disadv|Low bandwidth(less data can be sent), short distance, slow, Max speed:400kbps(around)|||
|Adv|Simple|||

