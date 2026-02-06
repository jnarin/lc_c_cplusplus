/*
Problem: 3634. Minimum Removals to Balance Array
Link: https://leetcode.com/problems/minimum-removals-to-balance-array/
*/

#define MAXVAL(a,b) (((a) > (b)) ? (a) : (b))

static int upperBound(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize; 
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

static int incrCmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), incrCmp);
    int count = 0, i, j;

    for (i = 0; i < numsSize; i++) {
        j = numsSize;
        if (1LL * nums[i] * k <= nums[numsSize - 1]){
            j = upperBound(nums, numsSize, 1LL * nums[i] * k);
        }

        count = MAXVAL(count, j - i);
    }

    return numsSize - count;
}
