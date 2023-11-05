/*
 * Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
 * Problem: 1503. Last Moment Before All Ants Fall Out of a Plank
 * */

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

static int getMax(int *array, int arraySize){
    int ans = INT_MIN, i;

    for (i = 0; i < arraySize; i++){
        ans = MAX(ans, array[i]);
    }

    return ans;
}

static int getMin(int *array, int arraySize){
    int ans = INT_MAX, i;

    for (i = 0; i < arraySize; i++){
        ans = MIN(ans, array[i]);
    }

    return ans;
}

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) {
    int maxLeft = leftSize > 0 ? getMax(left, leftSize) : 0,
        maxRight = rightSize > 0 ? getMin(right, rightSize) : n;

    return MAX(maxLeft, n - maxRight);
}
