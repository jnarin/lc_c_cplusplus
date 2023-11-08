/*
Link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
Problem: 2849. Determine if a Cell Is Reachable at a Given Time
*/

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b; })

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t){
    int dx, dy, s;
    
    dx = abs(sx - fx);
    dy = abs(sy - fy);
    
    s = MAXVAL(dx, dy);
    
    if (s == 0){
        return (t != 1);
    }
    
    return (s <= t);
}