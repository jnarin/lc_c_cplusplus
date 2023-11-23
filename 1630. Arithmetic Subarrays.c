/*
Link: https://leetcode.com/problems/arithmetic-subarrays/
Problem: 1630. Arithmetic Subarrays
*/

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {
    bool *ans = malloc(lSize * sizeof(bool));
    int i, j, diff;
    
    *returnSize = lSize;
    memset(ans, true, lSize * sizeof(bool));
    
    for (i = 0; i < lSize; i++){
        int subArrayLen = r[i] - l[i] + 1;
        int subArray[subArrayLen];
        
        memcpy(subArray, &nums[l[i]], sizeof(int) * subArrayLen);
        qsort(subArray, subArrayLen, sizeof(int), incrCmp);
        
        diff = subArray[1] - subArray[0];
        for (j = 2; j < subArrayLen && ans[i] == true; j++){
            ans[i] = ans[i] && (subArray[j] - subArray[j - 1] == diff);
        }
    }
    
    return ans;
}