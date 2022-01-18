#pragma once
#include "common.h"

class Meeting {
	float duration;
	int attendees;
	string subject;
	string agenda;
public:
	Meeting(float d, int a, string s) :duration(d), attendees(a), subject(s) {}
	int GetAttendees();
	string GetMeetingSubject();
};
