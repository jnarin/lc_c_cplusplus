/*
Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Problem: 34. Find First and Last Position of Element in Sorted Array
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ans = calloc(2, sizeof(int));
    *returnSize = 2;
    
    ans[0] = ans[1] = -1;
    
    int l, r, m, t;
    
    l = 0;
    r = numsSize - 1;
    
    while (l <= r){
        m = (l & r) + ((l ^ r) >> 1);
        
        if (nums[m] == target){
            t = m;
            while (t >= 0 && t < numsSize && nums[t] == target){
                t--;
            }
            ans[0] = t + 1;
            
            t = m;
            while (t >= 0 && t < numsSize && nums[t] == target){
                t++;
            }
            ans[1] = t - 1;
            
            break;
        }
        
        if (nums[m] > target){
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    return ans;
}