/*
 * Link: https://leetcode.com/problems/132-pattern/
 * Problem: 456. 132 Pattern
 * */

#define MINVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

typedef struct {
    int num, currMin;
}stack;

bool find132pattern(int* nums, int numsSize){
    stack s[numsSize];
    int sIdx = -1;
    memset(s, 0, sizeof(s));
    int i, currMin;

    currMin = nums[0];

    for (i = 1; i < numsSize; i++){
        while (sIdx >= 0 && nums[i] >= s[sIdx].num){
            sIdx--;
        }

        if (sIdx >= 0 && nums[i] > s[sIdx].currMin){
            return true;
        }

        s[sIdx + 1].num = nums[i];
        s[sIdx + 1].currMin = currMin;
        sIdx++;

        currMin = MINVAL(nums[i], currMin);
    }

    return false;
}
