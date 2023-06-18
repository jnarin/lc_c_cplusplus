/*
 * Link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
 * Problem: 2328. Number of Increasing Paths in a Grid
 * */
#define MOD     (int)(1e9 + 7)

static int dfs(int **grid, const int m, const int n, int **dp, int i, int j){
    if (dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] = 1;

    int k, x, y;
    static const int dirs[] = {0, 1, 0, -1, 0};

    for (k = 0; k < 4; k++){
        x = i + dirs[k];
        y = j + dirs[k + 1];

        if (x < 0 || y < 0 || x >= m || y >= n){
            continue;
        }

        if (grid[x][y] <= grid[i][j]){
            continue;
        }

        dp[i][j] = (dp[i][j] + dfs(grid, m, n, dp, x, y)) % MOD;
    }

    return dp[i][j];
}

int countPaths(int** grid, int gridSize, int* gridColSize){
    int **dp;
    int ans = 0, i, j;

    dp = calloc(gridSize, sizeof(int *));
    for (i = 0; i < gridSize; i++){
        dp[i] = calloc(gridColSize[i], sizeof(int));
        for (j = 0; j < gridColSize[i]; j++){
            dp[i][j] = -1;
        }
    }

    for (i = 0; i < gridSize; i++){
        for (j = 0; j < gridColSize[i]; j++){
            ans = (ans + dfs(grid, gridSize, gridColSize[i], dp, i, j)) % MOD;
        }
    }

    for (i = 0; i < gridSize; i++){
        free(dp[i]);
    }
    free(dp);

    return ans;
}
