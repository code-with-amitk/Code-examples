Terms
- [Cookie](#cok)
- [Inbound, Outbound Requests](#io)
- [Intermediaries: proxy, gateway, and tunnel](#int)
- Origin server
- [PAC File](#pac)
- User Agent

## Terms
<a name=cok></a>
### HTTP Cookie / Web cookie / Internet cookie / browser cookie
This is a file _created by Web browser_ & placed on the user's computer.
- **why?** Web Server asks web browser to store some information locally.
  - So that when Web Browser again queries web server, Web server can identify, Whether it's same web browser or different, Whether it's same information asked by web browser or different.
  - To track the user's browsing activity(clicking particular buttons, recording which pages were visited in the past, User Preferences).
  - Saving info user entered in forms: names, addresses, passwords(stored as hashed), and payment card numbers.
```c
  Web Browser                                   Web server
         -- GET /sample_page.html HTTP/2.0 ->
            Host: www.example.org
	    
         <------- HTTP/2.0 200 OK---------------
                 Content-Type: text/html
                 Set-Cookie: yummy_cookie=choco       //Store cookie
                 Set-Cookie: tasty_cookie=strawberry
                 [page content]
		 
 store information
 in Cookie file
```
- **Where Cookie is stored on my Computer?**
  - _Path:_ "C:\Users\user_name\AppData\Local\Google\Chrome\User Data\Default\Network\Cookie(SQL Lite DB)"
  - _In Browser:_ Right-click on your browser window > Inspect > Applications tab > Cookies > Check installed cookies
```c
# cat "C:\Users\user_name\AppData\Local\Google\Chrome\User Data\Default\Network\Cookie"
creation_utc      top_frame_site_key  host_key      name  encrypted_value  path    expires_utc     secure httponly  last_access_utc  expires persistent  priority
13268758066855308		    .microsoft.com  MC1    129109aksknz1   /    13300294067855308   1	    0      13292307116001488  1        1          0
```
- **Stolen Cookie?** If hacker steals and installs your cookies into their web browser, hacker will get access your account.
  - _How cookie theaft can be avoided?_ Cleaning cookies every 7-14 days.

<a name=io></a>
### Inbound, Outbound Requests
 - inbound means "toward the origin server"
 - outbound means "toward the user agent".

<a name=os></a>
### Origin Server
Program that can provide authoritative responses to HTTP client

<a name=pac></a>
### PAC(proxy auto-configuration) File
- This is a Javascript file that instructs a browser to forward traffic to a particular [proxy server](/System-Design/Concepts/Proxy_Servers), instead of directly to the destination server. All browsers support PAC File.
- This configures [Explicit Proxy](/System-Design/Concepts/Proxy_Servers/#exp) in browser.
- **Limitations of PAC**
  - Can only send web traffic, not other(eg: video, audio).
  - Admin user can change proxy address(to which requests need to go) in PAC. Also admin can completely disable it.
```c
//Example of PAC File
function FindProxyForURL(url, host) {

// If the hostname matches, send direct.
	if (dnsDomainIs(host, "intranet.domain.com"))
		return "DIRECT";

// If the protocol or URL matches, send direct.
	if (url.substring(0, 4)=="ftp:")
		return "DIRECT";

// If the requested website is hosted within the internal network, send direct.
	if (isPlainHostName(host) ||
		isInNet(dnsResolve(host), "10.0.0.0", "255.0.0.0") ||
		isInNet(dnsResolve(host), "172.16.0.0",  "255.240.0.0") ||
		isInNet(dnsResolve(host), "192.168.0.0",  "255.255.0.0") ||
		isInNet(dnsResolve(host), "127.0.0.0", "255.255.255.0"))
		return "DIRECT";

// If the IP address of the local machine is within a defined
// subnet, send to a specific proxy.
	if (isInNet(myIpAddress(), "10.10.5.0", "255.255.255.0"))
		return "PROXY 1.2.3.4:8080";

// DEFAULT RULE: All other traffic, use below proxies, in fail-over order.
	return "PROXY 4.5.6.7:8080; PROXY 7.8.9.10:8080";

}
```

<a name=ua></a>
### User Agent
Any client programs that initiate a HTTP request.

<a name=int></a>
### Intermediaries
```c
UA ======Proxy=====Tunnel======Reverse_Proxy====== OS
```
#### Proxy
- A "proxy" is a message-forwarding agent that is chosen by the client, usually via local configuration.
- Some proxies are designed to apply transformations to selected messages or content while they are being forwarded

#### Gateway (or Reverse Proxy)
- Acts as an [origin server](#os) for the outbound connection but translates received requests and forwards them inbound to another server or servers.

#### Tunnel
- A blind relay between 2 connections without changing the messages.

