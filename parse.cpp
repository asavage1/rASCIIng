// parse.cpp
#include "parse.h"
#include <iostream>
using namespace std;


/* Purpose: updates the position of the car and validates that it has
 *		not collided with anything
 * Parameters: the user to be updated, the map 
 * Value returned: modified user struct
 */
User updatePosition(User user, Map &road)
{
		char input;

		if (reached_finish(user, road)) {
				user.finished = true;
				return user;
		}

//		while(!reached_finish(user, road)) {
//			input = getch();
		cin >> input;
		if (input == 'a') {
				user = move_left(user, road);
		} else if (input == 'd') {
				user = move_right(user, road);
		}
//}
		return user;
		
}

/* Purpose: checks if the user is at the finish line
 * Parameters: the user and the map
 * Value returned: true if at finish line, false if not
 */
bool reached_finish(User user, Map &road) 
{

		if (user.row == road.getHeight()) {
				return true;
		} else {
				return false;
		}

}

/* Purpose: moves the user to the left if has not collided
		with a wall, adds penalty if needed.
 * Parameters: the user, the map
 * Value returned: the updated user
 */
User move_left(User user, Map &road)
{
		if (hit_object_left(user, road)) {
				user.penalty++;
				return user;
		}

		user.col = user.col - 1;
		user.row = user.row + 1;
		return user;
}

/* Purpose: moves the user to the right if not a collision
		with a wall, add penalty if needed
 * Parameters: the user, the map
 * Value returned: the updated user
 */
User move_right(User user, Map &road)
{

        if (hit_object_right(user, road)) {
                user.penalty++;
        	return user;
	}
        
        user.row = user.row + 1;
        user.col = user.col + 1;
        return user;

}

/* Purpose: checks if the user has hit a wall or not
 * Parameters: the user, the road
 * Value returned: true if has hit and object, false if not
 */
bool hit_object_left(User user, Map &road)
{
	//ORIGINAL char top_left = road.getElement(user.row - 1, user.col - 3);
	char top_left = road.getElement(user.row , user.col + 3);

	char bot_left = road.getElement(user.row - 2, user.col + 3);
	//char middle_left = road.getElement(user.row - 2, user.col - 3);
	//char front = road.getElement(user.row - 3, user.col - 3);

	if (top_left == B_STR or top_left == B_LFT or top_left == B_RT) {
	    	cout << "true" << endl;
		return true;
	} else if (bot_left == B_STR or bot_left == B_LFT or bot_left == B_RT) {
	    	cout << "true" << endl;
		return true;
	}
        return false;

}

bool hit_object_right(User user, Map &road)
{
	char top_right = road.getElement(user.row - 1, user.col + 3);	
	char bot_right = road.getElement(user.row - 3, user.col + 3);
        
	if (top_right == B_STR or top_right == B_LFT or top_right == B_RT) {
		return true;
	} else if (bot_right == B_STR or bot_right == B_LFT or bot_right == B_RT) {
		return true;
	}
	return false;
}



