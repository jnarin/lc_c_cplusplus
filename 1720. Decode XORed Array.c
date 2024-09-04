/*
Problem: 1720. Decode XORed Array
Link: https://leetcode.com/problems/decode-xored-array/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    int *ans = calloc(encodedSize + 1, sizeof(int)), i, idx;
    *returnSize = encodedSize + 1;
    
    ans[0] = first;
    for (idx = 0, i = 1; idx < encodedSize; idx++, i++) {
        ans[i] = ans[i - 1] ^ encoded[idx];
    }

    return ans;
}
