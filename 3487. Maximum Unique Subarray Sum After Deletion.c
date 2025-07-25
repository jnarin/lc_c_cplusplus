/*
Problem: 3487. Maximum Unique Subarray Sum After Deletion
Link: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
*/

#define MAX_NUMS        (202)
#define MAXVAL(a, b)    (((a) > (b)) ? (a) : (b))

static int geMax(const int *nums, const int numsSize) {
    int max = nums[0], i;

    for (i = 1; i < numsSize; i++) {
        max = MAXVAL(max, nums[i]);
    }

    return max;
}

int maxSum(int* nums, int numsSize) {
    int max = geMax(nums, numsSize);
    if (max <= 0) {
        return max;
    }

    int freq[MAX_NUMS] = {0}, ans = 0, i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] < 0 || freq[nums[i] + 100] > 0) {
            continue;
        }

        ans += nums[i];
        freq[nums[i] + 100]++;
    }

    return ans;
}
