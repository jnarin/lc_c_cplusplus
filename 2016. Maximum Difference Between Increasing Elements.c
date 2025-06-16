/*
Problem: 2016. Maximum Difference Between Increasing Elements
Link: https://leetcode.com/problems/maximum-difference-between-increasing-elements/
*/

#define MAX_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;})

#define MIN_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b; })

int maximumDifference(int* nums, int numsSize){
    int ans = -1, min = nums[0], i;
    
    for (i = 1; i < numsSize; i++){
        if (nums[i] > min){
            ans = MAX_VAL(ans, nums[i] - min);
        }
        
        min = MIN_VAL(min, nums[i]);
    }
    
    return ans;
}
