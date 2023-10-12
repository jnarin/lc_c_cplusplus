/*
Link: https://leetcode.com/problems/find-in-mountain-array/
Problem: 1095. Find in Mountain Array
*/

/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */
#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))
typedef enum{
    LEFT = 0,
    RIGHT = 1,
}eDIR;

static int search(MountainArray* mountainArr, int target, int l, int r, eDIR d){
    int m;
    
    if (d == LEFT){
        while (l < r){
            m = MIDVAL(l, r);
            
            if (get(mountainArr, m) < target){
                l = m + 1;
            } else {
                r = m;
            }
        }
    } else {
        while (l < r){
            m = MIDVAL(l, r);

            if (get(mountainArr, m) > target){
                l = m + 1;
            } else {
                r = m;
            }
        }
    }
    
    return l;
}

static int getPeakIdx(MountainArray* mountainArr, int l, int r){
    int m;
    while (l < r){
        m = MIDVAL(l, r);
        
        if (get(mountainArr, m) < get(mountainArr, m + 1)){
            l = m + 1;
        } else {
            r = m;
        }

    }
    
    return l;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int len = length(mountainArr);
    int p = getPeakIdx(mountainArr, 0, len - 1);
	
    int l = search(mountainArr, target, 0, p, LEFT);
    if (get(mountainArr, l) == target){
        return l;
    }
    
    int r = search(mountainArr, target, p + 1, len - 1, RIGHT);
    if (get(mountainArr, r) == target){
        return r;
    }
    
    return -1;
}