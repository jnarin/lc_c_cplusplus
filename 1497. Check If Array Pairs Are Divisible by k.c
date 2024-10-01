/*
Problem: 1497. Check If Array Pairs Are Divisible by k
Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
*/

bool canArrange(int* arr, int arrSize, int k) {
    int count[k], i, r;
    
    memset(count, 0, sizeof(count));
    
    for (i = 0; i < arrSize; i++) {
        r = arr[i] % k;
        r += r < 0 ? k : 0;
        
        count[r]++;
    }
    
    if (count[0] & 1) {
        return false;
    }
    
    for (i = 1; i <= k / 2; i++) {
        if (count[i] != count[k - i]) {
            return false;
        }
    }
    
    return true;
}
