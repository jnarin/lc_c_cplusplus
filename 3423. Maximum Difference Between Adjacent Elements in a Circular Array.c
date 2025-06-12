/*
Problem: 3423. Maximum Difference Between Adjacent Elements in a Circular Array
Link: https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxAdjacentDistance(int* nums, int numsSize) {
    int i, ans = abs(nums[0] - nums[numsSize - 1]);

    for (i = 1; i < numsSize; i++) {
        ans = MAXVAL(ans, abs(nums[i] - nums[i - 1]));
    }

    return ans;   
}
