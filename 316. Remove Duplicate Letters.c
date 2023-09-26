/*
Link: https://leetcode.com/problems/remove-duplicate-letters/
Problem: 316. Remove Duplicate Letters
*/
#define MAX_ALPHA   (26)
#define MAX_INPUT   (1000)

char * removeDuplicateLetters(char * s){
    char *ans = calloc(MAX_INPUT + 1, sizeof(char));
    int index_map[MAX_ALPHA] = {0}, 
        visit_map[MAX_ALPHA] = {0}, i,
        sLen = strlen(s), ansIdx = 0;
    
    for (i = 0; i < sLen; i++){
        index_map[s[i] - 'a'] = i;
    }
    
    for (i = 0; i < sLen; i++){
        if (visit_map[s[i] - 'a']){
            continue;
        }
        
        while (ansIdx && ans[ansIdx - 1] > s[i] 
               && i <= index_map[ans[ansIdx - 1] - 'a']){
            visit_map[ans[ansIdx - 1] - 'a'] = 0;
            ansIdx--;
        }
        
        ans[ansIdx++] = s[i];
        visit_map[s[i] - 'a'] = 1;
    }
        
    return ans;

}