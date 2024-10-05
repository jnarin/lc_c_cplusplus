/*
Problem: 567. Permutation in String
Link: https://leetcode.com/problems/permutation-in-string/
*/

bool checkInclusion(char* s1, char* s2) {
    int s1Len = strlen(s1), s2Len = strlen(s2),
        s1Map[26] = {0}, s2Map[26] = {0}, i;
    
    if (s1Len > s2Len) {
        return false;
    }
    
    for (i = 0; i < s1Len; i++) {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;
    }
    
    for (i = s1Len; i < s2Len; i++) {
        if (memcmp(s1Map, s2Map, sizeof(s1Map)) == 0) {
            return true;
        }
        
        s2Map[s2[i - s1Len] - 'a']--;
        s2Map[s2[i] - 'a']++;
    }
    
    return memcmp(s1Map, s2Map, sizeof(s1Map)) == 0 ? true : false;    
}
