/*
Problem: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
Link: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minDifference(int* nums, int numsSize) {
    if (numsSize < 4) {
        return 0;
    }
    
    qsort(nums, numsSize, sizeof(int), incrCmp);
    
    int left, right, ans = INT_MAX;
    
    for (left = 0, right = numsSize - 4; left < 4; left++, right++) {
        ans = MINVAL(ans, nums[right] - nums[left]);
    }
    
    return ans;    
}