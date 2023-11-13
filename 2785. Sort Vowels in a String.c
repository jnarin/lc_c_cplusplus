/*
Link: https://leetcode.com/problems/sort-vowels-in-a-string/
Problem: 2785. Sort Vowels in a String
*/

static bool isVowel(char c){
    const char *vowelList = "AEIOUaeiou";
    int len = strlen(vowelList), i;
    
    for (i = 0; i < len; i++){
        if (vowelList[i] == c){
            return true;
        }
    }
    
    return false;
}

static int incrCmp(const void *a, const void *b){
    return *(char *)a - *(char *)b;
}

char * sortVowels(char * s){
    int len = strlen(s), i, vowelsIdx = 0;
    char vowels[len];
    
    memset(vowels, 0, sizeof(vowels));
    
    /* Hint 1: Extract vowels from input and sort the
    array of vowels */
    for (i = 0; i < len; i++){
        if (isVowel(s[i])){
            vowels[vowelsIdx++] = s[i];
        }
    }
    
    qsort(vowels, vowelsIdx, sizeof(char), incrCmp);
    
    /* Replace the vowels in input with those from sorted array */
    vowelsIdx = 0;
    for (i = 0; i < len; i++){
        if (isVowel(s[i])){
            s[i] = vowels[vowelsIdx++];
        }
    }
    
    return s;
}