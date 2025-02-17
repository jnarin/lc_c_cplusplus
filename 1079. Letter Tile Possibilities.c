/*
Problem: 1079. Letter Tile Possibilities
Link: https://leetcode.com/problems/letter-tile-possibilities/
*/

static int dfs(int *freq, const int len) {
    int ans = 0, i;

    for (i = 0; i < len; i++) {
        if (freq[i]) {
            freq[i]--;
            ans += 1 + dfs(freq, len);
            freq[i]++;
        }
    }

    return ans;
}

int numTilePossibilities(char* tiles) {
    int freq[26] = {0};

    while (*tiles) {
        freq[*tiles - 'A']++;
        tiles++;
    }
    
    return dfs(freq, 26);
}
