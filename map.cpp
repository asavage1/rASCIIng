/*
 * map.h
 * Polyhack 2016, 10/14/16
 *
 * Generates a two dimensional array of characters based on user input (or if
 * none is provided, uses default sizes) that represents a race course for
 * the rASCIIng program.
 */

#include "math.h"
#include "time.h"
#include "map.h"

Map::Map()
{
        rows = DEFAULT_ROWS;
        cols = DEFAULT_COLS;
        newMap();
}

Map::Map(int width, int height)
{
        /* Make sure parameters are reasonable */
        rows = width;
        cols = height;
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
        srand(time(NULL));

        char *row;
        int boundaryIndex = getBoundaryIndex(lastRow);
        int offset = rand()%MAX_OFFSET - 1;
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
                } else if (i < boundaryIndex + offset + cols) {
                        row[i] = RD;
                } else if (i == boundaryIndex + offset + cols) {
                        row[i] = boundaryChar;
                } else {
                        row[i] OOB;
                }
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
