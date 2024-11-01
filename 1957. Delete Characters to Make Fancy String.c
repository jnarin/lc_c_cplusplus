/*
Problem: 1957. Delete Characters to Make Fancy String
Link: https://leetcode.com/problems/delete-characters-to-make-fancy-string
*/

char* makeFancyString(char* s) {
    int n = strlen(s);
    int i = 0, j = 0;
    while(j < n) {
        if(j < n - 2 && s[j] == s[j + 1] && s[j] == s[j + 2]) {
            j++;
        } else {
            s[i++] = s[j++];
        }
    }
    s[i] = '\0';
    
    return s;
}
