/*
Problem: 3375. Minimum Operations to Make Array Values Equal to K
Link: https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
*/


typedef struct HashSet {
    int *table;
    int size;
} HashSet;

static HashSet *hashsetCreate(int size) {
    HashSet *set = (HashSet *)malloc(sizeof(HashSet));
    set->table = (int *)calloc(size, sizeof(int));
    set->size = size;
    return set;
}

static void hashsetFree(HashSet *set) {
    free(set->table);
    free(set);
}

static int hashsetAdd(HashSet *set, int key) {
    int index = key % set->size;
    while (set->table[index] != 0) {
        if (set->table[index] == key) {
            return 0; // Already exists
        }
        index = (index + 1) % set->size;
    }
    set->table[index] = key;
    return 1; // Added successfully
}

static int hashsetContains(HashSet *set, int key) {
    int index = key % set->size;
    while (set->table[index] != 0) {
        if (set->table[index] == key) {
            return 1; // Exists
        }
        index = (index + 1) % set->size;
    }
    return 0; // Not found
}

static int hashsetSize(HashSet *set) {
    int count = 0, i;
    for (i = 0; i < set->size; i++) {
        if (set->table[i] != 0) {
            count++;
        }
    }

    return count;
}

#define MAX_NUM (101)

static int minArray(int *nums, int numsSize) {
    int min = nums[0], i;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    return min;
}

int minOperations(int* nums, int numsSize, int k) {
    HashSet *set = hashsetCreate(MAX_NUM);
    int i, ans;

    for (i = 0; i < numsSize; i++) {
        hashsetAdd(set, nums[i]);
    }

    int min = minArray(nums, numsSize);

    if (min < k) {
        ans = -1; // Impossible to make all elements equal to k
        goto exit;
    }

    if (min > k) {
        ans = hashsetSize(set); 
        goto exit;
    }

    ans = hashsetSize(set) - 1;

exit:

    hashsetFree(set);
    return ans;


}
