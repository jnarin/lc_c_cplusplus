/*
Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/
Problem: 2348. Number of Zero-Filled Subarrays
*/

long long zeroFilledSubarray(int* nums, int numsSize){
    long long ans = 0;
    int count = 0, i;
    
    for (i = 0; i < numsSize; i++){
        if (nums[i] == 0){
            count++;
            ans += count;
        } else {
            count = 0;
        }
    }
    
    return ans;
}