## netstat
- Print network connections, routing tables, interface statistics, masquerade connections, and multicast memberships
- **Options**
  - *-p:* show pid
  - *-a*: all interfaces
  - *-n:* show Numeric
  - *-t:* tcp
  - *-u:* udp

### Commands
- *1. Show TCP/UDP statistics of all interfaces:* `# netstat  -plunt`
- *2. Get number of active connections:* `# netstat -ant | awk '{print $NF}' | grep -v '[a-z]' | sort | uniq -c`
- *3. Get number of connections per ip address:* `# netstat -ntu | awk '{print $5}' | cut -d: -f1 | sort | uniq -c | sort -n`
- *4. Get all IP Address connected to your host:* `# netstat -lantp | grep ESTABLISHED |awk '{print $5}' | awk -F: '{print $1}' | sort -u`
- *5. Monitor open connection to web server on port 80, count and sort it by IP:* `# watch "netstat -plan|grep :80|awk {'print \$5'} | cut -d: -f 1 | sort | uniq -c | sort -nk 1"`
```
