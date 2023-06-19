/*
Link: https://leetcode.com/problems/find-the-highest-altitude/
Problem: 1732. Find the Highest Altitude
*/
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int largestAltitude(int* gain, int gainSize){
    int i, ans = 0, t = 0;
    
    for (i = 0; i < gainSize; i++){
        t += gain[i];
        ans = MAXVAL(ans, t);
    }
    
    return ans;
}