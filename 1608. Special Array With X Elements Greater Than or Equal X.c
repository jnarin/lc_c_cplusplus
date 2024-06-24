/*
Problem: 1608. Special Array With X Elements Greater Than or Equal X
Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
*/

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int specialArray(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), incrCmp);
    
    if (nums[0] >= numsSize) {
        return numsSize;
    }
    
    int i, ans;
    
    for (i = 1; i < numsSize; i++) {
        ans = numsSize - i;
        
        if (nums[i - 1] < ans && nums[i] >= ans) {
            return ans;
        }
    }
    
    return -1;
}