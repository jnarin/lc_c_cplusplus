/*
Link: https://leetcode.com/problems/counting-bits/
Problem: 338. Counting Bits
Approach: Faster method - O(n)
If n is odd, the number of bits set is number of bits set in (n/2) + 1
If n is even, the number of bits set is the same as (n/2)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* countBits(int n, int* returnSize){
    int *ans = calloc(n + 1, sizeof(int)), i;
    *returnSize = n + 1;
    
    ans[0] = 0;
    
    for (i = 1; i <= n; i++){
        ans[i] = ans[i >> 1] + (i & 1);
    }
    
    return ans;
}