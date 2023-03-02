#include <stdio.h>
#include "grid_utils.h" 

void generateGrid(char grid[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            grid[i][j] = '*';
        }
    }
}

void generateInterpol(char gridInterpol[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gridInterpol[i][j] = -1;
        }
    }    
}

void generateVisited(char gridVisited[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            gridVisited[i][j] = 0;
        }
    }
}

void generateTilesNumber(char grid[][10])
{
    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] != 99)
            {
                if (i != 0 && j != 9)
                {
                    if (grid[i-1][j+1] == 99) counter++;
                }
                if (i != 9 && j != 0)
                {
                    if (grid[i+1][j-1] == 99) counter++;
                }
                if (i != 0)
                {
                    if (grid[i-1][j] == 99) counter++;
                }
                if (j != 0)
                {
                    if (grid[i][j-1] == 99) counter++;
                }
                if (i != 9)
                {
                    if (grid[i+1][j] == 99) counter++;
                }
                if (j != 9)
                {
                    if (grid[i][j+1] == 99) counter++;
                }
                if (i != 9 && j != 9)
                {
                    if (grid[i+1][j+1] == 99) counter++;
                }
                if (i != 0 && j != 0)
                {
                    if (grid[i-1][j-1] == 99) counter++;
                }
                grid[i][j] = counter;
                counter = 0;
            }
        }
    }
}

void printGrid(char grid[][10], char gridInterpol[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (gridInterpol[i][j] == -1) printf("* ");
            else if (gridInterpol[i][j] == 'b') printf("b ");
            else printf("%d ", gridInterpol[i][j]);
        }
        printf("\n");
    }
}

void activateTile(char grid[][10], char gridInterpol[][10], char gridVisited[][10], int x, int y)
{
    gridInterpol[x][y] = grid[x][y];
    if (grid[x][y] == 99) gridInterpol[x][y] = 'b';
    if (grid[x][y] == 0 && gridVisited[x][y] != 1)
    {
        gridVisited[x][y] = 1;
        if (x-1 >= 0) activateTile(grid, gridInterpol, gridVisited, x-1, y);
        if (y+1 <= 9) activateTile(grid, gridInterpol, gridVisited, x, y+1);
        if (x+1 <= 9) activateTile(grid, gridInterpol, gridVisited, x+1, y);
        if (y-1 >= 0) activateTile(grid, gridInterpol, gridVisited, x, y-1);
    }
    
}