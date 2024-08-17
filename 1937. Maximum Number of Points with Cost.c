/*
Problem: 1937. Maximum Number of Points with Cost
Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    long long dp[pointsColSize[0]];
    memset(dp, 0, sizeof(dp));
    
    int i, j;
    
    for (i = 0; i < pointsSize; i++) {
        long long lToR[pointsColSize[i]], max = 0;
        
        for (j = 0; j < pointsColSize[i]; j++) {
            max = MAXVAL(max - 1, dp[j]);
            lToR[j] = max;
        }
        
        long long rToL[pointsColSize[i]];
        max = 0;
        
        for (j = pointsColSize[i] - 1; j >= 0; j--) {
            max = MAXVAL(max - 1, dp[j]);
            rToL[j] = max;
        }
        
        for (j = 0; j < pointsColSize[i]; j++) {
            dp[j] = MAXVAL(lToR[j], rToL[j]) + points[i][j];
        }
    }
    
    long long ans = 0;
    
    for (i = 0; i < pointsColSize[0]; i++) {
        ans = MAXVAL(ans, dp[i]);
    }
    
    return ans;
}
