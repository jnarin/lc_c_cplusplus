/*
 * Problem: 42. Trapping Rain Water
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * */

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

int trap(int* height, int heightSize){
    int ans = 0;
    int l[heightSize], r[heightSize];
    int i;

    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));

    for (i = 1; i < heightSize; i++){
        l[i] = MAX(l[i - 1], height[i - 1]);
    }

    for(i = heightSize - 2; i >= 0; i--){
        r[i] = MAX(r[i + 1], height[i + 1]);
    }

    for(i = 1; i < heightSize - 1; i++){
        int t = MIN(l[i], r[i]);
        t = t - height[i];
        ans += MAX(0,  t);
    }

    return ans;
}

