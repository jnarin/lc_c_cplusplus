/*
Problem: 3068. Find the Maximum Sum of Node Values
Link: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static long long maxSumOfNodes(int i, int isEven, int *nums, int numsSize, int k, long long **dp) {
    if (i >= numsSize) {
        return isEven == 1 ? 0 : INT_MIN;
    }
    
    if (dp[i][isEven] != -1) {
        return dp[i][isEven];
    }
    
    long long noXorDone = nums[i] + maxSumOfNodes(i + 1, isEven, nums, numsSize, k, dp);
    long long xorDone = (nums[i] ^ k) + maxSumOfNodes(i + 1, isEven ^ 1, nums, numsSize, k, dp);
    
    dp[i][isEven] = MAXVAL(xorDone, noXorDone);
    
    return dp[i][isEven];
}

long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
    long long **dp;
    int i, j;
    
    dp = malloc(numsSize * sizeof(long long *));
    for (i = 0; i < numsSize; i++) {
        dp[i] = malloc(2 * sizeof(long long));
        for (j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    
    long long ans = maxSumOfNodes(0, 1, nums, numsSize, k, dp);
    
    for (i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return ans;
}