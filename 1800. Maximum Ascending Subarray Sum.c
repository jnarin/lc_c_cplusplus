/*
Problem: 1800. Maximum Ascending Subarray Sum
Link: https://leetcode.com/problems/maximum-ascending-subarray-sum/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxAscendingSum(int* nums, int numsSize) {
    int i, ans = 0, sum = nums[0];

    for (i = 1; i < numsSize; i++) {
        if (nums[i - 1] < nums[i]) {
            sum += nums[i];
        } else {
            ans = MAXVAL(ans, sum);
            sum = nums[i];
        }
    }
    
    return MAXVAL(ans, sum);
}
