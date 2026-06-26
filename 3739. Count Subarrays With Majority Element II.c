/*
Problem: 3739. Count Subarrays With Majority Element II
Link: https://leetcode.com/problems/count-subarrays-with-majority-element-ii
*/
typedef struct stBinaryIndexedTree {
    int n;
    int *c;
}BinaryIndexedTree;

static void createBIT(BinaryIndexedTree *obj, int n) {
    obj->n = n;
    obj->c = calloc(n + 1, sizeof(int));
}

static void updateBIT(BinaryIndexedTree *obj, int index, int delta) {
    while (index <= obj->n) {
        obj->c[index] += delta;
        index += index & -index;
    }
}

static int queryBIT(BinaryIndexedTree *obj, int index) {
    int sum = 0;
    while (index > 0) {
        sum += obj->c[index];
        index -= index & -index;
    }

    return sum;
}

void freeBIT(BinaryIndexedTree *obj) {
    free(obj->c);
    obj->c = NULL;
    obj->n = 0;
}

long long countMajoritySubarrays(int* nums, int numsSize, int target) {
    BinaryIndexedTree tree;
    createBIT(&tree, 2 * numsSize + 1);

    int s = numsSize + 1;
    updateBIT(&tree, s, 1);

    long long ans = 0;
    for (int i = 0; i < numsSize; i++) {
        s += nums[i] == target ? 1 : -1;

        ans += queryBIT(&tree, s - 1);
        updateBIT(&tree, s, 1);
    }

    freeBIT(&tree);
    return ans;
}
