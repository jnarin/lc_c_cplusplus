/*
Problem: 3392. Count Subarrays of Length Three With a Condition
Link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/
*/

int countSubarrays(int* nums, int numsSize) {
    int i, ans = 0;

    for (i = 0; i + 2 < numsSize; i++) {
        ans += (((nums[i] + nums[i + 2]) * 2) == nums[i + 1]);
    }
    
    return ans;
}
