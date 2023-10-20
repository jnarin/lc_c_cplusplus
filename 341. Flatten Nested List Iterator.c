/*
Link: https://leetcode.com/problems/flatten-nested-list-iterator/
Problem: 341. Flatten Nested List Iterator
*/
/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

#define MAX_LEN (500)

struct NestedIterator {
    int *arr, idx, size;
};

static void flatten(struct NestedInteger *nestedList, struct NestedIterator *iter){
    if (NestedIntegerIsInteger(nestedList)){
        if (iter->size % MAX_LEN == 0){
            iter->arr = realloc(iter->arr, sizeof(int) * (iter->size + MAX_LEN));
        }
        
        iter->arr[iter->size++] = NestedIntegerGetInteger(nestedList);
    } else {
        int nestedListSize = NestedIntegerGetListSize(nestedList), i;
        struct NestedInteger **t = NestedIntegerGetList(nestedList);
        
        for (i = 0; i < nestedListSize; i++){
            flatten(t[i], iter);
        }    
    }
}

struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) {
    struct NestedIterator *iter = calloc(1, sizeof(struct NestedIterator));
    iter->arr = calloc(MAX_LEN, sizeof(int));
    
    int i;
    
    iter->idx = iter->size = 0;
    for (i = 0; i < nestedListSize; i++){
        flatten(nestedList[i], iter);
    }
    
    return iter;
}

bool nestedIterHasNext(struct NestedIterator *iter) {
    return iter->idx < iter->size;
}

int nestedIterNext(struct NestedIterator *iter) {
    return iter->arr[iter->idx++];
}

/** Deallocates memory previously allocated for the iterator */
void nestedIterFree(struct NestedIterator *iter) {
    free(iter->arr);
    free(iter);
}

/**
 * Your NestedIterator will be called like this:
 * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize);
 * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i));
 * nestedIterFree(i);
 */