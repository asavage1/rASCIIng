#ifndef PARSE_H
#define PARSE_H

// parse.h
#include "map.h"
#include "game.h"
#include "user.h"
#include <iostream>

User updatePosition(User user, Map road);
bool reached_finish(User user, Map road);
User move_left(User user);
User move_right(User user);
bool hit_object(User user);


#endif /* PARSE_H */
