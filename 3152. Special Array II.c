/*
Problem: 3152. Special Array II
Link: https://leetcode.com/problems/special-array-ii/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    bool *ans = calloc(queriesSize, sizeof(bool));
    int id = 0, i, pairity[numsSize];

    memset(pairity, 0, sizeof(pairity));
    *returnSize = queriesSize;

    for (i = 1; i < numsSize; i++) {
        if ((nums[i] & 1) == (nums[i - 1] & 1)) {
            id++;
        }

        pairity[i] = id;
    }

    for (i = 0; i < queriesSize; i++) {
        ans[i] = pairity[queries[i][1]] == pairity[queries[i][0]];
    }
    
    return ans;
}
