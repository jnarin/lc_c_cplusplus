/*
Problem: 1039. Minimum Score Triangulation of Polygon
Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
*/

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minScoreTriangulation(int* values, int valuesSize) {
    int n = valuesSize;
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int length = 2; length < n; length++) {
        for (int i = 0; i + length < n; i++) {
            int j = i + length;
            dp[i][j] = __INT_MAX__;
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
            }
        }
    }

    return dp[0][n - 1];
    
}
