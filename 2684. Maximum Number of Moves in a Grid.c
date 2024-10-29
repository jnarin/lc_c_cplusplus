/*
Problem: 2684. Maximum Number of Moves in a Grid
Link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxMoves(int** grid, int gridSize, int* gridColSize) {
    int ans = 0, m = gridSize, n = gridColSize[0], i, j;
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    
    for (j = n - 2; j >= 0; j--) {
        for (i = 0; i < m; i++) {
            if (grid[i][j + 1] > grid[i][j]) {
                dp[i][j] = dp[i][j + 1] + 1;
            }
            
            if (i > 0 && grid[i - 1][j + 1] > grid[i][j]) {
                dp[i][j] = MAXVAL(dp[i][j], dp[i - 1][j + 1] + 1);
            }
            
            if (i + 1 < m && grid[i + 1][j + 1] > grid[i][j]) {
                dp[i][j] = MAXVAL(dp[i][j], dp[i + 1][j + 1] + 1);
            }
        }
    }
    
    for (i = 0; i < m; i++) {
        ans = MAXVAL(ans, dp[i][0]);
    }
    
    return ans;
}
