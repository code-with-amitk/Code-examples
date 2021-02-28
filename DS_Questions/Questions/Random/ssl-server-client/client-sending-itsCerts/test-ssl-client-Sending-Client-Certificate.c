/* https://aticleworld.com/ssl-server-client-using-openssl-in-c/
 * https://wiki.openssl.org/index.php/SSL/TLS_Client
 * Compile:
 * 	# gcc -v test-ssl-client.c -L/usr/local/lib64/ -lssl -lcrypto -o SSL-CLIENT
 * 	OR
 * 	# gcc -v -nostdinc -I /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include -I /usr/include test-ssl-client-Sending-Client-Certificate.c -lssl -lcrypto -o SSL-CLIENT-SENDING-CLIENT-CERTIFICATE
 * Running:
 * 	# LD_LIBRARY_PATH=/usr/local/lib64/:$LD_LIBRARY_PATH ./SSL-CLIENT 127.0.0.1 8081
 * 	OR
 * 	# LD_LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include:/usr/include ./SSL-CLIENT-SENDING-CLIENT-CERTIFICATE 127.0.0.1 8081 <SSL-Server-crt-andkey-file> <ssl-client-certificate> <ssl-client-key-file>
 */

//Generating client Key and CSR
//# /usr/bin/openssl req -new -nodes -days 365 -newkey rsa:1024 -keyout ssl-client-certandkey.csr -out ssl-client-certandkey.csr
//Signing csr
//# /usr/bin/openssl x509 -req -in ssl-client-certandkey.csr -CA ssl-server-certandkey.crt -CAkey ssl-server-certandkey.crt -CAcreateserial -out hdfc.crt

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
#define FAIL    -1

int tcp_connect(const char *hostname, int port){   
	int sd;
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
    	if (connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0){
	        close(sd);
        	perror(hostname);
	        abort();
    	}
    	return sd;
}

SSL_CTX* initialize_ssl_context(void){   
	SSL_METHOD *method;
    	SSL_CTX *ctx;
    	OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
    	SSL_load_error_strings();   /* Bring in and register error messages */
    	method = TLSv1_2_client_method();  /* Create new client-method instance */
    	ctx = SSL_CTX_new(method);   /* Create new context */
    	if (ctx == NULL){
        	ERR_print_errors_fp(stderr);
        	abort();
    	}
    	return ctx;
}

void check_server_certificates(SSL* ssl){   
	X509 *cert;
    	char *line;
	int res;

	printf("\nStep-6: Reading SSL Server Certificates\n");
    	cert = SSL_get_peer_certificate(ssl);
    	if (cert != NULL){
        	printf("\tServer has provided certificate:\n");

        	line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        	printf("\tSubject: %s\n", line);
        	free(line);       /* free the malloc'ed string */

        	line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        	printf("\tIssuer: %s\n\n", line);
        	free(line);       /* free the malloc'ed string */

//18 X509_V_ERR_DEPTH_ZERO_SELF_SIGNED_CERT: self signed certificate
//the passed certificate is self signed and the same certificate cannot be found in the list of trusted certificates.
		printf("Step-7: Verifying SSL Server Certificates using SSL_get_verify_result()\n");
		int res = SSL_get_verify_result(ssl);		
		if (res != X509_V_OK){		//#define X509_V_OK 0
			printf("***[FATAL] SSL_get_verify_result() failed Reason:%d*** \nAborting!!\n\n",res);
			exit(0);
		}else{
			printf("\tServer Certificate Verified Successfully\n");
		}
        	X509_free(cert);     /* free the malloc'ed certificate copy */
    	}else{
        	printf("Info: No Server certificates configured. Shall We exit?\n");
	}
}

