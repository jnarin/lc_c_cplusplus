/*
Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings
Problem: 712. Minimum ASCII Delete Sum for Two Strings
*/

#define MINVAL(a, b)\
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

int minimumDeleteSum(char * s1, char * s2){
    int i, j;
    int m = strlen(s1) + 1, n = strlen(s2) + 1;
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    
    for (i = 1; i < m; i++){
        dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }
    
    for (j = 1; j < n; j++){
        dp[0][j] = dp[0][j - 1] + s2[j - 1];
    }
    
    for (i = 1; i < m; i++){
        for (j = 1; j < n; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = MINVAL(dp[i - 1][j] + s1[i - 1],
                                 dp[i][j - 1] + s2[j - 1]);
            }
        }
    }
    
    return dp[m - 1][n - 1];
}
