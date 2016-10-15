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

char OOB = 'X';
char RD = ' ';
char B_STR = '|';
char B_LFT = '\';
char B_RT = '/';
char VIEW_LENGTH = 20;
char CAR_BUMPER = '_';
char CAR_EDGE = '|';
char CAR_WHEEL = 'O';


void print_race(Map map, User car);

void print_row(char *row, int width, int row_index);
