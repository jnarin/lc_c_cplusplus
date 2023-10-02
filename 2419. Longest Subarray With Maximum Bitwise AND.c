/*
 * Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
 * Problem: 2419. Longest Subarray With Maximum Bitwise AND
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int longestSubarray(int* nums, int numsSize){
    int ans = 0, maxIdx = 0, t = 0, i;

    for (i = 0; i < numsSize; i++){
        if (nums[i] == nums[maxIdx]){
            t++;
            ans = MAXVAL(ans, t);
            continue;
        } else if (nums[i] > nums[maxIdx]){
            maxIdx = i;
            t = ans = 1;
            continue;
        } else {
            t = 0;
        }
    }

    return ans;
}
