/*
 * Problem: 2000. Reverse Prefix of Word
 * Link: https://leetcode.com/problems/reverse-prefix-of-word/
 * */

char* reversePrefix(char* word, char ch) {
    int len = strlen(word), i = 0, stackTop = 0, idx = 0;
    char *ans = calloc(len + 1, sizeof(char)), stack[len];
    bool must_reverse = false;

    memset(stack, 0, sizeof(stack));

    while (i < len) {
        if (word[i] != ch) {
            stack[stackTop++] = word[i++];
            continue;
        }

        if (word[i] == ch) {
            stack[stackTop++] = word[i++];
            must_reverse = true;
            break;
        }
    }

    if (must_reverse == false) {
        strncpy(ans, word, len);
    } else {
        while (stackTop) {
            ans[idx++] = stack[--stackTop];
        }

        for (; i < len; i++) {
            ans[idx++] = word[i];
        }
    }

    return ans;
}
