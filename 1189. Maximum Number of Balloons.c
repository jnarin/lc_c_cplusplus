/*
Problem: 1189. Maximum Number of Balloons
Link: https://leetcode.com/problems/maximum-number-of-balloons/
*/

int maxNumberOfBalloons(char* text) {
    int freq[26] = {0}, ans = 0;
    char *p = text;
    
    while (*p) {
        freq[*p - 'a']++;
        p++;
    }

    for (;;) {
        if (freq['b' - 'a'] >= 1
            && freq['a' - 'a'] >= 1
            && freq['l' - 'a'] >= 2
            && freq['o' - 'a'] >= 2
            && freq['n' - 'a'] >= 1) {
                ans++;
                freq['b' - 'a']--;
                freq['a' - 'a']--;
                freq['l' - 'a'] -= 2;
                freq['o' - 'a'] -= 2;
                freq['n' - 'a']--;
            } else {
                break;
            }
    }
    
    return ans;
}
