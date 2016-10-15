// parse.cpp
#include "parse.h"
#include <iostream>
using namespace std;


/* Purpose: updates the position of the car and validates that it has
 *		not collided with anything
 * Parameters: the user to be updated, the map 
 * Value returned: modified user struct
 */
User updatePosition(User user, Map road)
{
		int penalty = 0;
		char input;

		if (reached_finish) {
				user.finished = true;
				return user;
		}

		cin >> input;
		if (input == 'a') {
				move_left(user, road);
		} else if (input == 'd') {
				move_right(user, road);
		}

		return user;
		
}

/* Purpose: checks if the user is at the finish line
 * Parameters: the user and the map
 * Value returned: true if at finish line, false if not
 */
bool reached_finish(User user, Map road) 
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
User move_left(User user, Map road)
{
		if (hit_object(user, road)) {
				user.penalty++;
		}

		user.col = user.col - 1;

		return user;
}

/* Purpose: moves the user to the right if not a collision
		with a wall, add penalty if needed
 * Parameters: the user, the map
 * Value returned: the updated user
 */
User move_right(User user, Map road)
{

		if (hit_object) {
				user.penalty++;
		}

		user.row = user.row - 1;

		return user;

}

/* Purpose: checks if the user has hit a wall or not
 * Parameters: the user, the road
 * Value returned: true if has hit and object, false if not
 */
bool hit_object(User user, Map road)
{

		if (user.col + 2 == B_STR or user.col + 2 == B_LFT or user.col + 2 == B_RT) {
				return true;
		} else if (user.col - 2 == B_STR or user.col - 2 == B_LFT or user.col - 2 == B_RT) {
				return true;
		} else if (user.row - 3 == B_STR or user.row - 3 == B_LFT or user.col - 2 == B_RT) {
				return true;
		} else if (user.row == B_STR or user.row == B_LFT or user.row == B_RT) {
				return true;
		}

		return false;
}












