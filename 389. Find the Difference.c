/*
Link: https://leetcode.com/problems/find-the-difference/
Problem: 389. Find the Difference
If the two strings are combined together, the problem is to 
find the character whose count is odd.
*/
char findTheDifference(char * s, char * t){
    int lenS = strlen(s), lenT = strlen(t), i;
    char ans = 0;
    
    for (i = 0; i < lenS; i++){
        ans ^= s[i];
    }
    
    for (i = 0; i < lenT; i++){
        ans ^= t[i];
    }
    
    return ans;
}