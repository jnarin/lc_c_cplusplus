/*
Problem: 3541. Find Most Frequent Vowel and Consonant
Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

static bool isVowel(char c) {
    const char *vowels = "AEIOUaeiou";
    int i;

    for (i = 0; vowels[i]; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }

    return false;
}

static void getMaxCounts(int *freq, int size, int *maxVowel, int *maxConsonant) {
    int i;

    for (i = 0; i < size; i++) {
        if (isVowel(i + 'a')) {
            *maxVowel = MAXVAL(*maxVowel, freq[i]);
        } else {
            *maxConsonant = MAXVAL(*maxConsonant, freq[i]);
        }
    }

    return;
}

int maxFreqSum(char* s) {
    int freq[26] = {0}, i, maxVowel = 0, maxConsonant = 0;;

    for (i = 0; s[i]; i++) {
        freq[s[i] - 'a']++;
    }

    getMaxCounts(freq, 26, &maxVowel, &maxConsonant);
    
    return maxVowel + maxConsonant;
}
