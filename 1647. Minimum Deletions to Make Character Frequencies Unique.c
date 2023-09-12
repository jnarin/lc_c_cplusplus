/*
Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
Problem: 1647. Minimum Deletions to Make Character Frequencies Unique
*/
#define MINVAL(a, b)   \
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a < _b ? _a : _b; })

#define MAX_CHAR    (26)

static int decr_cmp(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int minDeletions(char * s){
    int freq_map[MAX_CHAR] = {0}, i, len = strlen(s), f, ans = 0, curr_freq;
    
    for (i = 0; i < len; i++){
        freq_map[s[i] - 'a']++;
    }
    
    qsort(freq_map, MAX_CHAR, sizeof(int), decr_cmp);
    
    f = freq_map[0];
    
    for (i = 0; i < MAX_CHAR; i++){
        curr_freq = freq_map[i];
        if (curr_freq > f){
            ans = f > 0 ? ans + (curr_freq - f) : ans + curr_freq;
        }
        
        f = MINVAL(f - 1, curr_freq - 1);
    }

    return ans;
}