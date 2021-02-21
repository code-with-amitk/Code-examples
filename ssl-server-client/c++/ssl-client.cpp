#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <iostream>
#define FAIL    -1

class OpenSSLClient{
public:
  SSL_CTX* InitializeSSLContext(void);
  int TCPConnect(const char*, int);
  void CheckServerCertificates(SSL*);
};

int OpenSSLClient::TCPConnect(const char *hostname, int port){
  int sd;
  int ret;
      struct hostent *host;
      struct sockaddr_in addr;

      if ((host = gethostbyname(hostname)) == NULL){
          perror(hostname);
          abort();
      }
      sd = socket(PF_INET, SOCK_STREAM, 0);
      bzero(&addr, sizeof(addr));
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      addr.sin_addr.s_addr = *(long*)(host->h_addr);
      if ((ret = connect(sd, (struct sockaddr*)&addr, sizeof(addr))) != 0){
          close(sd);
          perror(hostname);
          return ret;
      }
      return sd;
}

SSL_CTX* OpenSSLClient::InitializeSSLContext(void){
  const SSL_METHOD *method;
      SSL_CTX *ctx;
      OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
      SSL_load_error_strings();   /* Bring in and register error messages */
//      method = TLSv1_2_client_method();  /* Create new client-method instance */
      method = TLS_client_method();  /* Create new client-method instance */
      ctx = SSL_CTX_new(method);   /* Create new context */
      if (ctx == NULL){
          ERR_print_errors_fp(stderr);
          abort();
      }
      return ctx;
}

void OpenSSLClient::CheckServerCertificates(SSL* ssl){
  X509 *cert;
      char *line;
  std::cout << std::endl << "6. Reading SSL Server Certificates!" << std::endl;
  cert = SSL_get_peer_certificate(ssl);
  if (cert != NULL){
    std::cout << std::endl << "\tServer has provided certificate!" << std::endl;

    line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
    std::cout << std::endl << "\tSubject: " << line << std::endl;
    free(line);       /* free the malloc'ed string */

    line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
    std::cout << std::endl << "\tIssuer: " << line << std::endl;
    free(line);       /* free the malloc'ed string */

//18 X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT: self signed certificate
//the passed certificate is self signed and the same certificate cannot be found in the list of trusted certificates.
    std::cout << std::endl << "7. Verifying SSL Server Certificates using SSL_get_verify_result()" << std::endl;

    int res = SSL_get_verify_result(ssl);
    if (res != X509_V_OK){    //#define X509_V_OK 0
      std::cout << std::endl << "***[FATAL] SSL_get_verify_result() failed. Aborting!" << res << std::endl;
      exit(0);
    }else{
      std::cout << std::endl << "\tServer Certificate Verified Successfully" << std::endl;
    }
          X509_free(cert);     /* free the malloc'ed certificate copy */
      }else{
          std::cout << std::endl << "Info: No Server certificates configured. Shall We exit?" << std::endl;
  }
}

