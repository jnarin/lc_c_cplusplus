/*
Problem: 3718. Smallest Missing Multiple of K
Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/
*/

int missingMultiple(int* nums, int numsSize, int k) {
    int count[101] = {0}, i;

    for (i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    for (i = 1; i * k < 101; i++) {
        if (count[i * k] == 0) {
            return i * k;
        }
    }
    
    return i * k;
}
