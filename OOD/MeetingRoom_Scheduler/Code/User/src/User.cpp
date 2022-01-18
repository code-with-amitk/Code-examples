#include "User.h"
#include"MeetingScheduler.h"

bool User::ScheduleMeeting(MeetingScheduler& ms, Meeting mt, vector<User>& vecAttendees) {
	if (this->m_UserType != UserType::organizer) {
		cout << "Attendee cannot organize a meeting\n";
		return false;
	}
	if (ms.ScheduleMeeting(mt, vecAttendees)) {
		//Send Notification
		return true;
	}
	return false;
}
