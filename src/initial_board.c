#include <stdint.h>
#include "heptachess_board.h"

const uint8_t INITIAL_GRID[19][19] = {
    {0, 0, 121, 119, 115, 113, 114, 119, 121, 0, 105, 103, 99, 97, 98, 103, 105, 0, 0},
    {0, 0, 0, 121, 119, 116, 119, 121, 0, 0, 0, 105, 103, 100, 103, 105, 0, 0, 0},
    {0, 0, 0, 0, 120, 117, 120, 0, 0, 0, 0, 0, 104, 101, 104, 0, 0, 0, 89},
    {0, 0, 0, 0, 0, 118, 0, 0, 0, 0, 0, 0, 0, 102, 0, 0, 0, 89, 87},
    {0, 0, 0, 0, 0, 122, 0, 0, 0, 0, 0, 0, 0, 106, 0, 0, 88, 87, 83},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 86, 85, 84, 81},
    {25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 87, 82},
    {23, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 89, 87},
    {18, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 89},
    {17, 20, 21, 22, 26, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {19, 23, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73},
    {23, 25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73, 71},
    {25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 71, 67},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74, 70, 69, 68, 65},
    {0, 0, 0, 0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 58, 0, 0, 72, 71, 66},
    {0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 73, 71},
    {0, 0, 0, 0, 40, 37, 40, 0, 0, 0, 0, 0, 56, 53, 56, 0, 0, 0, 73},
    {0, 0, 0, 41, 39, 36, 39, 41, 0, 0, 0, 57, 55, 52, 55, 57, 0, 0, 0},
    {0, 0, 41, 39, 34, 33, 35, 39, 41, 0, 57, 55, 50, 49, 51, 55, 57, 0, 0}
};