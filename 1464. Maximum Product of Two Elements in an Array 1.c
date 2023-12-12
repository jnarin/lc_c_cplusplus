/*
Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Problem: 1464. Maximum Product of Two Elements in an Array


Sort the array in decreasing order, and take the first
two elements
Time & Space Complexity: O(n log(n))
*/

static int decrCmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int maxProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), decrCmp);
    
    return (nums[0] - 1) * (nums[1] - 1);
}