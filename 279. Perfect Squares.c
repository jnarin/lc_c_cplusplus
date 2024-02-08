/*
Link: https://leetcode.com/problems/perfect-squares/
Problem: 279. Perfect Squares
*/

#define MIN_VAL(a, b) (((a) < (b)) ? (a) : (b))

int numSquares(int n){
    int t = n + 1;
    int dp[t], i;

    for (i = 0; i < t; i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    int count = 1;
    int s = count * count;

    while (s <= n){
        for (i = s; i < t; i++){
            dp[i] = MIN_VAL(dp[i - s] + 1, dp[i]);
        }

        count++;
        s = count * count;
    }

    return dp[n];
}