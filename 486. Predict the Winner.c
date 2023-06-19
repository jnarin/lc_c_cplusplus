/*
 * Link: https://leetcode.com/problems/predict-the-winner/
 * Problem: 486. Predict the Winner
 * */

#define MAXVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

bool PredictTheWinner(int* nums, int numsSize){
    int dp[numsSize];
    int i, j, k;

    memcpy(dp, nums, sizeof(dp));

    for (k = 1; k < numsSize; k++){
        for (j = numsSize - 1; j - k >= 0; j--){
            i = j - k;
            dp[j] = MAXVAL(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }

    return dp[numsSize - 1] >= 0;
}

