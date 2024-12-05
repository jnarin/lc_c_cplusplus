/*
Problem: 2337. Move Pieces to Obtain a String
Link: https://leetcode.com/problems/move-pieces-to-obtain-a-string/
*/

bool canChange(char* start, char* target) {
    int len = strlen(start), i, j;
    i = j = 0;
    
    while (i <= len && j <= len) {
        while (i < len && start[i] == '_') {
            i++;
        }
        
        while (j < len && target[j] == '_') {
            j++;
        }
        
        if (i == len || j == len) {
            return i == len && j == len;
        }
        
        if (start[i] != target[j]) {
            return false;
        }
        
        if (start[i] == 'R' && i > j) {
            return false;
        }
        
        if (start[i] == 'L' && i < j) {
            return false;
        }
        
        i++;
        j++;
    }
    
    return true;    
}
