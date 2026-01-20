/*
Problem: 3314. Construct the Minimum Bitwise Array I
Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int *ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    for(int i = 0; i < numsSize; i++) {
        if (nums[i] == 2) {
            ans[i] = -1;
            continue;
        }
        
        int t = 1;

        while ((nums[i] & t) > 0) {
            t = t << 1;
        }

        ans[i] = nums[i] - (t >> 1);
        
    }

    return ans;
}
