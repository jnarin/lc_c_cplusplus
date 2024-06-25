/*
Problem: 1122. Relative Sort Array
Link: https://leetcode.com/problems/relative-sort-array/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXNUMVAL   (1001)

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int map[MAXNUMVAL], i;
    memset(map, 0, sizeof(map));
    
    for (i = 0; i < arr1Size; i++){
        map[arr1[i]]++;
    }
    
    int *ans = calloc(arr1Size, sizeof(int)), idx = 0;
    *returnSize = arr1Size;
    for (i = 0; i < arr2Size; i++){
        while (map[arr2[i]] > 0){
            ans[idx++] = arr2[i];
            map[arr2[i]]--;
        }
    }
    
    for (i = 0; i < MAXNUMVAL; i++){
        while (map[i] > 0){
            ans[idx++] = i;
            map[i]--;
        }
    }
    
    return ans;
}
