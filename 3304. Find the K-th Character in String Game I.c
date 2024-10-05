/*
Problem: 3304. Find the K-th Character in String Game I
Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
*/

char kthCharacter(int k) {
    int v = k;
    
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    
    char s[v + 1];
    s[v] = '\0';
    
    int idx = 0, i, t;
    s[idx++] = 'a';
    
    while (idx < k) {
        t = idx;
        for (i = 0; i < t; i++) {
            s[idx++] = s[i] != 'z' ? s[i] + 1 : 'a';
        }
    }
    
    return s[k - 1];
}
