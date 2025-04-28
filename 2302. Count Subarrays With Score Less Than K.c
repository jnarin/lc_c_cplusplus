/*
Problem: 2302. Count Subarrays With Score Less Than K
Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
*/


long long countSubarrays(int* nums, int numsSize, long long k) {
    long long ans = 0, sum = 0;
    int left = 0, right;

    for (right = 0; right < numsSize; right++) {
        sum += nums[right];

        while (sum * (right - left + 1) >= k) {
            sum -= nums[left++];
        }

        ans += right - left + 1;
    }

    return ans;
}
