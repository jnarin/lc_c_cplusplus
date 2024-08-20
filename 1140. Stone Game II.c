/*
Link: https://leetcode.com/problems/stone-game-ii/
Problem: 1140. Stone Game II
*/
#define MIN_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b; })


#define MAX_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b; })


static int solve(int i, int j, int *piles, int pilesSize, int dp[pilesSize][pilesSize], int *suffixSum){
    if (i + (j << 1) >= pilesSize){
        return suffixSum[i];
    }

    if (dp[i][j]){
        return dp[i][j];
    }
    
    int opp = suffixSum[i], k;
    for (k = 1; k <= (j << 1); k++){
        opp = MIN_VAL(opp, 
                      solve(i + k, MAX_VAL(j, k), 
                      piles, pilesSize, dp, suffixSum));
    }
    
    dp[i][j] = suffixSum[i] - opp;
    
    return dp[i][j];
}

int stoneGameII(int* piles, int pilesSize){
    int dp[pilesSize][pilesSize], suffixSum[pilesSize], i;
    
    memset(dp, 0, sizeof(dp));
    memcpy(suffixSum, piles, sizeof(suffixSum));
    
    for (i = pilesSize - 2; i >= 0; i--){
        suffixSum[i] += suffixSum[i + 1];
    }
    
    return solve(0, 1, piles, pilesSize, dp, suffixSum);
}

