/*
 * Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
 * Problem: 1913. Maximum Product Difference Between Two Pairs
 * */

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int maxProductDifference(int* nums, int numsSize){
    int ans = 0;

    qsort(nums, numsSize, sizeof(int), incrCmp);

    int a = nums[numsSize -1], b = nums[numsSize - 2],
        c = nums[0], d = nums[1];

    return (a * b) - (c * d);
}
