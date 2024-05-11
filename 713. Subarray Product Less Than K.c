/*
 * Problem: 713. Subarray Product Less Than K
 * Link: https://leetcode.com/problems/subarray-product-less-than-k/
 * */

int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    int ans = 0, l, r, p = 1;

    if (k <= 1) {
        return ans;
    }

    for (l = 0, r = 0; r < numsSize && l < numsSize; r++) {
        p *= nums[r];

        while (l < numsSize && p >= k) {
            p /= nums[l];
            l++;
        }

        ans += r - l + 1;
    }

    return ans;
}
