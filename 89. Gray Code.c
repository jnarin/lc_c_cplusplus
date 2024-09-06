/*
Problem: 89. Gray Code
Link: https://leetcode.com/problems/gray-code/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int size = 1 << n, i, idx = 0, j;
    int *ans = calloc(size, sizeof(int));
    *returnSize = size;
    
    ans[idx++] = 0;
    
    for (i = 0; i < n; i++) {
        for (j = idx - 1; j >= 0; j--) {
            ans[idx++] = ans[j] | (1 << i);
        }
    }
    
    return ans;
}
