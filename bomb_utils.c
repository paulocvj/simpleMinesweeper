#include <stdlib.h>
#include "bomb_utils.h"

void placeBomb(char grid[][10], int bombSpotsX[], int bombSpotsY[], int i)
{
    bombSpotsX[i] = rand() % 10;
    bombSpotsY[i] = rand() % 10;
    if (grid[bombSpotsX[i]][bombSpotsY[i]] == BOMB_NUMBER) placeBomb(grid, bombSpotsX, bombSpotsY, i);
}