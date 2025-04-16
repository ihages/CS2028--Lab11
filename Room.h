#ifndef __ROOM__
#define __ROOM__

class Room {
	int roomNumber;
	std::string roomType;
	bool hasArrow;

	Room() : roomType(" "), roomNumber(), hasArrow(false){};
	Room(std::string contents) : roomType(contents), roomNumber(), hasArrow(false) {};

	void setRoom(std::string contents) {
		roomType = contents;
	}
	bool isRoomEmpty() { return roomType != "Bats" || roomType != "Pit" || roomType != "Wumpus"; }

	friend std::ostream& operator<<(std::ostream& os, const Room& right) {
		if (right.roomType == "Bats") {
			os << "You hear screeching";
		}
		else if (right.roomType == "Pit") {
			os << "You feel a breeze";
		}
		else if (right.roomType == "Wumpus") {
			os << "You smell an animal";
		}
		else {
			os << "";
		}
		return os;
	}
};

#endif
#pragma once
