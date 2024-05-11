/*
 * Problem: 992. Subarrays with K Different Integers
 * Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
 * */

static int subarraysWithAtMostKDistinct(int *nums, int numsSize, int k) {
    int ans = 0;
    int count[numsSize + 1];
    int l, r;

    memset(count, 0, sizeof(count));

    for (l = 0, r = 0; r < numsSize; r++) {
        count[nums[r]]++;
        if (count[nums[r]] == 1) {
            k--;
        }

        while (k == -1) {
            count[nums[l]]--;
            if (count[nums[l++]] == 0) {
                k++;
            }
        }

        ans += r - l + 1;
    }


    return ans;
}

int subarraysWithKDistinct(int* nums, int numsSize, int k) {
    return subarraysWithAtMostKDistinct(nums, numsSize, k) -
           subarraysWithAtMostKDistinct(nums, numsSize, k - 1);
}
