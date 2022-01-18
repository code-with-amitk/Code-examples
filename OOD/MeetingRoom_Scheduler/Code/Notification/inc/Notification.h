#pragma once
#include "User.h"
#include "common.h"
class User;

class Notification {
public:
	Notification() {}
	bool SendNotification(vector<User>& vecUsers, string& strMsg);
};

class test {
public:
	test(){}
};