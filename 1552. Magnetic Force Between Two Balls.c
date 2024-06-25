/*
Problem: 1552. Magnetic Force Between Two Balls
Link: https://leetcode.com/problems/magnetic-force-between-two-balls/
*/

#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1)) 

static int incrCmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static bool canPlaceBalls(int x, int *position, int positionSize, int m) {
    int p = position[0], ballsPlaced = 1, i;
    
    for (i = 1; i < positionSize && ballsPlaced < m; i++) {
        int c = position[i];
        
        if (c - p >= x) {
            ballsPlaced += 1;
            p = c;
        }
    }
    
    return ballsPlaced == m;
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), incrCmp);
    
    int ans = 0, low = 1, high = ceil(position[positionSize - 1]/(m - 1.0)), mid;
    
    while (low <= high) {
        mid = MIDVAL(low, high);
        
        if (canPlaceBalls(mid, position, positionSize, m)) {
            ans = mid;
            
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return ans;
}