/*
Problem: 3963. Create Grid With Exactly One Path
Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    char **grid = calloc(m, sizeof(char *));
    *returnSize = m;

    for (int i = 0; i < m; i++) {
        grid[i] = calloc((n + 1), sizeof(char));
        for (int j = 0; j < n; j++) {
            grid[i][j] = (j == 0 || i == m - 1) ? '.' : '#';
        }
        grid[i][n] = '\0';
    }

    return grid;
}
