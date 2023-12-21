/*
Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
Problem: 1637. Widest Vertical Area Between Two Points Containing No Points
*/

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b; })

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    int x[pointsSize], i, ans = INT_MIN;
    
    for (i = 0; i < pointsSize; i++){
        x[i] = points[i][0];
    }
    
    qsort(x, pointsSize, sizeof(int), incrCmp);
    
    for (i = 0; i < (pointsSize - 1); i++){
        ans = MAXVAL(ans, x[i + 1] - x[i]);
    }
    
    return ans;    
}