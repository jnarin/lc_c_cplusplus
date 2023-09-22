/*
Link: https://leetcode.com/problems/is-subsequence/
Probem: 392. Is Subsequence
*/
bool isSubsequence(char * s, char * t){
    int sLen = strlen(s), tLen = strlen(t), i = 0, j = 0;
    
    while (i < sLen && j < tLen){
        if (s[i] != t[j]){
            j++;
            continue;
        }
        
        i++;
        j++;
    }
    
    return i == sLen ? true : false;
}