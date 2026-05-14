/*
Problem: 2784. Check if Array is Good
Link: https://leetcode.com/problems/check-if-array-is-good/
*/
#define MAXNUMS (201)

bool isGood(int* nums, int numsSize) {
    int freq[MAXNUMS] = {0};
    int maxNum = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num > maxNum) {
            maxNum = num;
        }
        freq[num]++;
    }

    if (maxNum != numsSize - 1) {
        return false;
    }

    for (int i = 1; i < maxNum; i++) {
        if (freq[i] != 1) {
            return false;
        }
    }

    if (freq[maxNum] != 2) {
        return false;
    }

    return true;
}
