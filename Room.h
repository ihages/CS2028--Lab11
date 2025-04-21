#ifndef __ROOM__
#define __ROOM__

class Room {
	private:
		int roomNumber;
		std::string roomType;
		bool hasArrow;
		bool playerVisited;

	public:
		Room() : roomType(" "), roomNumber(-1), hasArrow(false), playerVisited(false) {};
		Room(std::string contents) : roomType(contents), roomNumber(-1), hasArrow(false), playerVisited(false) {};
		Room(std::string contents, int roomNum) : roomType(contents), roomNumber(roomNum), hasArrow(false), playerVisited(false) {};

		bool isRoomEmpty() { return roomType != "Bats" && roomType != "Pit" && roomType != "Wumpus"; }

		std::string roomMessage() {
			if (roomType == "Bats") {
				return "You hear screeching";
			} else if (roomType == "Pit") {
				return "You feel a breeze";
			} else if (roomType == "Wumpus") {
				return "You smell an animal";
			} else {
				return "";
			}
		}

		void visitRoom() {
			playerVisited = true;
		}

		bool getVisited() {
			return playerVisited;
		}

		void arrowLanded() {
			hasArrow = true;
		}

		void pickupArrow() {
			hasArrow = false;
		}

		void setRoomType(std::string updatedRoom) {
			roomType = updatedRoom;
		}

		int getRoomNumber() { return roomNumber; }
		int getRoomIndex() { return roomNumber - 1; }
		std::string getRoomType() { return roomType; }
		bool isVisited() { return playerVisited; }
		bool isArrowHere() { return hasArrow; }
		bool isWumpusRoom() { return roomType == "Wumpus"; }

		bool operator== (const Room &right) {
			return this->roomNumber == right.roomNumber;
		}

};

#endif
#pragma once
