/*
Problem: 2029. Stone Game IX
Link: https://leetcode.com/problems/stone-game-ix/
*/

#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

bool stoneGameIX(int* stones, int stonesSize) {
    int count[3] = {0}, i;

    for (i = 0; i < stonesSize; i++) {
        count[stones[i] % 3]++;
    }

    if (count[0] & 1) {
        return abs(count[1] - count[2]) > 2;        
    }

    return MINVAL(count[1], count[2]) > 0;
}
