/*
Link: https://leetcode.com/problems/missing-number/
Problem: 268. Missing Number
*/
int missingNumber(int* nums, int numsSize){
    int sum = 0, i;
    for (i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    
    int t = (numsSize * (numsSize + 1)) / 2;
    
    return t - sum;
}