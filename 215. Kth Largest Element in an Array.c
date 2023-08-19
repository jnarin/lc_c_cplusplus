/*
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Problem: 215. Kth Largest Element in an Array
 * */

/* Even with sorting the entire array, performance on LC is as good as C++ solution with priority queue :) */

static int decr_cmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), decr_cmp);

    return nums[k - 1];
}
