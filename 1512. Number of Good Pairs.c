/*
Link: https://leetcode.com/problems/number-of-good-pairs/
Problem: 1512. Number of Good Pairs
*/
#define MAX_NUM  (101)

int numIdenticalPairs(int* nums, int numsSize){
    int map[MAX_NUM] = {0}, i, ans = 0;
    
    for (i = 0; i < numsSize; i++){
        map[nums[i]]++;
    }
    
    for (i = 0; i < MAX_NUM; i++){
        if (map[i]){
            ans += (map[i] * (map[i] - 1)) >> 1;
        }
    }

    return ans;
}