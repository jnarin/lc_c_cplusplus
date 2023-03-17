/*
Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/
Problem: 1394. Find Lucky Integer in an Array
Approach:
The values of numbers will be within 1 and 500,
they can be counted using a map
Iterate map in reverse and return the largest number that
matches the frequency
*/

#define MAX_ARR_VAL (501)
int findLucky(int* arr, int arrSize){
    int i;
    int map[MAX_ARR_VAL] = {0};
    
    for (i = 0; i < arrSize; i++){
        assert(arr[i] > 0 && arr[i] < 501);
        map[arr[i]]++;
    }
    
    for (i = MAX_ARR_VAL - 1; i > 0; i--){
        if (map[i] == i){
            return i;
        }
    }
    
    return -1;
}
