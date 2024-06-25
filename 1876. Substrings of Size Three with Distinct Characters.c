/*
Problem: 1876. Substrings of Size Three with Distinct Characters
Link: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
*/

static int uniqueElementCount(int *array, int arraySize) {
    int ans = 0, i;
    
    for (i = 0; i < arraySize; i++) {
        ans = array[i] == 1 ? ans + 1 : ans;
    }    
    return ans;
}

int countGoodSubstrings(char* s) {
    int map[26] = {0}, len = strlen(s), i = 0, ans = 0;
    
    if (len < 3) {
        return 0;
    }
    
    map[s[i++] - 'a']++;
    map[s[i++] - 'a']++;
    map[s[i++] - 'a']++;
    
    ans = uniqueElementCount(map, 26) == 3 ? ans + 1 : ans;
    
    for (; i < len; i++) {
        map[s[i - 3] - 'a']--;
        map[s[i] - 'a']++;
        
        ans = uniqueElementCount(map, 26) == 3 ? ans + 1 : ans;
    }
    
    return ans;
}