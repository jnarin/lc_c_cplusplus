/*
 * Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
 * Problem: 1877. Minimize Maximum Pair Sum in Array
 * */

#define MAXVAL(a, b)\
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    (_a > _b) ? _a : _b;    })

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int minPairSum(int* nums, int numsSize){
    int l = 0, r = numsSize - 1, ans = 0;

    qsort(nums, numsSize, sizeof(int), incrCmp);

    while (l < r){
        ans = MAXVAL(ans, (nums[l] + nums[r]));
        l++;
        r--;
    }

    return ans;
}

