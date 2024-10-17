/*
Problem: 670. Maximum Swap
Link: https://leetcode.com/problems/maximum-swap/
*/

#define MAX_DIGITS  (10)

int maximumSwap(int num) {
    char sNum[MAX_DIGITS + 1];

    sNum[MAX_DIGITS] = '\0';

    snprintf(sNum, MAX_DIGITS, "%d", num);

    int len = strlen(sNum), last[10], i, j;

    for (i = 0; i< 10; i++) {
        last[i] = -1;
    }

    for (i = 0; i < len; i++) {
        last[sNum[i] - '0'] = i;
    }

    for (i= 0; i < len; i++) {
        for (j = 9; j > sNum[i] - '0'; j--) {
            if(last[j] > i) {
                char tmp = sNum[i];
                sNum[i] = sNum[last[j]];
                sNum[last[j]] = tmp;

                return atoi(sNum);
            }
        }
    }

    return num;
}
