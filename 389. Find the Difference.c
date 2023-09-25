/*
Link: https://leetcode.com/problems/find-the-difference/
Problem: 389. Find the Difference
*/
#define MAX_ALPHA   (26)

char findTheDifference(char * s, char * t){
    int map[MAX_ALPHA] = {0}, lenS = strlen(s), lenT = strlen(t), i;
    
    for (i = 0; i < lenS; i++){
        map[s[i] - 'a']++;
    }
    
    for (i = 0; i < lenT; i++){
        if (map[t[i] - 'a'] <= 0){
            return t[i];
        }
        
        map[t[i] - 'a']--;
    }
    
    return 0;
}