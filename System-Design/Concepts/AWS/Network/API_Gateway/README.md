**API Gateway = Rate limiter, SSL Terminator, IP Whitelister**

### API Gateway
- Developers create HTTP/[REST APIs](/Networking/OSI-Layers/Layer-7/WebServer_WebClient_WebService/WebClient_Connecting_WebServer/REST/), Webhooks, websockets. API G/W runs on EC2 & exposes publicly addressable web service.
- APIs can connect back-end systems as mobile, web, and server applications or services.
- CloudFront integrates with API Gateway for users to access APIs.

#### API G/w supports
- Rate limiting, SSL termination, authentication, IP whitelisting, servicing static content, etc.

