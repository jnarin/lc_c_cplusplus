/*
Problem: 3090. Maximum Length Substring With Two Occurrences
Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

int maximumLengthSubstring(char* s) {
    int ans = 0, freq[26] = {0}, len = strlen(s);

    for (int l = 0, r = 0; r < len; r++) {
        freq[s[r] - 'a']++;
        while (freq[s[r] - 'a'] > 2) {
            freq[s[l++] - 'a']--;
        }

        ans = MAXVAL(ans, r - l + 1);
    }
    
    return ans;
}
