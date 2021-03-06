#ifndef PARSE_H
#define PARSE_H

// parse.h
#include "map.h"
#include "game.h"
#include "user.h"
#include <iostream>
//#include <ncurses.h>

User updatePosition(User user, Map &road);
bool reached_finish(User user, Map &road);
User move_left(User user, Map &road);
User move_right(User user, Map &road);
bool hit_object_left(User user, Map &road);
bool hit_object_right(User user, Map &road);

#endif /* PARSE_H */
