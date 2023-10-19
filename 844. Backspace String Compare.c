/*
Link: https://leetcode.com/problems/backspace-string-compare/
Problem: 844. Backspace String Compare
*/

#define CHECK_SKIP_CHAR(c) (((c) == '#') || ((c) == '*'))

/* Simulate backspace character '#' and replace the deleted character
with '+' */
static void parseBS(char *s){
    int sLen = strlen(s), i = sLen - 1, x;
    
    while (i >= 0){
        if (s[i] == '#'){
            x = i - 1;
            while (x >= 0 && CHECK_SKIP_CHAR(s[x])){
                x--;
            }
            
            if (x >= 0){
                s[x] = '*';
            }
        }
        
        i--;
    }
}

/* Check if input strings are same, but ignore any differences where '#' or '+' 
characters are present */
static bool compareBS(char * s, char * t){
    int sLen = strlen(s), tLen = strlen(t);
    int i, j, a, b;
    bool skipCheck = false;
    
    i = j = a = b = 0;
    while (i < sLen || j < tLen){
        if (CHECK_SKIP_CHAR(s[i])){
            skipCheck = true;
            i++;
        }
        
        if (CHECK_SKIP_CHAR(t[j])){
            skipCheck = true;
            j++;
        }
        
        if (skipCheck){
            skipCheck = false;
            continue;
        }
        
        if (i < sLen && j < tLen && s[i] != t[j]){
            return false;
        }
        
        if (i < sLen){
            i++;
            a++;
        }
        
        if (j < tLen){
            j++;
            b++;
        }
    }
    
    return a == b ? true : false;
}

bool backspaceCompare(char * s, char * t){
    if (strcmp(s, t) == 0){
        return true;
    }
    
    parseBS(s);
    parseBS(t);
    
    return compareBS(s, t);
}
