/*
Problem: 961. N-Repeated Element in Size 2N Array
Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
*/
int repeatedNTimes(int* nums, int numsSize) {
    int i;

    for (i = 0; i < numsSize >> 1; i++) {
        if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
            return nums[i];
        }
    }
    
    return nums[numsSize - 1];
}