int main(int count, char *strings[])
{   
	SSL_CTX *ctx;
	int server, bytes;
    	SSL *ssl;
    	char buf[1024], *hostname, *portnum;
	char acClientRequest[1024] ={0};
    	if ( count != 6 ){
	        printf("Usage:\
			%s <sslserver-hostname> <sslserver-portnum> <sslserver-Certificate-Chain-and-key> <client-cert-file> <client-key-file>\n", strings[0]);
        	exit(0);
    	}

   	hostname = strings[1];
    	portnum = strings[2];

	SSL_library_init();
    	ctx = initialize_ssl_context();
	printf("\nStep-1: SSL_library_init(), initialize_ssl_context() Completed Successfully\n");

	if ( SSL_CTX_use_certificate_file(ctx, strings[4], SSL_FILETYPE_PEM) <= 0 ){
	        ERR_print_errors_fp(stderr);
        	abort();
    	}

    	if ( SSL_CTX_use_PrivateKey_file(ctx,strings[5], SSL_FILETYPE_PEM) <= 0 ){
	        ERR_print_errors_fp(stderr);
        	abort();
	}

	if ( !SSL_CTX_check_private_key(ctx) ){
	        fprintf(stderr, "Private key does not match the public certificate\n");
        	abort();
	}

	printf("\nStep-2: Client Loaded Self Certificate(Signed by Server) Successfully\n");

	printf("\nStep-3: TCP 3-way-handshake (SYN-SYNACK-SYN) Started\n");
    	server = tcp_connect(hostname, atoi(portnum));
	printf("\tTCP 3-way-handshake Completed\n");

/* SSL_new(): 
 * 	Create a new SSL structure for a connection
 * SSL_set_fd(SSL *ssl, int fd):
 * 	Sets the file descriptor fd as the input/output facility for the TLS/SSL (encrypted) side of ssl.
 * SSL_connect(SSL *ssl):
 * 	SSL_connect() initiates the TLS/SSL handshake with a server. The communication channel must already have been set and assigned to the ssl by setting an underlying BIO.
 */
    	ssl = SSL_new(ctx);
    	SSL_set_fd(ssl, server);
	SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
	printf("\nStep-4: Create new SSL structure for SSL Connection Completed Sucessfully\n");	
	printf("\nStep-5: Configuration for Already connected TCP Socket for SSL Completed Sucessfully\n");	

/*SSL_CTX_load_verify_locations(SSL_CTX *ctx, const char *CAfile, const char *CApath):
 * 	Specifies the locations for ctx, at which CA certificates for verification purposes are located. The certificates available via CAfile and CApath are trusted.
 */
	printf("\nStep-6: Loading Server Certificate Locally\n");
//	int rc = SSL_CTX_load_verify_locations(ctx, "testServer.pem", NULL);	
	int rc = SSL_CTX_load_verify_locations(ctx, strings[3], NULL);	
	if (rc != 1) {
		printf("Loading CA Certificate failed rc=%d\n",rc);
		exit(0);
	}else{
		printf("\tLoading of Server Cert Completed Successfully\n");
	}

    	if (SSL_connect(ssl) == FAIL){
	        ERR_print_errors_fp(stderr);
		printf("SSL_connect() failed\n");
		abort();
    	}else{
		printf("\nStep-7: SSL_connect(ssl) sending CLIENT_HELLO completed Successfully\n");
	        printf("\tConnected to Server with encryption/Key/Cipher\t[%s]\n", SSL_get_cipher(ssl));
        	check_server_certificates(ssl);

        	char acUsername[16] ={0},acPassword[16] ={0};
		const char *cpRequestMessage = "<Body><UserName>%s<UserName><Password>%s<Password><Body>";
	        printf("\nStep-8: Communicate with Server on SSL\n");
		printf("\tAuthenticate to server\n");
		printf("\tEnter the User Name : ");
		scanf("%s",acUsername);
		printf("\tEnter the Password : ");
		scanf("%s",acPassword);
	        sprintf(acClientRequest, cpRequestMessage, acUsername,acPassword);   /* construct reply */

	        SSL_write(ssl,acClientRequest, strlen(acClientRequest));
		printf("\tMessage Sent to server: [%s]\n",acClientRequest);

	        bytes = SSL_read(ssl, buf, sizeof(buf));
        	buf[bytes] = 0;
	        printf("\tMessage Received from server: [%s]\n", buf);

		printf("\nStep-9: Freeing Allocated SSL Structure SSL_free(SSL)\n");
        	SSL_free(ssl);
    }
	printf("\nStep-10: Closing TCP Socket close(sockfd). Closes both directions of data transfer. No reading, no writing\n");
	close(server);

	printf("\nStep-11: Freeing allocated SSL_CTX object SSL_CTX *ctx\n");
	SSL_CTX_free(ctx);

	printf("\nClient Going, Good Bye\n\n");
	return 0;
}
