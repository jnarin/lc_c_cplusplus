/*
Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
Problem: 2125. Number of Laser Beams in a Bank
*/

int numberOfBeams(char** bank, int bankSize) {
    int ans, c, p, i;
    ans = c = p = 0;
    
    for (i = 0; i < bankSize; i++) {
        int len = strlen(bank[i]), j;
        
        for (j = 0; j < len; j++) {
            c = bank[i][j] == '1' ? c + 1 : c;
        }
                
        ans += c * p;
        p = c ? c : p;
        c = 0;
    }
    
    return ans;
}