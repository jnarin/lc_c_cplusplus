/*
Problem: 3644. Maximum K to Sort a Permutation
Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/
*/

int sortPermutation(int* nums, int numsSize) {
    int ans = -1, i;

    for (i = 0; i < numsSize; i++) {
        ans &= (i != nums[i]) ? nums[i] : ans;
    }
    
    return ans > 0 ? ans : 0;
}
