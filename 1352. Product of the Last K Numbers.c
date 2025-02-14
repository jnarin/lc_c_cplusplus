/*
Problem: 1352. Product of the Last K Numbers
Link: https://leetcode.com/problems/product-of-the-last-k-numbers/
*/

#define MAX_NUMS    ((4 * 10000) + 1)

typedef struct {
    int *v, idx;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = calloc(1, sizeof(ProductOfNumbers));
    obj->v = calloc(MAX_NUMS, sizeof(int));
    obj->idx = 0;

    obj->v[obj->idx++] = 1;

    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->idx = 0;
        obj->v[obj->idx++] = 1;

        return;
    }

    obj->v[obj->idx] = num * obj->v[obj->idx - 1];
    obj->idx++;

    return;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (obj->idx <= k) {
        return 0;
    } else {
        return obj->v[obj->idx - 1] / obj->v[obj->idx - 1 - k];
    }
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->v);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/
