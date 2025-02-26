/*
Problem: 1749. Maximum Absolute Sum of Any Subarray
Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
*/
#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int maxAbsoluteSum(int* nums, int numsSize) {
    int ans, maxSum = 0, minSum = 0, i;

    for (i = 0; i < numsSize; i++) {
        maxSum = MAXVAL(nums[i], maxSum + nums[i]);
        minSum = MINVAL(nums[i], minSum + nums[i]);

        ans = MAXVAL(ans, MAXVAL(maxSum, abs(minSum)));
    }
    
    return ans;
}
