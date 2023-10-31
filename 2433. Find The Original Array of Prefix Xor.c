/*
Link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
Problem: 2433. Find The Original Array of Prefix Xor
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize){
    int *ans = calloc(prefSize, sizeof(int)), i;
    *returnSize = prefSize;

    ans[0] = pref[0];
    
    for (i = 1; i < prefSize; i++){
        ans[i] = pref[i] ^ pref[i - 1];
    }
    
    return ans;
}