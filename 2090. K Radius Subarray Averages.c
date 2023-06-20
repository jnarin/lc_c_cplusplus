/*
Link: https://leetcode.com/problems/k-radius-subarray-averages/
Problem: 2090. K Radius Subarray Averages
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize){
    
    unsigned long sum = 0;
    int *ans = calloc(numsSize, sizeof(int));
    int t = (k << 1) + 1, i;
    *returnSize = numsSize;

    for (i = 0; i < numsSize; i++){
        ans[i] = -1;
    }
    
    for (i = 0; i < numsSize; i++){
       sum += nums[i];
       
       if (i - t >= 0){
           sum -= nums[i - t];
       }
       
       if (i >= t - 1){
           ans[i - k] = sum / t;
       }
   }
        
    return ans;
}