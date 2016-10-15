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
using namespace std;

/*
 * Purpose:     Prints the current grid of the 2D array of the racing map.
 * Parameters:  map is the map to be printed from
 * Value returned: None (void function).
 */
void print_race(Map *map, User car)
{

        int map_width = map->getWidth();
        //int map_height = map.get_map_height();
        //for (int i = 0; /*i < number of grid views*/; i++)
        //{
                for (int j = VIEW_LENGTH + car.row; j > car.row - 4; j--)
                {
                        char *row = map->getMapLine(j);
                        print_row(car, row, map_width, j);
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
                       cout << CAR_BUMPER;         
                }

                else if (row_index == car.row - 1 && i == car.col - 2)      
                {
                        cout << CAR_WHEEL << CAR_EDGE << " " << CAR_EDGE 
                            << CAR_WHEEL;
                        i += 4;

                }
                else if (row_index == car.row - 2 && i == car.col - 1)  
                {
                        cout << CAR_EDGE << " " << CAR_EDGE;
                        i += 2;
                }
                else if (row_index == car.row - 3 && i == car.col - 2) 
                {
                        cout << CAR_WHEEL << CAR_EDGE << CAR_BUMPER 
                            << CAR_EDGE << CAR_WHEEL;
                        i+=4;
                }
                else
                {
                    cout << row[i];
                }
                if (i == width - 1)
                {
                        cout << endl;
                }

        }

}
