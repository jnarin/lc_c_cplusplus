/*
Problem: 1358. Number of Substrings Containing All Three Characters
Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/

int numberOfSubstrings(char* s) {
    int len = strlen(s), count[3] = {0}, ans = 0, left = 0, i;

    for(i = 0; i < len; i++) {
        count[s[i] - 'a']++;
        while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
            ans += len - i;
            count[s[left] - 'a']--;
            left++;
        }
    }

    return ans;
}
