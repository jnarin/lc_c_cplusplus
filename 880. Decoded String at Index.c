/*
Link: https://leetcode.com/problems/decoded-string-at-index/
Problem: 880. Decoded String at Index
*/
char * decodeAtIndex(char * s, int k){
    char *ans = calloc(2, sizeof(char));
    long size = 0;
    int sLen = strlen(s), i;
    
    for (i = 0; i < sLen; i++){
        size = isdigit(s[i]) 
            ? size * (s[i] - '0') 
            : size + 1;
    }

    for (i = sLen - 1; i >= 0; i--){
        k %= size;
        if (k == 0 && isalpha(s[i])){
            ans[0] = s[i];
            return ans;
        }
        
        size = isdigit(s[i]) 
            ? size / (s[i] - '0')
            : size - 1;
    }
    
    assert(0);
}