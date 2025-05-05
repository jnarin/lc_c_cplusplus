/*
Problem: 790. Domino and Tromino Tiling
Link: https://leetcode.com/problems/domino-and-tromino-tiling/
*/

int numTilings(int n){
    const long long mod_ = 1e9 + 7;

    if (n < 3){
        return n;
    }

    int i;
    long long dp[n + 1][3];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = dp[1][0] = 1;
    dp[1][1] = dp[1][2] = 1;
    
    for (i = 2; i <= n; i++){
        dp[i][0] = (dp[i - 1][0] + dp[i -2][0] + dp[i - 2][1]  + dp[i - 2][2]) % mod_;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod_;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod_;
    }

    return dp[n][0];
}