int main(int count, char *strings[]){
  SSL_CTX *ctx;
  int server, bytes;
  SSL *ssl;
  char buf[1024], *hostname, *portnum;
  char acClientRequest[1024] ={0};
  if ( count != 6 ){
    std::cout << std::endl << "Usage: <sslserver-hostname> <sslserver-portnum> <sslserver-Certificate-Chain-and-key> <client-cert-file> <client-key-file> " << strings[0];
    exit(0);
  }

  hostname = strings[1];
  portnum = strings[2];

  OpenSSLClient oClient;
  SSL_library_init();

  ctx = oClient.InitializeSSLContext();
  std::cout << std::endl << "1: SSL_library_init() Completed!" << std::endl;

  if (SSL_CTX_use_certificate_file(ctx, strings[4], SSL_FILETYPE_PEM) <= 0 ){
    ERR_print_errors_fp(stderr);
    abort();
  }

  if (SSL_CTX_use_PrivateKey_file(ctx,strings[5], SSL_FILETYPE_PEM) <= 0 ){
    ERR_print_errors_fp(stderr);
    abort();
  }

  if (!SSL_CTX_check_private_key(ctx) ){
    std::cout << std::endl << "Private key does not match the public certificate" << std::endl;
    abort();
  }

  std::cout << std::endl << "2: Client Loaded Self Certificate(Signed by Server)!" << std::endl;

  std::cout << std::endl << "3: TCP 3-way-handshake (SYN-SYNACK-SYN) Started!" << std::endl;

  if((server = oClient.TCPConnect(hostname, atoi(portnum))) == -1)
    return 0;

  std::cout << std::endl << "\tTCP 3-way-handshake Completed" << std::endl;

/* SSL_new():
 *  Create a new SSL structure for a connection
 * SSL_set_fd(SSL *ssl, int fd):
 *  Sets the file descriptor fd as the input/output facility for the TLS/SSL (encrypted) side of ssl.
 * SSL_connect(SSL *ssl):
 *  SSL_connect() initiates the TLS/SSL handshake with a server. The communication channel must already have been set and assigned to the ssl by setting an underlying BIO.
 */	
  ssl = SSL_new(ctx);
  SSL_set_fd(ssl, server);
  SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
  std::cout << std::endl << "4: Create new SSL structure for SSL Connection Completed!" << std::endl;
  std::cout << std::endl << "5: Configuration for Already connected TCP Socket for SSL Completed!" << std::endl;

/*SSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *CAfile, const char *CApath):
 *  Specifies the locations for ctx, at which CA certificates for verification purposes are located. The certificates available via CAfile and CApath are trusted.
 */
  std::cout << std::endl << "6: Loading Server Certificate Locally!" << std::endl;
//  int rc = SSL_CTX_load_verify_locations(ctx, "testServer.pem", NULL);
  int rc = SSL_CTX_load_verify_locations(ctx, strings[3], NULL);
  if (rc != 1) {
    std::cout << std::endl << "Loading CA Certificate failed:" << rc << std::endl;
    exit(0);
  }else
    std::cout << std::endl << "\tLoading of Server Cert Completed!" << std::endl;


  if (SSL_connect(ssl) == FAIL){
    ERR_print_errors_fp(stderr);
    std::cout << std::endl << "SSL_connect() failed" << std::endl;
    abort();
  }else{
    std::cout << std::endl << "7: SSL_connect(ssl) sending CLIENT_HELLO completed!" << std::endl;
    std::cout << std::endl << "\tConnected to Server with encryption/Key/Cipher: " << SSL_get_cipher(ssl) << std::endl;

    oClient.CheckServerCertificates(ssl);

    char acUsername[16] ={0},acPassword[16] ={0};
    const char *cpRequestMessage = "<Body><UserName>%s<UserName><Password>%s<Password><Body>";
    std::cout << std::endl << "8. Communicate with Server on SSL!"  << std::endl;
    std::cout << std::endl << "\tAuthenticate to server!" << std::endl;
    std::cout << std::endl << "\tEnter the User Name : ";
    std::cin >> acUsername;
    std::cout << std::endl << "\tEnter the Password : ";
    std::cin >> acPassword;
    sprintf(acClientRequest, cpRequestMessage, acUsername,acPassword);   /* construct reply */

    SSL_write(ssl,acClientRequest, strlen(acClientRequest));
    std::cout << std::endl << "\tMessage Sent to server: " << acClientRequest << std::endl;

    bytes = SSL_read(ssl, buf, sizeof(buf));
    buf[bytes] = 0;
    std::cout << std::endl << "\tMessage Received from server: " << buf << std::endl;

    std::cout << std::endl << "9. Freeing Allocated SSL Structure SSL_free(SSL)" << std::endl;
    SSL_free(ssl);
  }

  std::cout << std::endl << "10. Closing TCP Socket close(sockfd). Closes both directions of data transfer. No reading, no writing" << std::endl;
  close(server);

  std::cout << std::endl << "11. Freeing allocated SSL_CTX object SSL_CTX *ctx" << std::endl;
  SSL_CTX_free(ctx);

  std::cout << std::endl << "Client Going, Good Bye!" << std::endl;
  return 0;
}	  
