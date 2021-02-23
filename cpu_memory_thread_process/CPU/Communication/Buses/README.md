## Comparison

|Bus>|I<sup>2</sup>C(2 wire bus)|SMBus(2 wire bus)|PMBus|
|---|---|---|---|
|Developed by|Philips(1982)|Intel(1995)||
|What|Oldest|Superset of I<sup>2</sup>C|Superset of SMBus|
|Compared to OSI Layer|Physical Layer|Phy+DL+N/W|Phy+DL+N/W+Transport Layer|
|Addresses|7 bit(1 device can have multiple addresses)|same as I2C||
|Components to connect|sensors, clocks, EEPROM|||
|Working Principle|Slaves,Master. Multimaster supported.|Same as I2C||
|Disadv|Low bandwidth(less data can be sent), short distance, slow, Max speed:400kbps(around)|||
|Adv|Simple|||

