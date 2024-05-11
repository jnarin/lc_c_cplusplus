/*
 * Problem: 58. Length of Last Word
 * Link: https://leetcode.com/problems/length-of-last-word/
 * */

int lengthOfLastWord(char* s) {
    int r = 0;
    int i = strlen(s) - 1;

    while (s[i] == ' '){
        i--;
    }

    while (i >= 0){
        if (s[i] == ' '){
            break;
        }

        r++;
        i--;
    }

    return r;

}

