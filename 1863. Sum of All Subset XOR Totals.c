/*
Problem: 1863. Sum of All Subset XOR Totals
Link: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
*/

static int dfs(int *nums, int numsSize, int i, int xors) {
    if (i == numsSize) {
        return xors;
    }
    
    int a = dfs(nums, numsSize, i + 1, xors),
        b = dfs(nums, numsSize, i + 1, nums[i] ^ xors);
    
    return a + b;
}

int subsetXORSum(int* nums, int numsSize) {
    return dfs(nums, numsSize, 0, 0);    
}