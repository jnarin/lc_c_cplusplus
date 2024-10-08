/*
Problem: 1963. Minimum Number of Swaps to Make the String Balanced
Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
*/

int minSwaps(char* s) {
    int count = 0;
    
    while (*s) {
        if (*s == '[') {
            count++;
        } else if (count > 0) {
            count--;
        }
        
        s++;
    }
    
    return (count + 1) / 2;
}
