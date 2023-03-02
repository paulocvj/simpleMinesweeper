#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "grid_utils.h"
#include "bomb_utils.h"

int main()
{
    srand(time(NULL));
    char grid[10][10];
    char gridInterpol[10][10];
    char gridVisited[10][10];
    int bombSpotsX[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int bombSpotsY[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int coordX, coordY;

    generateGrid(grid);
    generateInterpol(gridInterpol);
    generateVisited(gridVisited);

    for (int i = 0; i < 10; i++)
    {
        placeBomb(grid, bombSpotsX, bombSpotsY, i);
        grid[bombSpotsX[i]][bombSpotsY[i]] = BOMB_NUMBER;
    }

    generateTilesNumber(grid);
    printf("Game starting!\n");
    
    while(1)
    {
        printGrid(grid, gridInterpol);
        printf("Enter the coordinates: ");
        scanf("%d %d", &coordY, &coordX);
        activateTile(grid, gridInterpol, gridVisited, coordX, coordY);
        if (grid[coordX][coordY] == 99)
        {
            printGrid(grid, gridInterpol);
            printf("You lost!");
            break;
        }
    }

    return 0;
}