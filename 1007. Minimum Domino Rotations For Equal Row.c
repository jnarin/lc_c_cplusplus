/*
Problem: 1007. Minimum Domino Rotations For Equal Row
Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize){
    int ans = INT_MAX, i, t, topCount[7] = {0}, bottomCount[7] = {0}, sameCount[7] = {0};
    
    for (i = 0; i < topsSize; i++){
        topCount[tops[i]]++;
        bottomCount[bottoms[i]]++;
        
        sameCount[tops[i]] += (tops[i] == bottoms[i]);
    }
    
    for (i = 1; i <= 6; i++){
        if (topCount[i] + bottomCount[i] - sameCount[i] == topsSize){
            t = MINVAL(topCount[i], bottomCount[i]) - sameCount[i];
            
            ans = MINVAL(ans, t);
        }
    }
    
    return ans == INT_MAX ? -1 : ans;
}
