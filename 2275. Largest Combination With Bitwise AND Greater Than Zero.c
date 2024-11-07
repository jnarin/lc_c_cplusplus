/*
Problem: 2275. Largest Combination With Bitwise AND Greater Than Zero
Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
*/

int largestCombination(int* candidates, int candidatesSize) {
    int i, j, ans, count;
    
    ans = count = 0;
    for (i = 0; i < 31; i++) {
        count = 0;

        for (j = 0; j < candidatesSize; j++) {
            if (candidates[j] & (1 << i)) {
                count++;
            }
        }

        ans = count > ans ? count : ans;
    }
    
    return ans;
}
