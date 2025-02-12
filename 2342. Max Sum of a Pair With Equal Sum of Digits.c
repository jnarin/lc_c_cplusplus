/*
Problem: 2342. Max Sum of a Pair With Equal Sum of Digits
Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
*/
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static int getDigitSum(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

int maximumSum(int* nums, int numsSize) {
    int sumMap[100] = {0}, i, ans = -1, sum;

    for (i = 0; i < numsSize; i++) {
        sum = getDigitSum(nums[i]);
        if (sumMap[sum]) {
            ans = MAXVAL(ans, sumMap[sum] + nums[i]);
        }

        sumMap[sum] = MAXVAL(sumMap[sum], nums[i]);
    }

    return ans;
}
