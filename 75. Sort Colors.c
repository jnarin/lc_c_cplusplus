/*
 * Link: https://leetcode.com/problems/sort-colors/
 * Problem: 75. Sort Colors
 * */

#define MAX_COLORS  (3)

void sortColors(int* nums, int numsSize) {
    int colorCount[MAX_COLORS] = {0}, i, idx = 0;

    for (i = 0; i < numsSize; i++) {
        colorCount[nums[i]]++;
    }

    for (i = 0; i < MAX_COLORS; i++) {
        while (colorCount[i]--) {
            nums[idx++] = i;
        }
    }

    return;
}

