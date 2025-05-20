/*
Problem: 3355. Zero Array Transformation I
Link: https://leetcode.com/problems/zero-array-transformation-i/
*/

bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int prefix[numsSize + 1], i, l, r, d = 0;

    memset(prefix, 0, sizeof(prefix));
    for (i = 0; i < queriesSize; i++) {
        l = queries[i][0];
        r = queries[i][1];
        prefix[l]++;
        prefix[r + 1]--;
    }

    for (i = 0; i < numsSize; i++) {
        d += prefix[i];

        if (d < nums[i]) {
            return false;
        }
        
    }

    return true;
}
