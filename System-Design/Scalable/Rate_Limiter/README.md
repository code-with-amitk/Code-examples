**Rate Limiter**

### Rate Limiter
- Rate limiter blocks bots, or applications to overload web server(DoS Attack). Rate limiting can stop certain kinds of bot attacks.
- Because Application server has a limit to server x number of connections/sec. if more connections comes in server can crash.

<a name=r></a>
### Requirements
#### Functional
- _1._ System handles 50 requests/sec.
- _2._ System should return error if more than 50 requests are sent.
#### Non-Functional
Highly available, Latency should be minimum.
