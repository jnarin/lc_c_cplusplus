/*
Problem: 3074. Apple Redistribution into Boxes
Link: https://leetcode.com/problems/apple-redistribution-into-boxes/
*/

static int decrCmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

static int arrayIntSum(int *nums, int numsSize) {
    int sum = 0, i;

    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    return sum;
}

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int totalApples = arrayIntSum(apple, appleSize), totalCapacity = 0, i;

    qsort(capacity, capacitySize, sizeof(int), decrCmp);

    for (i = 0; i < capacitySize; i++) {
        totalCapacity += capacity[i];
        if (totalCapacity >= totalApples) {
            return i + 1;
        }
    }
    
    return capacitySize;
}
