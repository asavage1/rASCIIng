/*
 * map.cpp
 * Polyhack 2016, 10/14/16
 *
 * Generates a two dimensional array of characters based on user input (or if
 * none is provided, uses default sizes) that represents a race course for
 * the rASCIIng program.
 */

/*
 * TODO:
 * Have user pass in whether or not it wants obstacles?
 * Use more string functions
 */

#include <string>
#include <stdlib.h>
#include "math.h"
#include "time.h"
#include "map.h"

Map::Map()
{
        rows = DEFAULT_ROWS;
        cols = DEFAULT_COLS;
        newMap();
}

Map::Map(int height, int width)
{
        /* Make sure parameters are reasonable */
        rows = height;
        cols = width;
        newMap();
}

Map::~Map()
{
        for (int i = 0; i < rows; i++) {
                delete [] map[i];
        }
        delete [] map;
}

void Map::newMap()
{
        srand(time(NULL));
        map = new char*[rows];
        for (int i = 0; i < rows; i++) {
                map[i] = createMapRow(i - 1);
        }
}

char *Map::getMapLine(int i)
{
        return map[i];
}

int Map::getHeight()
{
        return rows;
}

int Map::getWidth()
{
        return cols;
}

char *Map::createMapRow(int i)
{
        if (i < 0) {
                return createFirst();
        }
        return createNext(i);
}

char *Map::createFirst()
{
        char *row = new char[cols];
        for (int i = 0; i < cols; i++) {
                if (i < (cols - ROAD_WIDTH) / 2 - 1) {
                        row[i] = OOB;
                } else if (i == (cols - ROAD_WIDTH) / 2 - 1) {
                        row[i] = B_STR;
                } else if (i < (cols + ROAD_WIDTH) / 2) {
                        row[i] = RD;
                } else if (i == (cols + ROAD_WIDTH) / 2) {
                        row[i] = B_STR;
                } else {
                        row[i] = OOB;
                }
        }
        prevBoundary = B_STR;
        return row;
}

char *Map::createNext(int lastRow)
{
        char *row = new char[cols];
        int boundaryIndex = getBoundaryIndex(lastRow);

        int offset;
        if (boundaryIndex == 0) {
                offset = 1;
        } else if (boundaryIndex == getWidth() - 1 - ROAD_WIDTH) {
                offset = -1;
        } else if (map[lastRow][boundaryIndex] == B_LFT) {
                offset = rand()%(MAX_OFFSET - 1) - 1;
        } else if (map[lastRow][boundaryIndex] == B_RT) {
                offset = rand()%(MAX_OFFSET - 1);
        } else {
                offset = rand()%MAX_OFFSET - 1;
        }

        char boundaryChar;
        if (offset == -1) {
                boundaryChar = B_LFT;
        } else if (offset == 0) {
                boundaryChar = B_STR;
        } else {
                boundaryChar = B_RT;
        }

        for (int i = 0; i < cols; i++) {
                if (i < boundaryIndex + offset) {
                        row[i] = OOB;
                } else if (i == boundaryIndex + offset) {
                        row[i] = boundaryChar;
                } else if (i < boundaryIndex + offset + ROAD_WIDTH) {
                        row[i] = RD;
                } else if (i == boundaryIndex + offset + ROAD_WIDTH) {
                        row[i] = boundaryChar;
                } else {
                        row[i] = OOB;
                }
        }

        if (((lastRow + 1) % OBS_FREQUENCY) == 0) {
                row = addObs(row, row[boundaryIndex + offset]);
        }

        return row;
}

int Map::getBoundaryIndex(int row)
{
        int index;
        for (index = 0; index < cols; index++) {
                if (map[row][index] == B_STR || 
                    map[row][index] == B_LFT || 
                    map[row][index] == B_RT) {
                        break;
                }
        }
        return index;
}

char Map::getElement(int row, int col)
{
        return map[row][col];
}


char *Map::addObs(char *row, char bound)
{
        std::string str = row;
        size_t first = str.find_first_of(bound);
        size_t last = str.find_last_of(bound);
        int obsPos = rand()%(last - first - OBS_WIDTH) + first;
        for (int i = obsPos; i < obsPos + OBS_WIDTH; i++) {
                row[i] = OBS;
        }
        return row;
}
