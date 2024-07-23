/*
Problem: 1636. Sort Array by Increasing Frequency
Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct freqMap {
    int val;
    int freq;
};

static int decrCmp(const void* a, const void* b) {
    struct freqMap *fa = (struct freqMap*)a;
    struct freqMap *fb = (struct freqMap*)b;

    if (fa->freq == fb->freq) {
        return fb->val - fa->val;
    }

    return fa->freq - fb->freq;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    struct freqMap fm[numsSize];
    int map[201] = {0}, i;
    int *ans = calloc(numsSize, sizeof(int));

    *returnSize = numsSize;

    for (i = 0; i < numsSize; i++) {
        map[nums[i] + 100]++;
    }

    for (i = 0; i < numsSize; i++) {
        fm[i].val = nums[i];
        fm[i].freq = map[nums[i] + 100];
    }
    
    qsort(fm, numsSize, sizeof(struct freqMap), decrCmp);   

    for (i = 0; i < numsSize; i++) {
        ans[i] = fm[i].val;
    }

    return ans;
}
