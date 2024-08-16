/*
Problem: 624. Maximum Distance in Arrays
Link: https://leetcode.com/problems/maximum-distance-in-arrays/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int ans = 0, min = 10000, max = -10000, i, len;
    
    for (i = 0; i < arraysSize; i++) {
        len = arraysColSize[i];
        
        ans = MAXVAL(ans, 
                     MAXVAL(arrays[i][len - 1] - min, 
                     max - arrays[i][0]));
        min = MINVAL(min, arrays[i][0]);
        max = MAXVAL(max, arrays[i][len - 1]);
    }
    
    return ans;
}
