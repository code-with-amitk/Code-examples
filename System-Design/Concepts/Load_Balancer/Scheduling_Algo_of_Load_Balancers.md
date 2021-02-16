## Scheduling Algorithms at Load Balancers
- **1. ROUND ROBIN:**    Send request one after other.
- **2. LEAST CONNECTIONS:** Sends requests to the server with the lowest number of active connections.
- **3. LEAST TIME:** Sends requests to the server selected by a formula that combines the fastest response time and fewest active connections.
- **4. HASH:** Distributes requests based on a key you define, such as the client IP address or the request URL.
- **5. IP HASH:** (HTTP only) – Distributes requests based on the first three octets of the client IP address.
- **6. RANDOM WITH 2 CHOICES:** Picks two servers at random and sends the request to the one that is selected by then applying the Least Connections algorithm.
