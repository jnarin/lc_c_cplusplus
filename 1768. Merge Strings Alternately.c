/*
Link: https://leetcode.com/problems/merge-strings-alternately/
Problem: 1768. Merge Strings Alternately
*/
char * mergeAlternately(char * word1, char * word2){
    assert(word1);
    assert(word2);
    
    int len1 = strlen(word1), len2 = strlen(word2);
    char *ans = calloc(len1 + len2 + 1, sizeof(char));
    assert(ans);
    
    int i, j, k;
    i = j = k = 0;
    
    char f = 0;
    
    while (i < len1 && j < len2){
        if (f == 0){
            ans[k] = word1[i];
            i++;
        } else {
            ans[k] = word2[j];
            j++;
        }
        
        f ^= 1;
        k++;
    }
    
    while (i < len1){
        ans[k++] = word1[i++];
    }
    
    while (j < len2){
        ans[k++] = word2[j++];
    }
    
    return ans;

}