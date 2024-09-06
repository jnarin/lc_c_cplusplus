/*
Problem: 3191. Minimum Operations to Make Binary Array Elements Equal to One I
Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
*/

int minOperations(int* nums, int numsSize) {
    int i, ans = 0;
    
    for (i = 0; i < numsSize - 2; i++) {
        if (nums[i] == 0) {
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            ans++;
        }
    }
    
    return nums[numsSize - 1] == 0 || nums[numsSize - 2] == 0 ? -1 : ans;
}
