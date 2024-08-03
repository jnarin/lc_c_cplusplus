/*
Problem: 3069. Distribute Elements Into Two Arrays I
Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    int arr1[numsSize], arr2[numsSize], i;
    int idx1 = 0, idx2 = 0;
    
    arr1[idx1++] = nums[0];
    arr2[idx2++] = nums[1];
    
    for (i = 2; i < numsSize; i++) {
        if (arr1[idx1 - 1] > arr2[idx2 - 1]){
            arr1[idx1++] = nums[i];
        } else {
            arr2[idx2++] = nums[i];
        }
    }
    
    int *ans = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;
    
    memcpy(&ans[0], arr1, sizeof(int) * idx1);
    memcpy(&ans[idx1], arr2, sizeof(int) * idx2);
    
    return ans;
}
