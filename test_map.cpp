/*
 * test_map.cpp
 * Polyhack 2016, 10/14/16
 *
 * Tests created array and get functions for map function
 */

#include <iostream>
#include <string>
#include "map.h"

using namespace std;

int main()
{
        Map map;
        for (int i = map.getHeight() - 1; i >= 0; i--) {
                string str = map.getMapLine(i);
                cout << str << endl;
        }
        return 0;
}
