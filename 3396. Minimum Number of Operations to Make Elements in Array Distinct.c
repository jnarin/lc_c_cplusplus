/*
Problem: 3396. Minimum Number of Operations to Make Elements in Array Distinct
Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
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

#define MAX_NUM (101)

int minimumOperations(int* nums, int numsSize) {
    HashSet *set = hashsetCreate(MAX_NUM);
    int i;
    int ans = 0;

    for (i = numsSize - 1; i >= 0; i--) {
        if (hashsetContains(set, nums[i])) {
            ans = i / 3 + 1;
            break;
        }

        hashsetAdd(set, nums[i]);
    }
   
    hashsetFree(set);
    
    return ans;

}
