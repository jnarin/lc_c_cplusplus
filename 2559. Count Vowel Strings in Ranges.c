/*
Problem: 2559. Count Vowel Strings in Ranges
Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/description/
*/

static bool isVowel(char c) {
    char *vowels = "AEIOUaeiou";
    int vowelCount = strlen(vowels), i;

    for (i = 0; i < vowelCount; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }

    return false;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int s[wordsSize + 1], i, len;
    char a, b;

    s[0] = 0;

    for (i = 0; i < wordsSize; i++) {
        len = strlen(words[i]);
        a = words[i][0];
        b = words[i][len - 1];

        if (isVowel(a) && isVowel(b)) {
            s[i + 1] = s[i] + 1;
        } else {
            s[i + 1] = s[i];
        }
    }

    int *result = calloc(queriesSize, sizeof(int));
    *returnSize = queriesSize;

    for (i = 0; i < queriesSize; i++) {
        result[i] = s[queries[i][1] + 1] - s[queries[i][0]];
    }

    return result;
}
