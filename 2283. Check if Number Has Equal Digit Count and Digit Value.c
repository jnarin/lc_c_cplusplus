/*
 * Problem: 2283. Check if Number Has Equal Digit Count and Digit Value
 * Link: https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/
 * */

bool digitCount(char* num) {
    int map[10] = {0}, len = strlen(num), i;

    for (i = 0; i < len; i++) {
        map[num[i] - '0']++;
    }

    for (i = 0; i < len; i++) {
        if (map[i] != num[i] - '0') {
            return false;
        }
    }

    return true;
}
