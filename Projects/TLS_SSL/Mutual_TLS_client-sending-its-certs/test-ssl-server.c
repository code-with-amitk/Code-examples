/* https://aticleworld.com/ssl-server-client-using-openssl-in-c/
 * Compile:
 * 	# gcc -v -Wall -o SSL-SERVER  test-ssl-server.c -L/usr/local/lib64/ -lssl -lcrypto
 * 	OR
 * 	# gcc -v -nostdinc -I  /usr/lib/gcc/x86_64-redhat-linux/4.8.5/include -I  /usr/include -Wall -o SSL-SERVER  test-ssl-server.c -lssl -lcrypto
 * Running:
 * 	# LD_LIBRARY_PATH=/usr/local/lib64/:$LD_LIBRARY_PATH  ./SSL-SERVER 8081
 * 	OR
 * 	# LD_LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include:/usr/include ./SSL-SERVER 8081 <self-signed-cert-andkey-file>
 */
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <resolv.h>
#include "openssl/ssl.h"
#include "openssl/ssl.h"
//#include <openssl/err.h>
//#include <openssl/err.h>
#define FAIL    -1
char *portnum;

int bind_and_listen(int port)
{   
	int sd;
	struct sockaddr_in addr;
	sd = socket(PF_INET, SOCK_STREAM, 0);
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

/*Sometimes, you might notice, you try to rerun a server and bind() fails, claiming "Address already in use." What does that mean? Well, a little bit of a socket that was connected is still hanging around in the kernel, and it's hogging the port. You can either wait for it to clear (a minute or so), or add code to your program allowing it to reuse the port. */
        int yes=1;
        if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
                perror("setsockopt");  exit(1);
        }

	if (bind(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 ){
		perror("can't bind port");
		abort();
	}

	if ( listen(sd, 10) != 0 ){
		perror("Can't configure listening port");
		abort();
	}
	return sd;
}

int isRoot(){
	if (getuid() != 0){
		return 0;
	}else{
		return 1;
	}
}

SSL_CTX* initialize_server_ctx(void){   
	SSL_METHOD *method;
	SSL_CTX *ctx;
	OpenSSL_add_all_algorithms();  /* load & register all cryptos, etc. */
	SSL_load_error_strings();   /* load all error messages */
	method = TLSv1_2_server_method();  /* create new server-method instance */
	ctx = SSL_CTX_new(method);   /* create new context from method */
	if ( ctx == NULL ){
		ERR_print_errors_fp(stderr);
		abort();
	}
	return ctx;
}

/* SSL_get_peer_certificate():
 * 	Returns a pointer to the X509 certificate the peer presented. If the peer did not present a certificate, NULL is returned.
 * X509_NAME_oneline():	X509_NAME printing routines
 * X509_get_subject_name(): returns the subject name of certificate x
 */
void show_client_certificates(SSL* ssl)
{   
	X509 *cert;
	char *line;
	printf("\tClient Certificate Recieved\n");
	cert = SSL_get_peer_certificate(ssl); /* Get certificates (if available) */
	if (cert != NULL){
		line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
		printf("Subject: %s\n", line);
		free(line);
		line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
		printf("Issuer: %s\n", line);
		free(line);
		X509_free(cert);
	}else{
		printf("\tClient has not provided any certificates.\n\n");
	}
}

void handle_client_connections(SSL* ssl) /* Serve the connection -- threadable */
{   
	char buf[1024] = {0};
	int sd, bytes;
	//const char* ServerResponse="<Body><Name>aticleworld.com</Name><year>1.5</year><BlogType>Embedede and c c++<BlogType><Author>amlendra<Author><Body>";
	const char* ServerResponse="You are connected to amit.com";
	const char *cpValidMessage = "<Body><UserName>amit<UserName><Password>amit<Password><Body>";							 

	printf("\nStep-7: Verifying Client Certificates\n");
	if ( SSL_accept(ssl) == FAIL ){     /* do SSL-protocol accept */
		ERR_print_errors_fp(stderr);
		printf("SSL_accept() failed\n");
	}else{
		printf("\nStep-8: SSL_accept(ssl) Completed Successfully\n");
		printf("\nStep-9: Client Certificates Verified Successfully\n");
		show_client_certificates(ssl);        /* get any certificates */
		bytes = SSL_read(ssl, buf, sizeof(buf)); /* get request */
		buf[bytes] = '\0';

		printf("\nStep-10: Communication with SSL Client Started\n");
		printf("\tMessage Recieved from Client: [%s]\n", buf);
		if (bytes > 0){
			if(strcmp(cpValidMessage,buf) == 0){
				printf("\tSending Response to SSL Client: [%s]\n",ServerResponse);
				SSL_write(ssl, ServerResponse, strlen(ServerResponse));
			}else{
				SSL_write(ssl, "Invalid Message", strlen("Invalid Message")); /* send reply */
			}
		}else{
			ERR_print_errors_fp(stderr);
		}
	}
	sd = SSL_get_fd(ssl);       /* get socket connection */

	printf("\nStep-10: Serving SSL client Completed\n\tSSL_free(ssl)\n");
	SSL_free(ssl);

	printf("\nStep-11: Closing TCP Socket with client close(sockfd)\n");
	close(sd);

	printf("\n***SSL Server listening for TCP Connection port[%d]***\n",atoi(portnum));
}

