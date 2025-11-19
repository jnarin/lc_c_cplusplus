/*
Problem: 2154. Keep Multiplying Found Values by Two
Link: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
*/

#define MAXVAL  (1001)
int findFinalValue(int* nums, int numsSize, int original) {
    char map[MAXVAL] = {0};
    int i;
    
    for (i = 0; i < numsSize; i++) {
        map[nums[i]] = 1;
    }
    
    while (original < MAXVAL) {
        if (map[original]) {
            original <<= 1;
        } else {
            break;
        }
    }
    
    return original;
}
