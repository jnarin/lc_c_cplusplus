/*
Problem: 3168. Minimum Number of Chairs in a Waiting Room
Link: https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/
*/

int minimumChairs(char* s) {
    int len = strlen(s), i;
    int ans = INT_MIN, seated = 0;
    
    for (i = 0; i < len; i++) {
        if (s[i] == 'E') {
            seated++;
        } else {
            seated--;
        }
        
        ans = seated > ans ? seated : ans;
    }
    
    return ans;
}
