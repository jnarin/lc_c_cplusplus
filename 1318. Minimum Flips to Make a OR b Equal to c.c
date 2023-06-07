/*
Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
Problem: 1318. Minimum Flips to Make a OR b Equal to c
*/

int minFlips(int a, int b, int c){
    int ans = 0;
    int x, y, z;
    
    while (a | b | c){
        x = a & 1;
        y = b & 1;
        z = c & 1;
        
        if ((x | y) != z){
            ans = (x == 1 && y == 1 && z == 0) ? ans + 2 : ans + 1;
        }
        
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    
    return ans;

}