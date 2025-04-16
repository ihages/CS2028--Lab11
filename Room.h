<<<<<<< HEAD
#ifndef __ROOM__
#define __ROOM__

class Room {
	std::string roomType;

	Room() : roomType(" ") {};
	Room(std::string contents) : roomType(contents) {};

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
=======
#ifndef __ROOM__
#define __ROOM__

class Room {
	std::string roomType;

	Room() : roomType(" ") {};
	Room(std::string contents) : roomType(contents) {};

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
>>>>>>> d70e3559fa1c56efe6ed955c17a2fa2a4d58e608
