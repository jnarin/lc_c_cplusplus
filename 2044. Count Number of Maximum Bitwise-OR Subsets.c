/*
Problem: 2044. Count Number of Maximum Bitwise-OR Subsets
Link: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
*/

static int getOrSum(int *nums, int numsSize) {
    int ans = 0, i;
    
    for (i = 0; i < numsSize; i++) {
        ans |= nums[i];
    }
    
    return ans;
}

static void dfs(int *nums, int numsSize, int i, int path, int orSum, int *ans) {
    if (i == numsSize) {
        if (path == orSum) {
            *ans += 1;
        }
        
        return;
    }
    
    dfs(nums, numsSize, i + 1, path, orSum, ans);
    dfs(nums, numsSize, i + 1, path | nums[i], orSum, ans);
}

int countMaxOrSubsets(int* nums, int numsSize) {
    int orSum = getOrSum(nums, numsSize), ans = 0;
    
    dfs(nums, numsSize, 0, 0, orSum, &ans);
    
    return ans;    
}
