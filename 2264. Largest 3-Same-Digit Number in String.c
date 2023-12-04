/*
Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/
Problem: 2264. Largest 3-Same-Digit Number in String
*/

char* largestGoodInteger(char* num) {
    const char *vals[] = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
    char *ans = calloc(3 + 1, sizeof(char));
    int i;
    
    for (i = 0; i < 10; i++){
        if (strstr(num, vals[i])){
            strncpy(ans, vals[i], 3);
            break;
        }
    }
    
    return ans;    
}