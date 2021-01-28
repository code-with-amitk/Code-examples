/* Lets take example of Season's cineplex, Same logic can be extended to all theaters in city and country
 * 
 * bookmyshow only does booking of 1 week in advance. Not more than that.
 *
 * Season's Cineplex have 5 theaters.
 * * Each theater having 12*15 = 180 seats
 * * This cineplex shows movie from 9AM - 12PM for every 3 hours. 5 movies/day/Theater
 * - Movie1(Avengers_eng) Movie2(Gold_hin) Movie3(Deadpool_eng)	Movie4(Venom_eng) Movie5(MI-Fallout_eng)
 * - Data structure for storage of Seating arrangement => 2 D array(12*15)
 * Example:
 * - For Avengers_eng. 1 show = 2-D Array avengers_eng(12*15). Whole Week = 12*15*7
 *
 * Logic:
 * - Ask Movie name, Booking Date, Show time
 * - Seats are stored in 3D array.
 *   	[Day-of-week][rows-of-threater][col-of-theater]
 */
#include<stdbool.h> 
#include<time.h>
#include<stdio.h>

int avengers_eng [7][12][15] = {};	//[no of 2 Arrays][Row-of-2D-Array][Col-of-2D-Array]
int gold_hin [7][12][15] = {1};	
int deadpool_eng [7][12][15] = {};
int venom_eng [7][12][15] = {};
int mi_eng [7][12][15] = {};

void show_seats(int movie_name,int booking_date) {
	int i,j,num=1,c=65;
	switch(movie_name){
                case 1: printf("\nDisplaying seats Avengers English:\n"); break;
                case 2: printf("\nDisplaying seats Gold Hindi:\n"); break;
                case 3: printf("\nDisplaying seats Deadpool English:\n"); break;
                case 4: printf("\nDisplaying seats Venom English:\n"); break;
                case 5: printf("\nDisplaying seats MI Fallout English:\n"); break;
        }
        for(i=0;i<13;i++){
                for(j=0;j<16;j++){
                        if(i==0&&j==0){printf("  "); continue;}
                        if (i==0) { printf("%2d ",num++); continue;}
                        if (i!=0 && j==0) { printf("%c ",c++); continue;}
                        switch(movie_name){
                        case 1:
                                printf("%2d ",avengers_eng[booking_date-1][i][j]);
                                break;
                        case 2:
                                printf("%2d ",gold_hin[booking_date-1][i][j]);
                                break;
                        case 3:
                                printf("%2d ",deadpool_eng[booking_date-1][i][j]);
                                break;
                        case 4:
                                printf("%2d ",venom_eng[booking_date-1][i][j]);
                                break;
                        case 5:
                                printf("%2d ",mi_eng[booking_date-1][i][j]);
                                break;
                        }
                }
                printf("\n");
        }
        printf("\t\tYour Eyes This Way");
        printf("\n");	
}

int book_seat(int movie_name,int row,int col, int booking_date){
//	printf("movie_name=%d,booking_date=%d,row=%d,col=%d\n",movie_name,booking_date,row,col);
//	printf("avengers_eng[booking_date-1][row-64][col]=%d\n",avengers_eng[booking_date-1][row-64][col]);
	switch(movie_name){
		case 1:	//Avengers
			if(avengers_eng[booking_date-1][row-64][col]){
				printf("Please select different Seat, Opted Seat already booked\n");
				return 1;
			}else{
				printf("Booking Here\n");
				avengers_eng[booking_date-1][row-64][col] = 1;
				return 0;
			}
			break;
		case 2:	//Gold
			gold_hin[booking_date-1][row-64][col] = 1;
			break;
		case 3: //Deadpool
			deadpool_eng[booking_date-1][row-64][col] = 1;
			break;
		case 4: //Venom
			venom_eng[booking_date-1][row-64][col] = 1;
			break;
		case 5: //MI
			mi_eng[booking_date-1][row-64][col] = 1;
			break;
	}
}

void payment (int no_of_seats) {
	printf("\nPlease pay: %d * 500 = %d",no_of_seats,no_of_seats*500);
	printf("\nClick OK to get directed to payment gateway\tOK\n");
}

void showBookCharge(int movie_name,int booking_date,int show_time, int no_of_seats) {
	int i,j, col, confirm=0;
	char row;
	show_seats(movie_name,booking_date);
go:
	printf("Please Select %d seats",no_of_seats);
	for(i=0;i<no_of_seats;i++){
		printf("\nSeat %d:",i+1);
		printf("\tRow:");
		scanf(" %c",&row);	//printf("\tSelected Row=%d",row);
		printf("\tCol:");
		scanf("%d",&col);	//printf("\tSelected Coloumn=%d",col);
		confirm = book_seat(movie_name,row,col,booking_date);
//		printf("\nconfirm=%d\n",confirm);
	}
	if(confirm)
		goto go;
	printf("\n\nSeats Confirmed");
	show_seats(movie_name,booking_date);
	payment(no_of_seats);
	printf("\n\n");
}

void main(){
	time_t temp = time(NULL);
	struct tm test = *localtime(&temp);
	int show_time, movie_name, movie_date, no_of_seats;
	char continue_booking;
again:
	printf("\t*****Welcome to bookmyshow.com*****\n");
	printf("Select Country(India-at present)\n"
		"Select State(Pune-At present)\n"
		"Select Cineplex(Season's-At present)\n");
	printf("Select Movie\n"
		"1. Avengers(English)\n2. Gold(Hindi)\n"
		"3. Deadpool(English)\n4. Venom(English)\n"
		"5. MI-fallout(English)\nYour Input:");
	scanf("%d",&movie_name);
	printf("\n\nSelect Date of Booking\n");
	printf("Today's Date %02d/%02d/%04d\n",test.tm_mday,test.tm_mon+1, test.tm_year+1900);
	printf("1. %02d 2. %02d 3. %02d 4. %02d 5. %02d 6. %02d 7. %02d\n",
		test.tm_mday,test.tm_mday+1,test.tm_mday+2,
		test.tm_mday+3,test.tm_mday+4,test.tm_mday+5,
		test.tm_mday+7);
	scanf("%d",&movie_date);
	printf("\n\nSelect Showtime\n"
		"1. 9AM-12PM\n2. 12PM-3PM\n"
		"3. 3PM-6PM\n4. 6PM-9PM\n"
		"5. 9PM-12AM\n");
	scanf("%d",&show_time);
	printf("\n\nNumber of seats you want to book:");
	scanf("%d",&no_of_seats);
	showBookCharge(movie_name,movie_date,show_time, no_of_seats);

	printf("\nContinue Booking..");
	printf("\nYes:y\nNo:n\n");
	scanf(" %c",&continue_booking);
	if(continue_booking == 'y')
		goto again;
	else
		exit(0);
}
