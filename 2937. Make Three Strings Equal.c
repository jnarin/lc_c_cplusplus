/*
Problem: 2937. Make Three Strings Equal
Link: https://leetcode.com/problems/make-three-strings-equal/
*/

int findMinimumOperations(char* s1, char* s2, char* s3) {
    int s1Len = strlen(s1), s2Len = strlen(s2), s3Len = strlen(s3);
    int i = 0;
    
    while (i < s1Len && i < s2Len && i < s3Len) {
        if (s1[i] == s2[i] && s2[i] == s3[i]) {
            i++;
            continue;
        } 
        
        break;
    }
    
    return i == 0 ? -1 : s1Len + s2Len + s3Len - i * 3;   
}
