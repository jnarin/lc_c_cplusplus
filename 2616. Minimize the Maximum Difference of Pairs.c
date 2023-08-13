/*
 * Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
 * Problem: 2616. Minimize the Maximum Difference of Pairs
 * */
#define MIDVAL(a, b)    (((a) & (b)) + (((a) ^ (b)) >> 1))

static int incr_cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

static int numPairs(int *nums, int numsSize, int diff){
    int p = 0, i = 1;

    while (i < numsSize){
        if (nums[i] - nums[i - 1] <= diff){
            p++;
            i++;
        }

        i++;
    }

    return p;
}

int minimizeMax(int* nums, int numsSize, int p){
    qsort(nums, numsSize, sizeof(int), incr_cmp);

    int l = 0, r = nums[numsSize - 1] - nums[0], m;

    while (l < r){
        m = MIDVAL(l, r);
        if (numPairs(nums, numsSize, m) >= p){
            r = m;
        } else {
            l = m + 1;
        }
    }

    return l;
}
