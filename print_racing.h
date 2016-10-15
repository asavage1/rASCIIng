/*
 * print_racing.h
 * by Nick Metzger
 * working with Iris Oliver, Leah Stern,
 * Andrew Savage and Elias Marcopolis
 *
 * rASCIIng
 *
 * Function declarations for print_racing.c
 */

#ifndef PRINT_RACING_H
#define PRINT_RACING_H

#include "map.h"
#include "user.h"

const int VIEW_LENGTH = 20;
const char CAR_BUMPER = '_';
const char CAR_EDGE = '|';
const char CAR_WHEEL = 'O';


void print_race(Map map, User car);

void print_row(User car, char *row, int width, int row_index);

#endif // PRINT_RACING_H
