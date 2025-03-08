/*
Problem: 2379. Minimum Recolors to Get K Consecutive Black Blocks
Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int minimumRecolors(char* blocks, int k) {
    int len = strlen(blocks), ans, i, count = 0;

    for (i = 0; i < k; i++) {
        count += blocks[i] == 'B';
    }

    ans = k - count;

    for (i = k; i < len; i++) {
        count -= blocks[i - k] == 'B';
        count += blocks[i] == 'B';

        ans = MINVAL(ans, k - count);
    }

    return ans;
}
