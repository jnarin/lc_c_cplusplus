/*
Problem: 2206. Divide Array Into Equal Pairs
Link: https://leetcode.com/problems/divide-array-into-equal-pairs/
*/

bool divideArray(int* nums, int numsSize) {
    int map[501] = {0};
    int i;
    
    for (i = 0; i < numsSize; i++) {
        map[nums[i]]++;
    }
    
    for (i = 0; i < 501; i++) {
        if (map[i] && (map[i] & 1)) {
            return false;
        }
    }
    
    return true;
}
