/*
Link: https://leetcode.com/problems/binary-subarrays-with-sum/
Problem: 930. Binary Subarrays With Sum
*/

#define MAX_NUM ((3 * 10000) + 1)

int numSubarraysWithSum(int* nums, int numsSize, int goal){
    int map[MAX_NUM] = {0}, prefix = 0, i, ans = 0;
    
    map[0] = 1;
    
    for (i = 0; i < numsSize; i++) {
        prefix += nums[i];
        
        if (prefix - goal >= 0 && prefix - goal < MAX_NUM && map[prefix - goal]) {
            ans += map[prefix - goal];
        }
        
        map[prefix]++;
    }
    
    return ans;
}