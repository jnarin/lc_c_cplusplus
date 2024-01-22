/*
Link: https://leetcode.com/problems/set-mismatch/submissions/
Problem: 645. Set Mismatch
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_LEN    (10001)
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *ans = calloc(2, sizeof(int));
    *returnSize = 2;

    int map[MAX_LEN] = {0};
    int i;

    for (i = 0; i < numsSize; i++){
        if (map[nums[i]] > 0){
            ans[0] = nums[i];
        }
        map[nums[i]]++;
    }

    for (i = 1; i <= numsSize; i++){
        if (map[i] == 0){
            ans[1] = i;
            break;
        }
    }
    
    return ans;
}