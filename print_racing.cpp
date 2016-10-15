/*
 * print_racing.cpp
 * by Nick Metzger
 * working with Iris Oliver,
 * Leah Stern, Elias Marcopolis, Andrew Savage
 * rASCIIng
 *
 * Prints out the current view of the game.
 */


#include "print_racing.h"

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*
 * Purpose:     Prints the current grid of the 2D array of the racing map.
 * Parameters:  map is the map to be printed from
 * Value returned: None (void function).
 */
void print_race(Map *map, User car)
{
        int map_width = map->getWidth();
        int map_height = map->getHeight();
        //for (int i = 0; /*i < number of grid views*/; i++)
        //{
                for (int j = VIEW_LENGTH + car.row; j > car.row - 4; j--)
                {
                        if (j < map_height)
                        {
                                char *row = map->getMapLine(j);
                                print_row(car, row, map_width, j);
                        } else {
//                                addch('\n');
                                fputc('\n', stdout);
                        }
                }

        //}
}

/*i
 * Purpose:     Prints out the characters associated with the contents of the 
 *              map row.
 * Parameters:  row is the pointer to the array of characters.
 * Value returned: None (void function).
 */


void print_row(User car, char *row, int width, int row_index)
{
        for (int i = 0; i < width; i++)
        {
                if (row_index == car.row && i == car.col)
                {
//                       addch(CAR_BUMPER);         
                       fputc(CAR_BUMPER, stdout);         

                }

                else if (row_index == car.row - 1 && i == car.col - 2)      
                {
//                        addch(CAR_WHEEL);
                        fputc(CAR_WHEEL, stdout);
//                        addch(CAR_EDGE);
                        fputc(CAR_EDGE, stdout);
//                        addch(' ');
                        fputc(' ', stdout);
//                        addch(CAR_EDGE, stdout); 
                        fputc(CAR_EDGE, stdout); 
//                        addch(CAR_WHEEL);
                        fputc(CAR_WHEEL, stdout);
                        i += 4;

                }
                else if (row_index == car.row - 2 && i == car.col - 1)  
                {
//                        addch(CAR_EDGE);
                        fputc(CAR_EDGE, stdout);
//                        addch(' ');
                        fputc(' ', stdout);
//                        addch(CAR_EDGE);
                        fputc(CAR_EDGE, stdout);
                        i += 2;
                }
                else if (row_index == car.row - 3 && i == car.col - 2) 
                {
//                        addch(CAR_WHEEL);
                        fputc(CAR_WHEEL, stdout);
//                        addch(CAR_EDGE);
                        fputc(CAR_EDGE, stdout);
//                        addch(CAR_BUMPER);
                        fputc(CAR_BUMPER, stdout);
//                        addch(CAR_EDGE); 
                        fputc(CAR_EDGE, stdout); 
//                        addch(CAR_WHEEL);
                        fputc(CAR_WHEEL, stdout);
                        i+=4;
                }
                else
                {
//                        addch(row[i]);
                    fputc(row[i], stdout);
                }
                if (i == width - 1)
                {
//                        addch('\n');
                        fputc('\n', stdout);
                }

        }
} 