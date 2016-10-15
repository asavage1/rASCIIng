// Nick, Iris, Leah, Andrew, and Elias
// 10/14/16
//
// code for race game class

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "game.h"
#include "parse.h"
#include "print_racing.h"
#include <windows.h>

using namespace std;

Game::Game()
{
	player.finished = false;
	player.row = 4;
	player.col = map.getWidth() / 2;
	player.penalty = 0;
	seconds = 0;
}

void Game::play()
{
	bool i = false;
	time_t startTime = time(NULL);
	print_race(&map, player);
	while (!player.finished) {
		player = updatePosition(player, map);
		if (i++ % 2) {
			print_race(&map, player);
		}
		Sleep(PAUSE);
	}
	time_t endTime = time(NULL);
	seconds = difftime(endTime, startTime) + player.penalty;
}

void Game::printResults()
{
	std::cout << "\nYour time was " << seconds << " seconds! Good job!\n";
}
