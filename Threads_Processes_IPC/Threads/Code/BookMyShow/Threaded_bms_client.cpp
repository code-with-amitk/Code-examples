//Compile as:
//# g++ -o threadedbookmy-client.cpp -o CLIENT -lpthread --std=c++11
#include <stdio.h>
#include <unistd.h>     //close()
#include <sys/socket.h>     //socket(), bind(), connect()
#include <netinet/in.h>     //sockaddr_in
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{ 
	int clientSocket,input, temp, i, col;
	char buffer[1024],row,str[10];
	string buf;
	struct sockaddr_in serverAddr;        socklen_t addr_size;
        clientSocket = socket(AF_INET, SOCK_STREAM, 0);

        serverAddr.sin_family = AF_INET;        
        serverAddr.sin_port = htons(4950);
        addr_size = sizeof (serverAddr);        
        connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

begin:
        recv(clientSocket, buffer, 1024, 0);	//movie_name
       	printf("%s",buffer);
	scanf("%d",&input);
	temp = htonl(input);
	send(clientSocket, &temp, sizeof(int), 0);

        recv(clientSocket, buffer, 1024, 0);	//booking_date
       	printf("%s",buffer);
	scanf("%d",&input);
	temp = htonl(input);
	send(clientSocket, &temp, sizeof(int), 0);

        recv(clientSocket, buffer, 1024, 0);	//show_time
       	printf("%s",buffer);
	scanf("%d",&input);
	temp = htonl(input);
	send(clientSocket, &temp, sizeof(int), 0);

        recv(clientSocket, buffer, 1024, 0);	//no_of_seats
       	printf("%s",buffer);
	scanf("%d",&input);
	temp = htonl(input);
	send(clientSocket, &temp, sizeof(int), 0);

        recv(clientSocket, buffer, 1024, 0);	//Seating_arragnment
       	printf("%s",buffer);

	//Creates String in format: numberofseats,Row_no,col_no
	cout<<"\n\n\t>>>>>> Seats Marked 1 are already Booked, Donot select them <<<<<<<\n";

	cout<<"\n Please select "<<input<<" Seats\n";
	snprintf(str,10,"%d,",input);	
	buf.append(str);
        for(i=0;i<input;i++){
        	printf("\nSeat %d:",i+1);
                cout<<"\tRow:";
		cin>>row;
		snprintf(str,10,"%d,",row);	
		buf.append(str);
               	cout<<"\tCol:";
		cin>>col;
		snprintf(str,10,"%d,",col);
		buf.append(str);
        }
	cout<<"Buffer="<<buf<<"\n";
	send(clientSocket, buf.c_str(), buf.size(), 0);

        recv(clientSocket, buffer, 1024, 0);	//Seats after booking
	printf("\n\n\nAfter Recv");
       	printf("%s\n\n",buffer);

	char cont;
	printf("Continue booking|New Booking Yes=y, No=n :\t\n");
	cin>>cont;
	if(cont == 'y'){
		send(clientSocket, &cont, 1, 0);
		goto begin;
	}else{
		close(clientSocket);
	}

	return 0;
}
