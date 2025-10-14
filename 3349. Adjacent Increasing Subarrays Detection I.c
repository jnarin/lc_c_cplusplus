/*
Problem: 3349. Adjacent Increasing Subarrays Detection I
Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/
*/

#define MINVAL(a, b) ((a) < (b) ? (a) : (b))

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int incr = 1, prevIncr = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            incr++;
        } else {
            prevIncr = incr;
            incr = 1;
        }

        if ((incr >> 1) >= k || MINVAL(prevIncr, incr) >= k) {
            return true;
        }
    }

    return false;
}
