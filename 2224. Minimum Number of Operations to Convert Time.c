/*
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
 * Problem: 2224. Minimum Number of Operations to Convert Time
 * */

static int convertTimeToMins(char *t) {
    int h = ((t[0] * 10) + t[1]) * 60,
        m = (t[3] * 10) + t[4];

    return h + m;
}

int convertTime(char* current, char* correct) {
    int ans = 0,
        currentTime = convertTimeToMins(current),
        correctTime = convertTimeToMins(correct);

    int diff = correctTime - currentTime;

    while (diff) {
        if (diff >= 60) {
            diff -= 60;
        } else if (diff >= 15) {
            diff -=15;
        } else if (diff >= 5) {
            diff -=5;
        } else {
            diff -= 1;
        }

        ans++;
    }

    return ans;
}
