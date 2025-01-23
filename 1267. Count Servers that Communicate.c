/*
Problem: 1267. Count Servers that Communicate
Link: https://leetcode.com/problems/count-servers-that-communicate/
*/

int countServers(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0], i, j, ans = 0;
    int rows[m], cols[n];

    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            rows[i] += grid[i][j];
            cols[j] += grid[i][j];
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            ans += grid[i][j] && (rows[i] > 1 || cols[j] > 1);
        }
    }

    return ans;
}
