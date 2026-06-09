/*
Problem: 3689. Maximum Total Subarray Value I
Link: https://leetcode.com/problems/maximum-total-subarray-value-i/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

typedef struct MAXMINPAIR {
    int max;
    int min;
} maxminPair;

void getMaxMin(int *nums, int numsSize, maxminPair *m) {
    m->max = INT_MIN;
    m->min = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        m->max = MAXVAL(m->max, nums[i]);
        m->min = MINVAL(m->min, nums[i]);
    }

    return;
}

long long maxTotalValue(int* nums, int numsSize, int k) {
    maxminPair m;
    getMaxMin(nums, numsSize, &m);

    return (long long)k * (m.max - m.min);
}
