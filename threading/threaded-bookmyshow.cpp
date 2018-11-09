 /* Lets take example of Season's cineplex, Same logic can be extended to all theaters in city and country
 * bookmyshow only does booking of 1 week in advance. Not more than that.
 *
 * Season's Cineplex have 5 theaters.
 * - Each theater having 12*15 = 180 seats
 * - This cineplex shows movie from 9AM - 12PM for every 3 hours. 5 movies/day/Theater
 * - Movie1(Avengers_eng) Movie2(Gold_hin) Movie3(Deadpool_eng) Movie4(Venom_eng) Movie5(MI-Fallout_eng)
 * 
 * Data structure for storage of Seating arrangement => 3 D array
 * 	[Day-of-week][rows-of-threater][col-of-theater]
 *      For Avengers_eng. 1 show = 2-D Array avengers_eng(12*15). Whole Week = 12*15*7
 
 * Client Browser:
 * - Ask Movie name, Booking Date, Show time
 * - Seats are stored in 3D array.
 *  [Day-of-week][rows-of-threater][col-of-theater]
 *
 * Server Request Handling Logic:
 * Parent process spawns threads. 
 * Browsers running bookmyshow will connect using TCP socket to Parent.
 * For each TCP connection 1 thread will handle to transaction.
 * All threads writes to 3D array storage of Movies.
 *			  	Parent
 *			  <--	Thread-1  <--tcp-->  Browser-doing-booking
 * 3D-Array-Movie-Storage <--	Thread-2  <--tcp-->  Browser-doing-booking
 *			  <--	Thread-3  <--tcp-->  Browser-doing-booking
 *			  <--	Thread-4  <--tcp-->  Browser-doing-booking
 * 3D-Array is integer array for storage of booking details/Movie for 1 week
 * 
 * ??What if 1 lac web Clients??
 * - Different Processes will run on parallel machines.
 * - Load Balancer would come in front of machines and distributes the load based on basis of load handled by server
 * - Again all Machines would write to 1 backend DB.
 */ 

//Compile as:
//# g++ -o THREDED-BOOKMYSHOW threaded-bookmyshow.cpp -lpthread --std=c++11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;

//#include <pthread.h>
//#include "threadpool.h"	//This program header file. Searches file incurrent directory
//#include <pthread.h>	//System Header File inclusion. Searches in system directories
#define PORT 4950
#define BUFSIZE 1024

fd_set master,read_fds;
int fdmax, i, yes=1, listener_sockfd= 0;
struct sockaddr_in serv_addr, client_addr;
pthread_mutex_t mutex;

int avengers_eng [7][12][15] = {};      //[no of 2 Arrays][Row-of-2D-Array][Col-of-2D-Array]
int gold_hin [7][12][15] = {1};
int deadpool_eng [7][12][15] = {};
int venom_eng [7][12][15] = {};
int mi_eng [7][12][15] = {};

char main_menu[] = "\t*****Welcome to bookmyshow.com*****\nSelect Country(India-at present)\nSelect State(Pune-At present)\nSelect Cineplex(Season's-At present)\nSelect Movie\n1. Avengers(English)\n2. Gold(Hindi)\n3. Deadpool(English)\n4. Venom(English)\n5. MI-fallout(English)\nYour Input:";
char showtime[]="\n\nSelect Showtime\n1. 9AM-12PM\n2. 12PM-3PM\n3. 3PM-6PM\n4. 6PM-9PM\n5. 9PM-12AM\n";
char seatno[]="\n\nNumber of seats you want to book";

/*void send_to_all(int j, int i, int sockfd, int nbytes_recvd, char *recv_buf, fd_set *master){
    if (FD_ISSET(j, master)){
        if (j != sockfd && j != i) {
            if (send(j, recv_buf, nbytes_recvd, 0) == -1) {    perror("send");    }
        }
    }
}

void send_recv(int i, fd_set *master, int sockfd, int fdmax){
    int nbytes_recvd, j; char recv_buf[BUFSIZE], buf[BUFSIZE];
     if ((nbytes_recvd = recv(i, recv_buf, BUFSIZE, 0)) <= 0) {
        if (nbytes_recvd == 0) {    printf("socket %d hung up\n", i);    }
        else{    perror("recv");    }
        close(i);    FD_CLR(i, master);
    }else{
        for(j = 0; j <= fdmax; j++){
            send_to_all(j, i, sockfd, nbytes_recvd, recv_buf, master );
        }
    }
}*/

