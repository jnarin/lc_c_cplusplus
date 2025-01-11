/*
Problem: 1400. Construct K Palindrome Strings
Link: https://leetcode.com/problems/construct-k-palindrome-strings/
*/

bool canConstruct(char* s, int k) {
    int map[26] = {0}, len = strlen(s), oddCharCount = 0, i;

    if (len < k) {
        return false;
    }
    
    for (i = 0; i < len; i++) {
        map[s[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        oddCharCount += map[i] & 1;
    }

    return oddCharCount > k ? false : true;
}
