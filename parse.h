// parse.h
#include map.h
#include User.h

User update_position(User user, map road);
bool reached_finish(User user, map road);
User move_left(User user, map road);
User move_right(User user, map road);
bool hit_object(User user, map road);



