/*
 * Link: https://leetcode.com/problems/unique-paths-ii/
 * Problem: 63. Unique Paths II
 * */

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    const int R = obstacleGridSize, C = obstacleGridColSize[0];
    int r, c;

    if (obstacleGrid[0][0] == 1){
        return 0;
    }

    int dp[R][C];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (r = 0; r < R; r++){
        for (c = 0; c < C; c++){
            if (r == 0 && c == 0){
                continue;
            }

            if (obstacleGrid[r][c] == 1){
                continue;
            }

            if (r > 0){
                dp[r][c] += dp[r - 1][c];
            }

            if (c > 0){
                dp[r][c] += dp[r][c - 1];
            }
        }
    }

    return dp[R - 1][C - 1];

}
