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

Game::Game()
{
	map = new Map();
	player.finished = false;
	player.row = 0;
	player.col = map.getWidth() / 2;
	player.penalty = 0;
	seconds = 0;
}

void Game::play()
{
	time_t startTime = time(NULL);
	while (!player.finished) {
		player = updatePosition(player, map);
		print_race(map, player);
		usleep(PAUSE);
	}
	time_t endTime = time(NULL);
	seconds = difftime(startTime, endTime) + player.penalty;
}

void Game::printResults()
{
	std::cout << "\nYour time was " << time << " seconds! Good job!";
}
