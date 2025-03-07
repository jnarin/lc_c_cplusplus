/*
Problem: 2523. Closest Prime Numbers in Range
Link: https://leetcode.com/problems/closest-prime-numbers-in-range/
*/

#define MAXNUMS (1000000)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestPrimes(int left, int right, int* returnSize) {
    int primes[MAXNUMS], isPrime[MAXNUMS], *result = calloc(2, sizeof(int)),
        primesCount = 0, i, j;


    for(i = 0; i < 1000000; i++) {
        isPrime[i] = 1;
    }

    isPrime[0] = 0;
    isPrime[1] = 0;

    for(i = 2; i < MAXNUMS; i++) {
        if(isPrime[i]) {
            primes[primesCount++] = i;

            for(j = i * 2; j < MAXNUMS; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    int minDiff = MAXNUMS;
    int minDiffIndex = -1;

    for(i = 0; i < primesCount - 1; i++) {
        if(primes[i] >= left && primes[i + 1] <= right) {
            if(primes[i + 1] - primes[i] < minDiff) {
                minDiff = primes[i + 1] - primes[i];
                minDiffIndex = i;
            }
        }
    }

    if(minDiffIndex == -1) {
        result[0] = -1;
        result[1] = -1;
    } else {
        result[0] = primes[minDiffIndex];
        result[1] = primes[minDiffIndex + 1];
    }

    *returnSize = 2;
    
    return result;
}
