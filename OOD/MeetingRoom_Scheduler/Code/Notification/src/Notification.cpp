#include "Notification.h"

bool Notification::SendNotification(vector<User>& vecUsers, string& strMsg) {
	for (auto i : vecUsers)
		i.GetMeetingNotification(strMsg);
	return true;
}