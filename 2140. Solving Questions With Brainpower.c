/*
Problem: 2140. Solving Questions With Brainpower
Link: https://leetcode.com/problems/solving-questions-with-brainpower/
*/

#define MAX_VAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b; })
    
long long mostPoints(int** questions, int questionsSize, int* questionsColSize){
    long long dp[questionsSize + 1], nextP;
    memset(dp, 0, sizeof(dp));
    int i, pts, bp, nextIdx;
    
    for (i = questionsSize - 1; i >= 0; i--){
        pts = questions[i][0];
        bp = questions[i][1];
        nextIdx = i + bp + 1;
        nextP = nextIdx < questionsSize ? dp[nextIdx] : 0;
        dp[i] = MAX_VAL(pts + nextP, dp[i + 1]);
    }
    
    return dp[0];
}
