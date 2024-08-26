/*
Problem: 2413. Smallest Even Multiple
Link: https://leetcode.com/problems/smallest-even-multiple/
*/

int smallestEvenMultiple(int n) {
    return (n & 1) == 0 ? n : n << 1;
}
