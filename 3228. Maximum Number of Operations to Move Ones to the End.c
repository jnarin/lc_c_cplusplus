/*
Problem: 3228. Maximum Number of Operations to Move Ones to the End
Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
*/

int maxOperations(char* s) {
    int ans = 0, countOnes = 0;
    char *t;

    t = s;
    while (*t) {
        if (*t == '1') {
            countOnes++;
        } else if (*(t + 1) == '\0' || *(t + 1) == '1') {
            ans += countOnes;
        }

        t++;
    }
    
    return ans;
}
