/*
Problem: 3867. Sum of GCD of Formed Pairs
Link: https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int incrCmp(const void *a, const void *b) {
    return *(int*)a - *(int *)b;
}

static int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


long long gcdSum(int* nums, int numsSize) {
    int prefixGcd[numsSize], max, i, t;
    long long ans = 0;

    for (i = 0; i < numsSize; i++) {
        max = MAXVAL(max, nums[i]);
        prefixGcd[i] = gcd(nums[i], max);
    }

    qsort(prefixGcd, numsSize, sizeof(int), incrCmp);

    for (i = 0; i < numsSize >> 1; i++) {
        ans += gcd(prefixGcd[i], prefixGcd[numsSize - i - 1]);
    }

    return ans;    
}
