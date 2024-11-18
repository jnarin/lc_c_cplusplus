/*
 * Problem: 1652. Defuse the Bomb
 * Link: https://leetcode.com/problems/defuse-the-bomb/
 * */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int i, *ans = calloc(codeSize, sizeof(int)), j;
    
    *returnSize = codeSize;
    
    if (k == 0) {
        return ans;
    }
    
    for (i = 0; i < codeSize; i++) {
        if (k > 0) {
            for (j = i + 1; j < i + k + 1; j++) {
                ans[i] += code[j % codeSize];
                
            }
        } else {
            for (j = i + k; j < i; j++) {
                ans[i] += code[(j + codeSize) % codeSize];
            }
        }
    }
    
    
    return ans;
}
