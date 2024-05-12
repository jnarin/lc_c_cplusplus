/*
 * Problem: 2373. Largest Local Values in a Matrix
 * Link: https://leetcode.com/problems/largest-local-values-in-a-matrix/
 * */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int **ans, i, j, x, y, t;

    t = gridSize - 2;


    ans = calloc(t, sizeof(int *));
    *returnSize = t;
    *returnColumnSizes = calloc(gridSize, sizeof(int));

    for (i = 0; i < t; i++) {
        ans[i] = calloc(t, sizeof(int));
        (*returnColumnSizes)[i] = t;
    }

    for (i = 0; i < t; i++) {
        for (j = 0; j < t; j++) {
            for (x = i; x < i + 3; x++) {
                for (y = j; y < j + 3; y++) {
                    ans[i][j] = MAXVAL(ans[i][j], grid[x][y]);
                }
            }
        }
    }

    return ans;
}
