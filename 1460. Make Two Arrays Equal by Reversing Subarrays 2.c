/*
Problem: 1460. Make Two Arrays Equal by Reversing Subarrays
Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/submissions/
*/

#define MAX_MAP_SIZE    (1001)

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    if (arrSize != targetSize) {
        return false;
    }
    
    int arrMap[MAX_MAP_SIZE] = {0}, targetMap[MAX_MAP_SIZE] = {0},
        i;
    
    for (i = 0; i < arrSize; i++) {
        arrMap[arr[i]]++;
    }
    
    for (i = 0; i < targetSize; i++) {
        targetMap[target[i]]++;
    }
    
    return memcmp(arrMap, targetMap, sizeof(arrMap)) == 0;
}
