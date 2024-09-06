/*
Problem: 2859. Sum of Values at Indices With K Set Bits
Link: https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/
*/

static int countBits(int n) {
    int c;
    
    for (c = 0; n; c++) {
        n &= n - 1;
    }
    
    return c;
}

int sumIndicesWithKSetBits(int* nums, int numsSize, int k){
    int ans = 0, i;
    
    for (i = 0; i < numsSize; i++) {
        ans += countBits(i) == k ? nums[i] : 0;
    }

    return ans;
}
