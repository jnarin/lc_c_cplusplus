/*
Link: https://leetcode.com/problems/rotate-string/
Problem: 796. Rotate String
*/
bool rotateString(char * s, char * goal){
    int len = strlen(s), len2 = len << 1;
    
    if (len != strlen(goal)){
        return false;
    }
    
    char t[len2 + 1];
    t[len2] = '\0';
    
    strncpy(&t[0], s, len);
    strncpy(&t[len], s, len);
    
    return strstr(t, goal) ? true : false;
}