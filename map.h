/*
 * map.h
 * Polyhack 2016, 10/14/16
 *
 * Generates a two dimensional array of characters based on user input (or if
 * none is provided, uses default sizes) that represents a race course for
 * the rASCIIng program.
 */

#ifndef MAP_H_
#define MAP_H_

const char OOB = 'X';
const char RD = ' ';
const char B_STR = '|';
const char B_LFT = '\\';
const char B_RT = '/';
const char OBS = '^';
const char FIN_LINE = '=';

class Map {
public:
        /* Default constructor */
        Map();

        /* Constructor with parameters */
        Map(int height, int width);

        /* Destructor */
        ~Map();

        /* Intializes a map */
        void newMap();

        /* Gets line i of the map */
        char *getMapLine(int i);

        int getHeight();
        int getWidth();
        char getElement(int row, int col);
private:
        /* Used when client doesn't specify rows or cols */
        static const int DEFAULT_ROWS = 500;
        static const int DEFAULT_COLS = 50;
        static const int ROAD_WIDTH = 30; /* so width >= 60 TODO */
        /* Make int FIRST_ROW = 0; ? */
        static const int MAX_OFFSET = 3;
        static const int OBS_FREQUENCY = 30;
        static const int OBS_WIDTH = 3;

        char **map;
        int rows;
        int cols;
        char prevBoundary;

        char *createMapRow(int i);
        char *createFirst();
        char *createNext(int lastRow);
        int getBoundaryIndex(int row);
        char *addObs(char *row, char bound);
};

#endif /* MAP_H_ */
