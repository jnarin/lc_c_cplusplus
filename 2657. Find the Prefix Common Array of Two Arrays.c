/*
Problem: 2657. Find the Prefix Common Array of Two Arrays
Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *ans = calloc(ASize, sizeof(int)), i, p = 0, map[ASize + 1];

    memset(map, 0, sizeof(map));

    for (i = 0; i < ASize; i++) {
        map[A[i]]++;
        p += map[A[i]] == 2;

        map[B[i]]++;
        p += map[B[i]] == 2;

        ans[i] = p;
    }

    *returnSize = ASize;
    return ans;    
}
