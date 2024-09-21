/*
Problem: 386. Lexicographical Numbers
Link: https://leetcode.com/problems/lexicographical-numbers/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize) {
    int *ans = calloc(n, sizeof(int)), idx = 0, c = 1;
    *returnSize = n;
    
    while (idx < n) {
        ans[idx++] = c;
        
        if (c * 10 <= n) {
            c *= 10;
        } else {
            while (c % 10 == 9 || c == n) {
                c /= 10;
            }
            
            c++;
        }
    }
    
    return ans;
}
