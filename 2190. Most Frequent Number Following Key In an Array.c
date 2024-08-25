/*
Problem: 2190. Most Frequent Number Following Key In an Array
Link: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/
*/

#define MAX_VAL (1001)

int mostFrequent(int* nums, int numsSize, int key) {
    int freqMap[MAX_VAL] = {0}, i;
    
    for (i = 0; (i + 1 )< numsSize; i++) {
        if (nums[i] == key) {
            freqMap[nums[i + 1]]++;
        }
    }
    
    int ans = -1, maxFreq = INT_MIN;
    
    for (i = 0; i < MAX_VAL; i++) {
        if (freqMap[i] > maxFreq) {
            ans = i;
            maxFreq = freqMap[i];
        }
    }
    
    return ans;
}
