/*
Problem: 1545. Find Kth Bit in Nth Binary String
Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
*/

char findKthBit(int n, int k) {
    if (n == 1) {
        return '0';
    }
    
    int length = (1 << n) - 1; // Length of the S string
    int middle = length / 2 + 1; // Position of the middle bit
    
    if (k == middle) {
        return '1'; // Middle bit is '1'
    }
    else if (k < middle) {
        return findKthBit(n - 1, k); // Recurse on the left half
    }
    else {
        return findKthBit(n - 1, length - k + 1) ^ 1; // Recurse on the right half and flip the bit
    }
}
