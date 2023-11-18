/*
 * Link: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
 * Problem: 1838. Frequency of the Most Frequent Element
 * */

#define MAXVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    (_a > _b) ? _a : _b;    })

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int maxFrequency(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), incrCmp);

    int ans = 1, l, r;
    long window = 0;

    l = 0;
    r = 1;

    while (r < numsSize){
        window += (long)(nums[r] - nums[r - 1]) * (long)(r - l);

        while (window > k){
            window -= (nums[r] - nums[l++]);
        }

        ans = MAXVAL(ans, r - l + 1);
        r++;
    }

    return ans;
}
