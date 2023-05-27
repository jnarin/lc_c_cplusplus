/*
Link: https://leetcode.com/problems/stone-game-iii/
Problem: 1406. Stone Game III
*/
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })


static int solve(int *stoneValue, int *dp, int stoneValueSize, int i){
    if (i >= stoneValueSize){
        return 0;
    }
    
    if (dp[i] != INT_MIN){
        return dp[i];
    }
    
    int sum = 0, j;
    
    for (j = i; j < stoneValueSize && j < i + 3; j++){
        sum += stoneValue[j];
        dp[i] = MAXVAL(dp[i], sum - solve(stoneValue, dp, stoneValueSize, j + 1));
    }
    
    return dp[i];
}

char * stoneGameIII(int* stoneValue, int stoneValueSize){
    int i, dp[stoneValueSize];
    
    for (i = 0; i < stoneValueSize; i++){
        dp[i] = INT_MIN;
    }
    
    int ans = solve(stoneValue, dp, stoneValueSize, 0);
    
    if (ans < 0){
        return "Bob";
    }
    
    if (ans > 0) {
        return "Alice";
    }
    
    return "Tie";
}