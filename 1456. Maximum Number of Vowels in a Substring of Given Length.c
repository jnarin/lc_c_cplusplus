/*
Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/
Problem: 1456. Maximum Number of Vowels in a Substring of Given Length
*/

static bool isVowel(char c){
    
    const char vowels[] = "aeiou";
    int vowels_len = strlen(vowels);
    int i;
    
    for (i = 0; i < vowels_len; i++){
        if (c == vowels[i]){
            return true;
        }
    }
    
    return false;
}

int maxVowels(char * s, int k){
    assert(s);
    int ans = 0, t = 0, i, len = strlen(s);
    
    for (i = 0; i < k; i++){
        t = isVowel(s[i]) ? t + 1 : t;
    }
    
    ans = t;
    
    for (i = k; i < len; i++){
        t = (((i - k) >= 0) && isVowel(s[i - k])) ? t - 1 : t;
        t = isVowel(s[i]) ? t + 1 : t;

        
        ans = t > ans ? t : ans;
    }
    
    return ans;
}