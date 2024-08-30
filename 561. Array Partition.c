/*
Problem: 561. Array Partition
Link: https://leetcode.com/problems/array-partition/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int arrayPairSum(int* nums, int numsSize){
    int i, ans = 0;
    
    qsort(nums, numsSize, sizeof(int), incrCmp);
    
    for (i = 0; i < numsSize; i += 2) {
        ans += nums[i];
    }
    
    return ans;
}
