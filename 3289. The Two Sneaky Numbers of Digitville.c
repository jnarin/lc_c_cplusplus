/*
Problem: 3289. The Two Sneaky Numbers of Digitville
Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int map[numsSize];
    memset(map, 0, sizeof(map));
    
    int *ans = calloc(2, sizeof(int)), idx = 0;
    *returnSize = 2;
    
    int i;
    
    for (i = 0; i < numsSize; i++) {
        map[nums[i]]++;
        if (map[nums[i]] == 2) {
            ans[idx++] = nums[i];
            if (idx == 2) {
                break;
            }
        }
    }
    
    return ans;
}
