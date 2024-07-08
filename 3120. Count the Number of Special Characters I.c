/*
Problem: 3120. Count the Number of Special Characters I
Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/
*/

int numberOfSpecialChars(char* word) {
    int len = strlen(word), map[128] = {0}, i, ans = 0;
    
    for (i = 0; i < len; i++) {
        map[word[i]]++;
    }
    
    for (i = 'A'; i <= 'Z'; i++) {
        if (map[i]) {
            ans += map[i - 'A' + 'a'] ? 1 : 0;
        }
    }
    
    return ans;
}
