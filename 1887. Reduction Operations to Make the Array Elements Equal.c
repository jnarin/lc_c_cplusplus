/*
 * Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
 * Problem: 1887. Reduction Operations to Make the Array Elements Equal
 * */

static int incr_cmp(void *a, void *b){
    return *(int *)a - *(int *)b;
}

int reductionOperations(int* nums, int numsSize){
    int ans = 0, i;

    qsort(nums, numsSize, sizeof(int), incr_cmp);

    for (i = numsSize - 1; i > 0; i--){
        ans = nums[i] != nums[i - 1] ? ans + numsSize - i : ans;
    }

    return ans;
}
