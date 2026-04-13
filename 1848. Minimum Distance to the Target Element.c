/*
Problem: 1848. Minimum Distance to the Target Element
Link: https://leetcode.com/problems/minimum-distance-to-the-target-element/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int getMinDistance(int* nums, int numsSize, int target, int start) {
    int i, ans = numsSize;

    for (i = start; i < numsSize; i++) {
        if (nums[i] == target) {
            ans = MINVAL(ans, i - start);
        }
    }

    for (i = start; i >= 0; i--) {
        if (nums[i] == target) {
            ans = MINVAL(ans, start - i);;
        }
    }

    return ans;
}
