/*
 * Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/
 * Problem: 2141. Maximum Running Time of N Computers
 * */

static long long arraySum(int *arr, int size){
    long long sum = 0;
    int i;

    for (i = 0; i < size; i++){
        sum += arr[i];
    }

    return sum;
}

static int incr_cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

long long maxRunTime(int n, int* batteries, int batteriesSize){
    long long sum = arraySum(batteries, batteriesSize);
    int i = batteriesSize - 1;

    qsort(batteries, batteriesSize, sizeof(int), incr_cmp);

    while (i >= 0 && batteries[i] > (sum / n)){
        sum -= batteries[i];
        i--;
        n--;
    }

    return sum / n;
}
