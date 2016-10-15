// Nick, Iris, Leah, Andrew, and Elias
// 10/14/16
//
// rASCIIng main race game class

#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "user.h"

class Game
{
public:
	Game();
	void play();
	void printResults();

private:
	const static unsigned int PAUSE = 100;
	Map map;
	User player;
	double seconds;
};

#endif // GAME_H