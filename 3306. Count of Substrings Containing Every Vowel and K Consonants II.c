/*
Problem: 3306. Count of Substrings Containing Every Vowel and K Consonants II
Link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/
*/

static bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

static int mapEntries(const int *map, const int size) {
    int count = 0, i;

    for (i = 0; i < size; i++) {
        if (map[i] > 0) {
            count++;
        }
    }

    return count;
}

static long long count(const char *word, const int len, const int k) {
    long long ans = 0;
    int l = 0, consonantCount = 0, map[26] = {0}, i;
    char w;

    for (i = 0; i < len; i++) {
        if (isVowel(word[i])) {
            map[word[i] - 'a']++;
        } else {
            consonantCount++;
        }

        while (consonantCount >= k && mapEntries(map, 26) == 5) {
            w = word[l++];
            if (isVowel(w)) {
                map[w - 'a']--;
            } else {
                consonantCount--;
            }
        }

        ans += l;
    }

    return ans;
}


long long countOfSubstrings(char* word, int k) {
    int len = strlen(word);
    return count(word, len, k) - count(word, len, k + 1);
}
