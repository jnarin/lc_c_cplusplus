/*
Link: https://leetcode.com/problems/replace-all-digits-with-characters/
Problem: 1844. Replace All Digits with Characters
*/
char * replaceDigits(char * s){
    int len = strlen(s), i;
    
    for (i = 1; i < len; i++){
        s[i] = isdigit(s[i]) ? s[i - 1] + (s[i] - '0') : s[i];
    }
        
    return s;
}