#include "MeetingScheduler.h"
#include "Notification.h"
#include "MeetingRoom.h"

bool MeetingScheduler::ScheduleMeeting(Meeting& mt, vector<User>& vecAttendees) {
	//Check Duration, Number of Attendees &
	//Allocate a meeting room accordingly
	for (auto i : m_vecMeetingRoomsInfo) {
		if (i.first == false) {	//Room is available
			if (i.second.GetRoomCapacity() > mt.GetAttendees()) {
				i.first = true;		//Mark this room booked
				//m_oNotification.SendNotification(vecAttendees, mt.GetMeetingSubject());
				return true;
			}
		}
	}
	return false;
}