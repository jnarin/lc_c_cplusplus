/*
Link: https://leetcode.com/problems/longest-increasing-subsequence/
Problem: 300. Longest Increasing Subsequence
*/

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

static int maxElement(int *array, int arraySize) {
    int max = INT_MIN, i;
    
    for (i = 0; i < arraySize; i++) {
        max = MAXVAL(max, array[i]);
    }
    
    return max;
}

int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize + 1], i, j;
    
    for (i = 0; i < numsSize + 1; i++) {
        dp[i] = 1;
    }
    
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < (dp[j] + 1)) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    return maxElement(dp, numsSize + 1);
}