/*
Problem: 1894. Find the Student that Will Replace the Chalk
Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
*/

static long sum(int *array, int size) {
    long sum = 0, i;
    
    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    
    return sum;
}

int chalkReplacer(int* chalk, int chalkSize, int k) {
    long totalChalksNeeded = sum(chalk, chalkSize), i;
    
    k %= totalChalksNeeded;
    
    if (k == 0) {
        return 0;
    }
    
    for (i = 0; i < chalkSize; i++) {
        k -= chalk[i];
        if (k < 0) {
            break;
        }
    }
    
    return i;
}
