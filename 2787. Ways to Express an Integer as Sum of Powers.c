/*
Problem: 2787. Ways to Express an Integer as Sum of Powers
Link: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
*/

int numberOfWays(int n, int x) {
    const int mod = (int)(1e9 + 7);
    int i, dp[n + 1], p, a;

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for (a = 1; (p = pow(a, x)) <= n; a++) {
        for (i = n; i >= p; i--) {
            dp[i] = (dp[i] + dp[i - p]) % mod;
        }
    }

    return dp[n];
}
