/*
 * Problem: 463. Island Perimeter
 * Link: https://leetcode.com/problems/island-perimeter/
 * */

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int islands, neighbors, i, j;

    islands = neighbors = 0;

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j]) {
                islands++;
                neighbors = ((i - 1) >= 0) && grid[i - 1][j] ? neighbors + 1 : neighbors;
                neighbors = ((j - 1) >= 0) && grid[i][j - 1] ? neighbors + 1 : neighbors;
            }
        }
    }

    return (islands * 4) - (neighbors * 2);
}


