/*
Problem: 3208. Alternating Groups II
Link: https://leetcode.com/problems/alternating-groups-ii/
*/

int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    int ans = 0, c = 0, i;

    for (i = 0; i < (colorsSize * 2); i++) {
        c = (i && colors[i % colorsSize] == colors[(i - 1) % colorsSize]) ? 1 : c + 1;
        ans += i >= colorsSize && c >= k;
    }

    return ans;    
}
