/*
Problem: 2078. Two Furthest Houses With Different Colors
Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
*/

int maxDistance(int* colors, int colorsSize){
    int ans = 0, i;
    int l, r;
    
    l = 0;
    r = colorsSize - 1;
    while (l < r){
        if (colors[l] != colors[r]){
            ans = r - l;
            break;
        }
        r--;
    }
    
    r = colorsSize - 1;
    while (l < r){
        if (colors[l] != colors[r]){
            ans = (r - l) > ans ? (r - l) : ans;
            break;
        }
        l++;
    }
    
    return ans;

}
