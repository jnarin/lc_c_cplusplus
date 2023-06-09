/*
 * Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
 * Problem: 1128. Number of Equivalent Domino Pairs
 * */

#define MINVAL(a, b)  \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b); \
    _a < _b ? _a : _b; })

#define MAXVAL(a, b)  \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b); \
    _a > _b ? _a : _b; })

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
    int map[100] = {0}, ans = 0, i;

    for (i = 0; i < dominoesSize; i++){
        int t = MINVAL(dominoes[i][0], dominoes[i][1]) * 10 + MAXVAL(dominoes[i][0], dominoes[i][1]);
        ans += map[t];
        map[t]++;
    }

    return ans;
}

