/*
Problem: 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {
    int len = strlen(seq), *ans = calloc(len, sizeof(int)), i, depth = -1, idx = 0;
    *returnSize = len;
    
    for (i = 0; i < len; i++) {
        ans[idx++] = seq[i] == '(' ? ++depth % 2 : depth-- % 2;
    }
    
    return ans;
}
