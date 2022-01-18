#include "common.h"
#include "User.h"
#include "MeetingRoom.h"
#include "Meeting.h"
#include "Notification.h"
#include"MeetingScheduler.h"
using namespace std;

int main()
{					
	//1. Created 1 meeting duration=60, no_of_attendees=10, agenda
	Meeting oStatusMeeting(60, 10, "status meeting");

	//2. Created 3 meeting rooms.
	// Requirement-2, n meeting rooms can be created.
	//Room1. capacity = 10, len = 25, width = 50
	//Room2. capacity = 20, len = 50, width = 100
	//Room3. capacity = 30, len = 100, width = 200
	MeetingRoom oMeetingRoom1(10, 25, 50);
	MeetingRoom oMeetingRoom2(20, 50, 100);
	MeetingRoom oMeetingRoom3(30, 100, 200);
	vector<MeetingRoom> vecMeetingRooms;
	vecMeetingRooms.push_back(oMeetingRoom1);
	vecMeetingRooms.push_back(oMeetingRoom2);
	vecMeetingRooms.push_back(oMeetingRoom3);

	//3. Create Notification Service
	Notification oNotification;

	//4. MeetingScheduler is Helper class for scheduling meetings
	//Provide information to MeetingScheduler:
	//	MeetingRooms
	//	NotificationService URL
	MeetingScheduler oMeetingScheduler(vecMeetingRooms, oNotification);

	//4. Attendees who will attend the meeting
	User oUserAttendee1("User1", UserType::attendee);	//Create Attendee user
	User oUserAttendee2("User2", UserType::attendee);	//Create Attendee user
	vector<User> vecAttendees;
	vecAttendees.push_back(oUserAttendee1);
	vecAttendees.push_back(oUserAttendee2);

	//5. Req-1: Organizer can schedule m meetings.
	User oUserOrg("Amit", UserType::organizer);		//Create Organizer user
	if (oUserOrg.ScheduleMeeting(oMeetingScheduler, oStatusMeeting, vecAttendees))	//Organizer will create a meeting
		cout << "organier=Amit " << oStatusMeeting.GetMeetingSubject() << " Booked\n";
	
	return 0;
}