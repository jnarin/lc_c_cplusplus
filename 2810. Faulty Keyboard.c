/*
Problem: 2810. Faulty Keyboard
Link: https://leetcode.com/problems/faulty-keyboard/
*/

static void reverse(char *s, int len) {
    int i;
    char t;
    
    for (i = 0; i < (len >> 1); i++) {
        t = s[len - i - 1];
        s[len - i - 1] = s[i];
        s[i] = t;
    }
}

char* finalString(char* s) {
    int len = strlen(s), i, idx = 0;
    char *ans = calloc(len + 1, sizeof(char));
    
    for (i = 0; i < len; i++) {
        if (s[i] == 'i') {
            reverse(ans, idx);
            continue;
        }
        
        ans[idx++] = s[i];
    }
        
    return ans;
}
