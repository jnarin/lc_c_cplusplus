/*
Problem: 344. Reverse String
Link: https://leetcode.com/problems/reverse-string/
*/

void reverseString(char* s, int sSize){
    char t;
    int i;
    int n = sSize >> 1;
    
    for (i = 0; i < n; i++){
        t = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = t;
    }
    
    return;
}