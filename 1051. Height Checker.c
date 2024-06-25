/*
Problem: 1051. Height Checker
Link: https://leetcode.com/problems/height-checker/
*/

static int incr_cmp(void *a, void *b){
    return *(int *)a - *(int *)b;
}

int heightChecker(int* heights, int heightsSize){
    int sortedHeights[heightsSize];
    memcpy(sortedHeights, heights, sizeof(sortedHeights));
    qsort(sortedHeights, heightsSize, sizeof(int), incr_cmp);
    
    int i, ans = 0;
    
    for (i = 0; i < heightsSize; i++){
        ans = heights[i] != sortedHeights[i] ? ans + 1 : ans;
    }
    
    return ans;
}