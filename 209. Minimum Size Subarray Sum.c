/*
Link: https://leetcode.com/problems/minimum-size-subarray-sum/
Problem: 209. Minimum Size Subarray Sum
*/

#define MINVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

int minSubArrayLen(int target, int* nums, int numsSize){
    int ans = INT_MAX, sum, l, r;
    
    sum = l = r = 0;
    
    while (r < numsSize){
        sum += nums[r];
        while (sum >= target){
            ans = MINVAL(ans, r - l + 1);
            sum -= nums[l++];
        }
        
        r++;
    }
    
    return ans == INT_MAX ? 0 : ans;
}