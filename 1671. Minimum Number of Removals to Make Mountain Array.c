/*
Problem: 1671. Minimum Number of Removals to Make Mountain Array
Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int minimumMountainRemovals(int* nums, int numsSize) {
    int left[numsSize], right[numsSize], i, j;
    int ans = 0;
    
    for (i = 0; i < numsSize; i++) {
        left[i] = right[i] = 1;
    }
    
    for (i = 1; i < numsSize; i++) {
        for (j = 0; j < i; j++) {
            left[i] = nums[i] > nums[j] ? MAXVAL(left[i], left[j] + 1) : left[i];
        }
    }
    
    for (i = numsSize - 2; i >= 0; i--) {
        for (j = i + 1; j < numsSize; j++) {
            right[i] = nums[i] > nums[j] ? MAXVAL(right[i], right[j] + 1) : right[i];
        }
    }
    
    for (i = 0; i < numsSize; i++) {
        ans = left[i] > 1 && right[i] > 1 ? MAXVAL(ans, left[i] + right[i] - 1) : ans;
    }
    
    return numsSize - ans;
}