string show_seats(int movie_name,int booking_date) {
	char temp[20];
	string seats;
	
        int i,j,num=1,c=65;
        switch(movie_name){
                case 1: 
			seats.append("\nDisplaying seats Avengers English:\n");
			break;
                case 2: 
			seats.append("\nDisplaying seats Gold Hindi:\n"); 
			break;
                case 3: 
			seats.append("\nDisplaying seats Deadpool English:\n"); 
			break;
                case 4: 
			seats.append("\nDisplaying seats Venom English:\n"); 
			break;
                case 5: 
			seats.append("\nDisplaying seats MI Fallout English:\n"); 
			break;
        }
        for(i=0;i<13;i++){
                for(j=0;j<16;j++){
                        if(i==0&&j==0){
				seats.append("  "); 
				continue;
			}
                        if (i==0) { 
				snprintf(temp,20,"%2d ",num++);
				seats.append(temp); 
				continue;
			}
                        if (i!=0 && j==0) {
				snprintf(temp,20,"%c ",c++);
				seats.append(temp); 
				continue;
			}
                        switch(movie_name){
                        case 1:
				snprintf(temp,20,"%2d ",avengers_eng[booking_date-1][i][j]);
                                seats.append(temp);
                                break;
                        case 2:
                                snprintf(temp,20,"%2d ",gold_hin[booking_date-1][i][j]);
                                seats.append(temp);
                                break;
                        case 3:
                                snprintf(temp,20,"%2d ",deadpool_eng[booking_date-1][i][j]);
                                seats.append(temp);
                                break;
                        case 4:
                                snprintf(temp,20,"%2d ",venom_eng[booking_date-1][i][j]);
                                seats.append(temp);
                                break;
                        case 5:
                                snprintf(temp,20,"%2d ",mi_eng[booking_date-1][i][j]);
                                seats.append(temp);
                                break;
                        }
                }
		seats.append("\n");
        }
        seats.append("\t\tYour Eyes This Way\n");
	cout<<"Array formed=\n"<<seats<<"\n";
	return(seats);
}

int blockSeat(int row, int col ,int movie_name,int booking_date) {
	switch(movie_name){
                case 1: //Avengers
                        if(avengers_eng[booking_date-1][row-64][col]){
                                printf("Please select different Seat, Opted Seat already booked\n");
                                return 1;
                        }else{
                                printf("Booking Here\n");
				pthread_mutex_lock(&mutex);
                                avengers_eng[booking_date-1][row-64][col] = 1;
				pthread_mutex_unlock(&mutex);
                                printf("Booked\n");
                                return 0;
                        }
                        break;
                case 2: //Gold
			pthread_mutex_lock(&mutex);
                        gold_hin[booking_date-1][row-64][col] = 1;
			pthread_mutex_unlock(&mutex);
                        break;
                case 3: //Deadpool
			pthread_mutex_lock(&mutex);
                        deadpool_eng[booking_date-1][row-64][col] = 1;
			pthread_mutex_unlock(&mutex);
                        break;
                case 4: //Venom
			pthread_mutex_lock(&mutex);
                        venom_eng[booking_date-1][row-64][col] = 1;
			pthread_mutex_unlock(&mutex);
                        break;
                case 5: //MI
			pthread_mutex_lock(&mutex);
                        mi_eng[booking_date-1][row-64][col] = 1;
			pthread_mutex_unlock(&mutex);
                        break;
        }
}

