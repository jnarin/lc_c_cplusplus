/*
Problem: 3619. Count Islands With Total Value Divisible by K
Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
*/

int countIslands(int** grid, int gridSize, int* gridColSize, int k) {
    int m = gridSize, n = gridColSize[0],
        dirs[] = {-1, 0, 1, 0, -1}, ans = 0;
    
    long long dfs(int i, int j) {
        long long s = grid[i][j];
        
        grid[i][j] = 0;

        int d;

        for (d = 0; d < 4; d++) {
            int x = i + dirs[d], y = j + dirs[d + 1];

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]) {
                s += dfs(x, y);
            }
        }

        return s;
    }

    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] && (dfs(i, j) % k == 0)) {
                ans++;
            }
        }

    }

    return ans;    
}
