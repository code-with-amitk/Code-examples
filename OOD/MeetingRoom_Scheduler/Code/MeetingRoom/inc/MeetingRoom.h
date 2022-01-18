#pragma once

class MeetingRoom {
	int capacity;
	float len, width;
public:
	//Requirment-3: Default room capacity=10.
	MeetingRoom() :capacity(10), len(40), width(50) {}
	MeetingRoom(int c, float l, float w) :capacity(c), len(l), width(w) {}
	int GetRoomCapacity();
};