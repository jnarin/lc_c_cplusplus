/*
Problem: 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
Link: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static long long arraySum(int* nums, int numsSize) {
    long long sum = 0, i;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return sum;
}

static int countVal(int* nums, int numsSize, int val) {
    int count = 0, i;

    for (i = 0; i < numsSize; i++) {
        count += nums[i] == val;
    }

    return count;
}

long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long sum1 = arraySum(nums1, nums1Size), sum2 = arraySum(nums2, nums2Size);
    int zeroCount1 = countVal(nums1, nums1Size, 0), zeroCount2 = countVal(nums2, nums2Size, 0);

    if ((zeroCount1 == 0 && sum1 < sum2 + zeroCount2) 
        || (zeroCount2 == 0 && sum2 < sum1 + zeroCount1)) {
        return -1;
    }

    return MAXVAL(sum1 + zeroCount1, sum2 + zeroCount2);
}
