/*
Problem: 2068. Check Whether Two Strings are Almost Equivalent
Link: https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
*/

bool checkAlmostEquivalent(char* word1, char* word2) {
    int map1[26] = {0}, map2[26] = {0}, i, diff,
        len1 = strlen(word1), len2 = strlen(word2);
    
    for (i = 0; i < len1; i++) {
        map1[word1[i] - 'a']++;
    }
    
    for (i = 0; i < len2; i++) {
        map2[word2[i] - 'a']++;
    }
    
    for (i = 0; i < 26; i++) {
        diff = abs(map1[i] - map2[i]);
        if (diff > 3) {
            return false;
        }
    }
    
    return true;
}
