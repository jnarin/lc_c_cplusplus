/*
Link: https://leetcode.com/problems/largest-odd-number-in-string/
Problem: 1903. Largest Odd Number in String
*/
#define CHRNUMTONUM(c) ((c) - '0')

char* largestOddNumber(char* num) {
    int len = strlen(num), i;
    
    for (i = len - 1; i >= 0; i--){
        if (CHRNUMTONUM(num[i]) & 1){
            break;
        }
    }
    
    char *ans = calloc((i + 1) + 1, sizeof(char)); // (i + 1) bytes for chars, 1 for '\0'
    if (i >= 0){
        strncpy(ans, num, i + 1);
    }
    
    return ans;    
}