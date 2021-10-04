**asio / async IO**
- [1. HTTP GET homepage from web-server](#e1)

## asio
For asynchronous network and low-level I/O programming.

<a name=e1></a>
#### 1. HTTP GET homepage from web-server
Create [Visual Studio project and link boost to it](/Languages/Programming_Languages/c++/boost/).
```cpp
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::resolver resolv{ ioservice };
tcp::socket tcp_socket{ ioservice };
std::array<char, 4096> bytes;

void read_handler(const boost::system::error_code& ec, std::size_t bytes_transferred) {
    if (!ec) {
        std::cout.write(bytes.data(), bytes_transferred);
        tcp_socket.async_read_some(buffer(bytes), read_handler);
    }
}

void connect_handler(const boost::system::error_code& ec) {                             //5. After TCP connect gets successful, send data
    if (!ec) {
        std::string r = "GET / HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n";
        write(tcp_socket, buffer(r));                                                   //6. write(HTTP GET) on TCP socket
        tcp_socket.async_read_some(buffer(bytes), read_handler);                        //7. asynchronously read data from the stream socket. Always returns immediately.
    }
}

void resolve_handler(const boost::system::error_code& ec, tcp::resolver::iterator it) {   //3. iterator it will have IP Address
    if (!ec)
        tcp_socket.async_connect(*it, connect_handler);                                   //4. Initiate TCP connect to *it
}

int main() {
    tcp::resolver::query q{ "theboostcpplibraries.com", "80" };             //1. Send DNS query and get IP of hostname
    resolv.async_resolve(q, resolve_handler);                               //2. q will contain IP address. and call resolv_handler
    ioservice.run();
}
```
