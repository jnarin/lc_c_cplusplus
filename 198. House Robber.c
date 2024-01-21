/*
 * Link: https://leetcode.com/problems/house-robber/
 * Problem: 198. House Robber
 * */

#define MAX_VAL(a, b) ({\
    __typeof__(a) _a = (a); \
    __typeof__(b) _b = (b); \
    a > b ? a : b;  })

int rob(int* nums, int numsSize){
    int ans, x, y, i;

    ans = x = y = 0;
    for (i = 0; i < numsSize; i++){
        ans = MAX_VAL(nums[i] + x, y);
        x = y;
        y = ans;
    }

    return ans;

}
