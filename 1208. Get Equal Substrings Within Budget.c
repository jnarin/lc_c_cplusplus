/*
Problem: 1208. Get Equal Substrings Within Budget
Link: https://leetcode.com/problems/get-equal-substrings-within-budget/
*/

int equalSubstring(char* s, char* t, int maxCost) {
    int i, j = 0, len = strlen(s);
    
    for (i = 0; i < len; i++) {
        maxCost -= abs(s[i] - t[i]);
        
        if (maxCost < 0) {
            maxCost += abs(s[j] - t[j]);
            j++;
        }
    }
    
    return len - j;
}