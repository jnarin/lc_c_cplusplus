/*
Link: https://leetcode.com/problems/sort-characters-by-frequency/
Problem: 451. Sort Characters By Frequency
*/

#define MAX_ALPHA_NUM   (128)
#define MAXVAL(a, b) \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

char* frequencySort(char* s) {
    int len = strlen(s), i;
    int map[MAX_ALPHA_NUM] = {0}, maxFreq = 0, idx = 0;
    char *ans = calloc(len + 1, sizeof(char));
    
    for (i = 0; i < len; i++) {
        map[s[i]]++;
        
        maxFreq = MAXVAL(map[s[i]], maxFreq);
    }
    
    while (maxFreq) {
        for (i = 0; i < MAX_ALPHA_NUM; i++) {
            if (map[i] == maxFreq) {
                while (map[i]--) {
                    ans[idx++] = (char)i;
                }
            }
        }
        
        maxFreq--;
    }
    
    return ans;
}