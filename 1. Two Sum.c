/*
Link: https://leetcode.com/problems/two-sum/
Problem: 1. Two Sum
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    int val, idx;
    UT_hash_handle hh;
}hash_entry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    hash_entry *map = NULL, *e, *t;
    int *ans = NULL;
    int i;
    
    for (i = 0; i < numsSize; i++){
        int x = target - nums[i];
        
        HASH_FIND_INT(map, &x, e);
        if (e){
            ans = calloc(2, sizeof(int));
            *returnSize = 2;
            
            ans[0] = i;
            ans[1] = e->idx;
            
            break;
        }
        
        e = calloc(1, sizeof(hash_entry));
        e->val = nums[i];
        e->idx = i;

        HASH_ADD_INT(map, val, e);
    }
    
    HASH_ITER(hh, map, e, t) {
        free(e);
    }
    
    return ans;

}
