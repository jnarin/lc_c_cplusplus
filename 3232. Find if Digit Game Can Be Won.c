/*
Problem: 3232. Find if Digit Game Can Be Won
Link: https://leetcode.com/problems/find-if-digit-game-can-be-won/
*/

bool canAliceWin(int* nums, int numsSize) {
    int singleDigitSum = 0, doubleDigitSum = 0, i;
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 9) {
            doubleDigitSum += nums[i];
        } else {
            singleDigitSum += nums[i];
        }
    }
    
    return singleDigitSum != doubleDigitSum;
}
