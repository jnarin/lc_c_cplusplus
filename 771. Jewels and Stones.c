/*
Problem: 771. Jewels and Stones
Link: https://leetcode.com/problems/jewels-and-stones/
*/

int numJewelsInStones(char* jewels, char* stones) {
    int jewelMap[256] = {0}, i, ans = 0;
    int jewelLen = strlen(jewels), stonesLen = strlen(stones);
    
    for (i = 0; i < jewelLen; i++) {
        jewelMap[jewels[i]]++;
    }
    
    for (i = 0; i < stonesLen; i++) {
        ans = jewelMap[stones[i]] ? ans + 1 : ans;
    }
    
    return ans;
}
