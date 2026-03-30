/*
Problem: 2840. Check if Strings Can be Made Equal With Operations II
Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
*/

bool checkStrings(char* s1, char* s2){
    int map[2][26] = {0}, i, len = strlen(s1);
    
    for (i = 0; i < len; i++) {
        map[i & 1][s1[i] - 'a']++;
        map[i & 1][s2[i] - 'a']--;
    }
    
    for (i = 0; i < 26; i++) {
        if (map[0][i] || map[1][i]) {
            return false;
        }
    }

    return true;
}