//void communicate_with_client(int newsockfd){
void *communicate_with_client(void *arg){
	int movie_name,booking_date,show_time,no_of_seats, confirm;
	char buffer[30], booking_date_s[100];
	time_t temp = time(NULL);
	struct tm test = *localtime(&temp);
	int ret = snprintf(booking_date_s,100,"\n\nSelect Date of Booking\nToday's Date %02d/%02d/%04d\n 1. %02d 2. %02d 3. %02d 4. %02d 5. %02d 6. %02d 7. %02d\n",test.tm_mday,test.tm_mon+1, test.tm_year+1900,test.tm_mday,test.tm_mday+1,test.tm_mday+2,test.tm_mday+3,test.tm_mday+4,test.tm_mday+5,test.tm_mday+7);
	
	int newsockfd = *((int *)arg);
begin:
	if (send(newsockfd, main_menu, sizeof(main_menu), 0) == -1) 
		printf("Error send() Main Menu\n");
        
	if (recv(newsockfd, &movie_name, sizeof(int), 0) == -1)
        	printf("Error recv() movie name\n");
	printf("movie_name =%d\n",ntohl(movie_name));

	if (send(newsockfd, booking_date_s, sizeof(booking_date_s), 0) == -1)
        	printf("Error send() booking date\n");
        
	if (recv(newsockfd, &booking_date, sizeof(int), 0) == -1) 
        	printf("Error recv() booking date\n");
	printf("booking_date =%d\n",ntohl(booking_date));

	if (send(newsockfd, showtime, sizeof(showtime), 0) == -1) 
        	printf("Error send() showtime\n");
        
	if (recv(newsockfd, &show_time, sizeof(int), 0) == -1)
        	printf("Error recv() showtime\n");
	printf("show_time =%d\n",ntohl(show_time));

	if (send(newsockfd, seatno, sizeof(seatno), 0) == -1)
        	printf("Error send() seatno\n");
        
	if (recv(newsockfd, &no_of_seats, sizeof(int), 0) == -1)
        	printf("Error recv() number of seats\n");
	printf("number_of_seats to book =%d\n",ntohl(no_of_seats));

	string seats = show_seats(ntohl(movie_name),ntohl(booking_date));
        if (send(newsockfd, seats.c_str(), seats.size(), 0) == -1) 
                printf("Error send() show_seats\n");
        
	if (recv(newsockfd, buffer, 30, 0) == -1)
        	printf("Error recv() selected seat buffer\n");

	//Format: No_of_seats,Row,Col. Eg: 2,A,4,B,5
	cout<<"Parsing Row Col from Buffer: "<<buffer<<endl;
	int var=0, row=0, col=0;
	char *tok = strtok(buffer,",");
	while (tok != NULL) {	
		var++;
		if(var == 1){
			printf("Number of bookings = %s\n",tok);
		}else if (var%2 == 0){
			row = atoi(tok);
			printf("row = %d\n",atoi(tok));
		}else {
			col = atoi(tok);
			printf("col = %d\n",atoi(tok));
		}
		if(row!=0 && col!=0){
			if(blockSeat(row,col,ntohl(movie_name),ntohl(booking_date))){
				printf("\nSeat Already booked, Please try again");
			}else{
				printf("\nBooking Confirmed");
			}
			row = 0;col = 0;
		}
		tok = strtok(NULL,",");
	}

	string seats1 = show_seats(ntohl(movie_name),ntohl(booking_date));
	cout<<"\n\n\n\n"<<seats1;
        if (send(newsockfd, seats1.c_str(), seats1.size(), 0) == -1)
		printf("Error send4()\n");

	char cont;
        if (recv(newsockfd, &cont, 1, 0) == -1)	//continue booking
                printf("Error recv() Continue booking\n");
        printf("Recieved = %c\n",cont); 

	if(cont =='y'){
		cout<<"Continue with Main Menu\n";
		goto begin;
	}
	//printf("Seats=%s\n",seats);
}

/*void connection_accept(fd_set *master, int *fdmax, int sockfd, struct sockaddr_in *client_addr){
	socklen_t addrlen;
	int newsockfd, ret, i=0;
	pthread_t tid[10];
	addrlen = sizeof(struct sockaddr_in);
    
	newsockfd = accept(sockfd, (struct sockaddr *)client_addr, &addrlen);
	if (newsockfd == -1){
		perror("accept"); 
		exit(1); 
	}

	ret = pthread_create(&tid[i],NULL,communicate_with_client,&newsockfd);
	if(ret != 0){
		printf("Failed to create thread\n");
	}

	pthread_join (tid[i], NULL);
	communicate_with_client (newsockfd);*/
/*		if (send(newsockfd, recv_buf, nbytes_recvd, 0) == -1) {    
			perror("send");    
		}
        	FD_SET(newsockfd, master);
	        if(newsockfd > *fdmax)  *fdmax = newsockfd;
        	printf("new connection from %s on port %d fd %d\n",inet_ntoa(client_addr->sin_addr), ntohs(client_addr->sin_port),newsockfd);*/
//    }
//}

void bind_listen(){
        if ((listener_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("Socket");
                exit(1);
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(4950);
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        memset(serv_addr.sin_zero, '\0', sizeof serv_addr.sin_zero);

	if (setsockopt(listener_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        	perror("setsockopt");  exit(1);
	}
	if (bind(listener_sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1) {
        	perror("Unable to bind"); exit(1);
	}
	if (listen(listener_sockfd, 10) == -1) {
        	perror("listen"); exit(1);
	}
}

int main(){
        int newsockfd, ret, k=0;
        pthread_t tid;
	struct sockaddr client_addr;
        socklen_t addrlen;// = sizeof(struct sockaddr_in);

	FD_ZERO(&master);        
	FD_ZERO(&read_fds);

	bind_listen();

	printf("\nServer Waiting for client on port 4950, socket=%d\n",listener_sockfd);
	fflush(stdout);        

        while(newsockfd = accept(listener_sockfd, &client_addr, &addrlen)){
		printf("Connection Accepted communicating on fd=%d\n",newsockfd);
       		ret = pthread_create(&tid,NULL,communicate_with_client,&newsockfd);//Immediately get new Thread
        	if(ret != 0){ printf("Failed to create thread\n"); return 1;}
	}
	return 0;
}
