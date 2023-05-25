/*
LinK: https://leetcode.com/problems/new-21-game/
Problem: 837. New 21 Game
*/

double new21Game(int n, int k, int maxPts){
    if (k == 0 || n >= maxPts + k - 1){
        return 1.0;
    }

    double ans = 0.0, windowSum, dp[n + 1];
    int i;
    memset(dp, 0, sizeof(dp));
    dp[0] = windowSum = 1.0;
    
    for (i = 1; i <= n; i++){
        dp[i] = windowSum / maxPts;
        if (i < k){
            windowSum += dp[i];
        } else {
            ans += dp[i];
        }
        
        windowSum = i - maxPts >= 0 ? windowSum - dp[i - maxPts] : windowSum;
    }
    
    return ans;

}