/*
Problem: 3158. Find the XOR of Numbers Which Appear Twice
Link: https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/
*/

#define MAXNUM  (51)
int duplicateNumbersXOR(int* nums, int numsSize) {
    int map[MAXNUM] = {0}, i;
    
    for (i = 0; i < numsSize; i++) {
        map[nums[i]]++;
    }
    
    int ans = 0;
    
    for (i = 0; i < MAXNUM; i++) {
        if (map[i] == 2) {
            ans ^= i;
        }
    }
    
    return ans;
}