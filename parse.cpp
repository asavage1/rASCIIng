// parse.cpp

/* Purpose: updates the position of the car and validates that it has
 *		not collided with anything
 * Parameters: 
 * Value returned:
 */
User update_position(User user, map road)
{
		int penalty = 0;
		char input;

		if (reached_finish) {
				user.finished = true;
				return user;
		}

		cin >> input;
		if (input == 'a') {
				move_left(coords, road);
		} else if (input == 'd') {
				move_right(coords, road);
		}

		return user;
		
}


bool reached_finish(User user, map road) 
{

		if (user.row == map.get_height()) {
				return true;
		} else {
				return false;
		}

}


User move_left(User user, map road)
{
		if (hit_object) {
				user.penalty++;
		}

		user.col = user.col - 1;

		return user;
}


User move_right(User user, map road)
{

		if (hit_object) {
				user.penalty++;
		}

		user.row = user.row - 1;

		return user;

}

bool hit_object(User user, map road)
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












