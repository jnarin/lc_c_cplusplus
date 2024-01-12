/*
 * Link: https://leetcode.com/problems/find-champion-i/
 * Problem: 2923. Find Champion I
 * */

int findChampion(int** grid, int gridSize, int* gridColSize) {
    int i;

    for (i = 0; i < gridSize; i++) {
        int j;
        int sum = 0;
        for (j = 0; j < gridColSize[i]; j++) {
            sum += grid[i][j];
        }

        if (sum == gridSize - 1) {
            return i;
        }
    }

    return -1;
}

