/*
Problem: 3136. Valid Word
Link: https://leetcode.com/problems/valid-word/
*/

static bool isVowel(char c) {
    static char vowelList[] = "aeiouAEIOU";
    int len = strlen(vowelList), i;
    
    for (i = 0; i < len; i++) {
        if (c == vowelList[i]) {
            return true;
        }
    }
    
    return false;
}

static bool isConsonant(char c) {
    static char consonantList[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    int len = strlen(consonantList), i;
    
    for (i = 0; i < len; i++) {
        if (c == consonantList[i]) {
            return true;
        }
    }
    
    return false;
}

static bool isAlphaNum(char c) {
    return (c >= '0' && c <= '9')
        || (c >= 'a' && c <= 'z') 
        || (c >= 'A' && c <= 'Z');
}


bool isValid(char* word) {
    int len = strlen(word);
    
    if (len < 3) {
        return false;
    }
    
    int i;
    bool vowel = false, consonant = false;
    
    for (i = 0; i < len; i++) {
        if (vowel == false && isVowel(word[i])) {
            vowel = true;
            continue;
        }
        
        if (consonant == false && isConsonant(word[i])) {
            consonant = true;
            continue;
        }
        
        if (isAlphaNum(word[i]) == false) {
            return false;
        }
    }
    
    return vowel && consonant;
}