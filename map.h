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

class Map {
public:
        /* Default constructor */
        Map();

        /* Constructor with parameters */
        Map(int row, int col);

        /* Destructor */
        ~Map();

        /* Intializes a map */
        void newMap();

        /* Gets line i of the map */
        char *getMapLine(int i);

        int getHeight();
        int getWidth();
private:
        /* Used when client doesn't specify rows or cols */
        static const int DEFAULT_ROWS = 10000;
        static const int DEFAULT_COLS = 80;

        /* Needs to include intialization for map ASCII chars */
        static const char B_STR;
        static const char B_LFT;
        static const char B_RT;
        static const char OOB;
        static const char RD;
        static const int ROAD_WIDTH = 40; /* so width >= 60 TODO */
        /* Make int FIRST_ROW = 0; ? */

        char **map;
        int rows;
        int cols;

        char *createMapRow(int i);
        char *createFirst();
        char *createNext(int lastRow);
};

#endif /* MAP_H_ */