int main(int count, char *Argc[])
{   
	SSL_CTX *ctx;
	int server;
	if(!isRoot()){
		printf("This program must be run as root/sudo user!!");
		exit(0);
	}
	if ( count != 3 ){
		printf("Usage: %s <portnum> <self-signed-certandkey>\n", Argc[0]);
		exit(0);
	}

	printf("\n***SSL Server Started***\n");
	// Initialize the SSL library
	SSL_library_init();
	portnum = Argc[1];
	ctx = initialize_server_ctx();        /* initialize SSL */
	printf("\nStep-1: SSL_library_init(), initialize_server_ctx() Completed Successfully\n");

	//# openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout ssl-server-certandkey.crt -out ssl-server-certandkey.crt
        if ( SSL_CTX_use_certificate_file(ctx, Argc[2], SSL_FILETYPE_PEM) <= 0 ){
                ERR_print_errors_fp(stderr);
		printf("\nLoading on SSL-Server Certificate failed\n");
                abort();
        }

        if ( SSL_CTX_use_PrivateKey_file(ctx, Argc[2], SSL_FILETYPE_PEM) <= 0 ){
                ERR_print_errors_fp(stderr);
		printf("\nLoading on SSL-Server Key failed\n");
                abort();
        }

        if ( !SSL_CTX_check_private_key(ctx) ){
                fprintf(stderr, "Private key does not match the public certificate\n");
		printf("\nVerification of private key failed\n");
                abort();
        }
	printf("\nStep-2: Loading of Self SSL-Server Certificate, Key Success\n");

//These System calls are used by SSL Server to 
//	1. Ask SSL client to send ceritficate on connect
//	2. Verify client certificate sent during connection	
	SSL_CTX_set_client_CA_list(ctx, SSL_load_client_CA_file(Argc[2]));
	SSL_CTX_load_verify_locations(ctx, Argc[2], NULL );
	SSL_CTX_set_verify (ctx,SSL_VERIFY_PEER|SSL_VERIFY_FAIL_IF_NO_PEER_CERT,0);
	
	server = bind_and_listen(atoi(portnum));    /* create server socket */
	printf("\nStep-3: Server binded & listening on TCP port [%d] Successfully\n",atoi(portnum));

	while (1){   
		struct sockaddr_in addr;
		socklen_t len = sizeof(addr);
		SSL *ssl;
		int client = accept(server, (struct sockaddr*)&addr, &len);  /* accept connection as usual */
		printf("\nStep-4: TCP 3-Way Handshake Started..\n");
		printf("\tNew Connection request from: %s:%d\n",inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
		printf("\tTCP 3-Way Handshake Completed Successfully\n");

/* SSL_new(): Create a new SSL structure for a connection
 * SSL_set_fd(SSL *ssl, int fd): Sets the file descriptor fd as the input/output facility for the TLS/SSL (encrypted) side of ssl.
 * SSL_connect(SSL *ssl):
 *      SSL_connect() initiates the TLS/SSL handshake with a server. The communication channel must already have been set and assigned to the ssl by setting an underlying BIO.
 */
		ssl = SSL_new(ctx);
		SSL_set_fd(ssl, client);
	        printf("\nStep-5: Create new SSL structure for SSL Connection Completed Successfully\n");  
        	printf("\nStep-6: Configuration for Already accepted TCP Socket for SSL Completed Sucessfully\n"); 

		handle_client_connections(ssl);         /* service connection */
	}
	close(server);          /* close server socket */
	SSL_CTX_free(ctx);         /* release context */
}
