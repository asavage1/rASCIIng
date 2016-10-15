// Nick, Iris, Leah, Andrew, and Elias
// 10/14/16
//
// rASCIIng -- C++ Racing Terminal Game

#include <iostream>
#include "game.h"
using namespace std;

int main () {
	Game race = new Game();
	race.play();
	race.printResults();
	return 0;
}