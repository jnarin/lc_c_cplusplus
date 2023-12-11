/*
Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
Problem: 1287. Element Appearing More Than 25% In Sorted Array
*/
int findSpecialInteger(int* arr, int arrSize) {
    int i, t = arrSize / 4;
    
    for (i = t; i < arrSize; i++){
        if (arr[i - t] == arr[i]){
            return arr[i];
        }
    }
    
    return INT_MIN;
}