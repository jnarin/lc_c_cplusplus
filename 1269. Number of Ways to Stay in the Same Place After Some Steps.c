/*
Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
Problem: 1269. Number of Ways to Stay in the Same Place After Some Steps
*/
#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

#define CONST_MOD   (int)(1e9 + 7)

int numWays(int steps, int arrLen){
    
    int n = MINVAL(arrLen, (steps >> 1) + 1), i;
    int dp[n], tempDp[n];
    
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    while (steps--){
        memset(tempDp, 0, sizeof(tempDp));
        
        for (i = 0; i < n; i++){
            tempDp[i] = dp[i];
            tempDp[i] = i - 1 >= 0 ? (tempDp[i] + dp[i - 1]) % CONST_MOD : tempDp[i];
            tempDp[i] = i + 1 < n ?  (tempDp[i] + dp[i + 1]) % CONST_MOD : tempDp[i];
        }
        
        memcpy(dp, tempDp, sizeof(dp));
    }
    
    return dp[0];
}