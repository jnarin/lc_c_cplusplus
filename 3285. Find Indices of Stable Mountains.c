/*
Problem: 3285. Find Indices of Stable Mountains
Link: https://leetcode.com/problems/find-indices-of-stable-mountains/
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int *ans = calloc(heightSize, sizeof(int)), idx = 0;
    int i;
    
    for (i = 1; i < heightSize; i++) {
        if (height[i - 1] <= threshold) {
            continue;
        }
        
        ans[idx++] = i;
    }
    
    *returnSize = idx;
    return ans;
}
