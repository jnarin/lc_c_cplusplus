/*
 * Link: https://leetcode.com/problems/combination-sum-iv/
 * Problem: 377. Combination Sum IV
 * */

static int cs4Helper(int *nums, int numsSize, int target, int *dp){
    int r = 0, i;
    
    if (dp[target] > -1) return dp[target];
    
    for (i = 0; i < numsSize; i++){
        if (nums[i] <= target){
            r += cs4Helper(nums, numsSize, target - nums[i], dp);
        }
    }
    
    dp[target] = r;
    
    return dp[target];
    
}

int combinationSum4(int* nums, int numsSize, int target){
    int dp[target + 1];
    int i;
    int r = 0;
    
    for (i = 0; i < target + 1; i++){
        dp[i] = -1;
    }
    
    dp[0] = 1;
    
    cs4Helper(nums, numsSize, target, dp);
    
    return dp[target];

}
