// Nick, Iris, Leah, Andrew, and Elias
// 10/14/16
//
// rASCIIng main race game class

#include "map.h"
#include "user.h"

class Game
{
public:
	Game();
	void play();
	void printResults();

private:
	const static unsigned int PAUSE = 250000;
	Map map;
	User player;
	double seconds;
};