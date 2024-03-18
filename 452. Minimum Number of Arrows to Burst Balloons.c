/*
Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
Problem: 452. Minimum Number of Arrows to Burst Balloons
*/

static int incrCmp(const void *a, const void *b){
    int *ai = *(int * const *)a,
        *bi = *(int * const *)b;

    return (*ai > *bi) - (*ai < *bi);
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 1) {
        return pointsSize;
    }
    
    qsort(points, pointsSize, sizeof(int *), incrCmp);
    
    int tempArray[pointsSize][2], idx = 0, i;
    memset(tempArray, 0, sizeof(tempArray));
    
    tempArray[idx][0] = points[0][0];
    tempArray[idx][1] = points[0][1];
    idx++;
    
    for (i = 1; i < pointsSize; i++) {
        if (points[i][0] <= tempArray[idx - 1][1]) {
            if (points[i][1] < tempArray[idx - 1][1]) {
                tempArray[idx - 1][1] = points[i][1];
            }
        } else {
            tempArray[idx][0] = points[i][0];
            tempArray[idx][1] = points[i][1];
            idx++;
        }
    }
    
    return idx;
    
}