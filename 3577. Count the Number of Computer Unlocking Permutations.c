/*
Problem: 3577. Count the Number of Computer Unlocking Permutations
Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
*/
int countPermutations(int* complexity, int complexitySize) {
    const int mod = 1e9 + 7;
    long ans = 1;
    int i;

    for (i = 1; i < complexitySize; i++) {
        if (complexity[i] <= complexity[0]) {
            return 0;
        }
    }

    for (i = 2; i < complexitySize; i++) {
        ans = (ans * i) % mod;
    }
    
    return (int)ans;
}
