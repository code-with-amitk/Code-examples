#pragma once
#include"MeetingScheduler.h"
#include"Meeting.h"
class MeetingScheduler;

class User {
	string name;
	UserType m_UserType;
public:
	User(string n, UserType ut) : name(n), m_UserType(ut) {}

	bool ScheduleMeeting(MeetingScheduler& ms, Meeting mt, vector<User>& vecAttendees);

	void GetMeetingNotification(string& strSubject) {
		cout << "Meeting " << strSubject << " Scheduled\n";
	}
};