/*
 * Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
 * Problem: 1422. Maximum Score After Splitting a String
 * */

#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maxScore(char* s) {
    int len = strlen(s), countZero = 0, countOne = 0, ans = INT_MIN, i;
    
    for (i = 0; i < len - 1; i++) {
        if (s[i] == '0') {
            countZero++;
        } else {
            countOne++;
        }
        
        ans = MAXVAL(ans, countZero - countOne);
    }
    
    if (i < len) {
        if (s[i] == '0') {
            countZero++;
        } else {
            countOne++;
        }
    }
    
    return ans + countOne;
}
