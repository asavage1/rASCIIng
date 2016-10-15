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

using namespace std;

Game::Game()
{
	player.finished = false;
	player.row = 0;
	player.col = map.getWidth() / 2;
	player.penalty = 0;
	seconds = 0;
}

void Game::play()
{

	cout << "here" << endl;
	time_t startTime = time(NULL);
	while (!player.finished) {
		cout << "hereeeee" << endl;
		player = updatePosition(player, map);

		cout << "hereeeee" << endl;
		print_race(map, player);
		
		cout << "hereeeee" << endl;
		usleep(PAUSE);
	}
	time_t endTime = time(NULL);
	seconds = difftime(startTime, endTime) + player.penalty;
}

void Game::printResults()
{
	std::cout << "\nYour time was " << seconds << " seconds! Good job!";
}
