/*
Problem: 3097. Shortest Subarray With OR at Least K II
Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii
*/

int minimumSubarrayLength(int* nums, int numsSize, int k) {
    int count[32] = {0}, i, ans = numsSize + 1, j, h, s;

    for (i = 0, j = 0, s = 0; j < numsSize; j++) {
        s |= nums[j];
        for (h = 0; h < 32; h++) {
            if (nums[j] >> h & 1) {
                count[h]++;
            }
        }

        for (; s >= k && i <= j; i++) {
            ans = ans < j - i + 1 ? ans : j - i + 1;
            for (h = 0; h < 32; h++) {
                if (nums[i] >> h & 1) {
                    count[h]--;
                    if (count[h] == 0) {
                        s ^= (1 << h);
                    }
                }
            }
        }
    }

    return ans > numsSize ? -1 : ans;
}
