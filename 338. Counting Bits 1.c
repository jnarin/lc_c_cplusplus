/*
Link: https://leetcode.com/problems/counting-bits/
Problem: 338. Counting Bits
Approach: Simple method - O(n log n)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int countBitsHelper(int n){
    int c;
    
    for (c = 0; n; c++){
        n &= (n - 1) ;
    }
    
    return c;
}

int* countBits(int n, int* returnSize){
    int *ans = calloc(n + 1, sizeof(int)), i;
    *returnSize = n + 1;
    
    for (i = 0; i <= n; i++){
        ans[i] = countBitsHelper(i);
    }
    
    return ans;
}