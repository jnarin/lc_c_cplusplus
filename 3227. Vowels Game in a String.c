/*
Problem: 3227. Vowels Game in a String
Link: https://leetcode.com/problems/vowels-game-in-a-string/
*/

static bool isVowel(char c) {
    const char *vowels = "AEIOUaeiou";
    int i;
    bool ret = false;

    for (i = 0; vowels[i]; i++) {
        if (c == vowels[i]){
            ret = true;
        }
    }
    
    return ret;
}

bool doesAliceWin(char* s) {
    int i;
    bool ret = false;

    for (i = 0; s[i]; i++) {
        if (isVowel(s[i]) == true) {
            ret = true;
            break;
        }
    }
    
    return ret;
}
