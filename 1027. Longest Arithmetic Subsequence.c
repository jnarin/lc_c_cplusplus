/*
Link: https://leetcode.com/problems/longest-arithmetic-subsequence/
Problem: 1027. Longest Arithmetic Subsequence
*/
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

#define MAXNUMVAL   (500)
#define MAXNUMLEN   (1001)

int longestArithSeqLength(int* nums, int numsSize){
    int ans = 0, dp[numsSize][MAXNUMLEN], i, j, k;
    memset(dp, 0, sizeof(dp));
    
    for (i = 0; i < numsSize; i++){
        for (j = 0; j < i; j++){
            k = nums[i] - nums[j] + MAXNUMVAL;
            dp[i][k] = MAXVAL(2, dp[j][k] + 1);
            ans = MAXVAL(ans, dp[i][k]);
        }
    }
    
    return ans;
}