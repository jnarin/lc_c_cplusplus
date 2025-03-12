/*
Problem: 2529. Maximum Count of Positive Integer and Negative Integer
Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*/

#define MAXVAL(a, b) ((a) > (b) ? (a) : (b))

int maximumCount(int* nums, int numsSize) {
    int max = 0, pos = 0, neg = 0, i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            pos++;
        } else if (nums[i] < 0) {
            neg++;
        }
    }

    return MAXVAL(pos, neg);;
}
