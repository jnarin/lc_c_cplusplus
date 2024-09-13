/*
Problem: 1310. XOR Queries of a Subarray
Link: https://leetcode.com/problems/xor-queries-of-a-subarray/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *ans = calloc(queriesSize, sizeof(int)), i, xorArr[arrSize + 1], ansIdx = 0;
    
    xorArr[0] = 0;
    for (i = 0; i < arrSize; i++) {
        xorArr[i + 1] = xorArr[i] ^ arr[i];
    }
    
    for (i = 0; i < queriesSize; i++) {
        ans[ansIdx++] = xorArr[queries[i][0]] ^ xorArr[queries[i][1] + 1];
    }
    
    *returnSize = queriesSize;
    return ans;
    
}
