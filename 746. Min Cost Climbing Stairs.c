/*
Link: https://leetcode.com/problems/min-cost-climbing-stairs/
Problem: 746. Min Cost Climbing Stairs
*/
#define MINVAL(a, b)    \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b;  })

int minCostClimbingStairs(int* cost, int costSize){
    int i;
    
    for (i = 2; i < costSize; i++){
        cost[i] += MINVAL(cost[i - 1], cost[i - 2]);
    }
    
    return MINVAL(cost[costSize - 1], cost[costSize - 2]);
}