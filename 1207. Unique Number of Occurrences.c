/*
Link: https://leetcode.com/problems/unique-number-of-occurrences/
Problem: 1207. Unique Number of Occurrences
*/

#define MAX_NUMS    (3000)

bool uniqueOccurrences(int* arr, int arrSize) {
    int freqMap[MAX_NUMS] = {0}, i;
    
    for (i = 0; i < arrSize; i++) {
        freqMap[arr[i] + 1000]++;
    }
    
    int freqCount[MAX_NUMS] = {0};
    
    for (i = 0; i < MAX_NUMS; i++) {
        if (freqMap[i] && freqCount[freqMap[i]]) {
            return false;
        }
        
        freqCount[freqMap[i]]++;
    }
    
    return true;
}