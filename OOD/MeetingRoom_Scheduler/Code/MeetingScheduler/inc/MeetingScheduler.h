#pragma once
#include "MeetingRoom.h"
#include "Notification.h"
#include "Meeting.h"
#include "common.h"
//class MeetingRoom;
class User;
class Notification;
//class Meeting;
constexpr auto MAX_MEETING_ROOMS = 30;

class MeetingScheduler {
	vector<pair<bool, MeetingRoom>> m_vecMeetingRoomsInfo;
	//Notification m_oNotification;
public:
	MeetingScheduler(vector<MeetingRoom>& mr, Notification& n) {
		for (auto i : mr) {
			if (mr.size() > MAX_MEETING_ROOMS) {
				cout << "Max meeting rooms exceeded";
			}
			m_vecMeetingRoomsInfo.push_back(make_pair(false, i));
		}
		//Requirement-4: Send notifications
		//m_oNotification = n;
	}

	bool ScheduleMeeting(Meeting& mt, vector<User>& vecAttendees);
};