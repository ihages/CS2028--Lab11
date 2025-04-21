April 19, 7:09 PM Evan O
- Added functionality for bat and pit room, added text for wumpus room. 
- Added text when neighboring room has something in it. 
- Map now generates with hazards in a random room. 
- Added debug for now that lets you know which rooms things are in. 
- Added the member to Room to track which rooms you have been to. 
- Added functions in main to make rooms visted.

Changed some functionality in Graph.cpp, changed all the addEdge so that they are 1 less so we dont need to subtract 1 from start and end.
Added vertices array for keeping track of all the rooms. 

Need to add functionality for shooting arrows, hitting the wumpus, wumpus moving, winning if you enter wumpus room with arrow, or losing if you enter without arrows. 

Currently nothing is done based on whether a room was visited or not. Should probably add something like "(visited)" to room that you have visited when observing.

April 21, 1:43 PM Evan O
- Added arrow pathing
- Added Wumpus pathing
- Added messages for arrows
- Moved locations of hazards text into print