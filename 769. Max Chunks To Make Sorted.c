/*
Problem: 769. Max Chunks To Make Sorted
Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maxChunksToSorted(int* arr, int arrSize) {
    int i, ans = 0, max = INT_MIN;
    
    for (i = 0; i < arrSize; i++) {
        max = MAXVAL(max, arr[i]);
        if (max == i) {
            ans++;
        }
    }
    
    return ans;
}
