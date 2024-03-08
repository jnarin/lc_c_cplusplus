/*
Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/
Problem: 3005. Count Elements With Maximum Frequency
*/

#define MAX_NUM_VAL (101)
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maxFrequencyElements(int* nums, int numsSize) {
    int freqMap[MAX_NUM_VAL] = {0}, i, maxFreq = 0;
    
    for (i = 0; i < numsSize; i++) {
        freqMap[nums[i]]++;
        maxFreq = MAXVAL(maxFreq, freqMap[nums[i]]);
    }
    
    int ans = 0;
    for (i = 0; i < MAX_NUM_VAL; i++) {
        if (freqMap[i] == maxFreq) {
            ans += maxFreq;
        }
    }
    
    return ans;
}