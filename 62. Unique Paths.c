/*
Link: https://leetcode.com/problems/unique-paths/
Problem: 62. Unique Paths
*/

int uniquePaths(int m, int n){
    int dp[n], i, j;
    for (i = 0; i < n; i++){
        dp[i] = 1;
    }
    
    for (i = 1; i < m; i++){
        for (j = 1; j < n; j++){
            dp[j] += dp[j - 1];
        }
    }
    
    return dp[n - 1];
}