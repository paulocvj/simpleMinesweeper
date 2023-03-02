#ifndef GRID_UTILS_H_
#define GRID_UTILS_H_

void generateGrid(char grid[][10]);
void generateInterpol(char gridInterpol[][10]);
void generateVisited(char gridVisited[][10]);
void printGrid(char grid[][10], char gridInterpol[][10]);
void generateTilesNumber(char grid[][10]);
void activateTile(char grid[][10], char gridInterpol[][10], char gridVisited[][10], int x, int y);

#endif // GRID_UTILS_H_