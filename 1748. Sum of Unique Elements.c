/*
Problem: 1748. Sum of Unique Elements
Link: https://leetcode.com/problems/sum-of-unique-elements/
*/

int sumOfUnique(int* nums, int numsSize) {
    int map[101] = {0}, i, ans = 0;
    
    for (i = 0; i < numsSize; i++) {
        map[nums[i]]++;
    }
    
    for (i = 0; i < 101; i++) {
        if (map[i] == 1) {
            ans += i;
        }
    }
    
    return ans;
}
