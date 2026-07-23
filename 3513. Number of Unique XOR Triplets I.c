/*
Problem: 3513. Number of Unique XOR Triplets I
Link: https://leetcode.com/problems/number-of-unique-xor-triplets-i/
*/
int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize < 3) {
        return numsSize;
    }

    int ans = 1;

    while (ans <= numsSize) {
        ans <<= 1;
    }

    return ans;
}
