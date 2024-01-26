/*
Link: https://leetcode.com/problems/out-of-boundary-paths/
Problem: 576. Out of Boundary Paths
*/

static int dfs(int m, int n, int maxMove, int i, int j, int ***dp) {
    static const int DIVMOD = (1e9 + 7);
    
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return 1;
    }
    
    if (maxMove <= 0) {
        return 0;
    }
    
    if (dp[i][j][maxMove] != -1) {
        return dp[i][j][maxMove];
    }
        
    long ans = 0;
    
    ans += dfs(m, n, maxMove - 1, i + 1, j, dp);
    ans += dfs(m, n, maxMove - 1, i - 1, j, dp);
    ans += dfs(m, n, maxMove - 1, i, j + 1, dp);
    ans += dfs(m, n, maxMove - 1, i, j - 1, dp);
    
    dp[i][j][maxMove] = ans % DIVMOD;
    
    return dp[i][j][maxMove];
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int i, j, k;
    
    int ***dp = calloc(m, sizeof(int **));
    for (i = 0; i < m; i++) {
        dp[i] = calloc(n, sizeof(int *));
        for (j = 0; j < n; j++) {
            dp[i][j] = calloc(maxMove + 1, sizeof(int));
            for (k = 0; k < maxMove + 1; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int ans = dfs(m, n, maxMove, startRow, startColumn, dp);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            free(dp[i][j]);
        }
        
        free(dp[i]);
    }
    free(dp);
    
    return ans;
}