// Nick, Iris, Leah, Andrew, and Elias
// 10/14/16
//
// rASCIIng -- C++ Racing Terminal Game

#include <iostream>
#include <ncurses.h>
#include "game.h"
using namespace std;

int main () {
	Game race;
	race.play();
	race.printResults();
	return 0;
}
