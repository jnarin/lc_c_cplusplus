/*
Link: https://leetcode.com/problems/last-stone-weight/
Problem: 1046. Last Stone Weight
*/

static int incr_cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}


int lastStoneWeight(int* stones, int stonesSize){
    int last_index = stonesSize - 1, r;
    
    while (last_index >= 0){
        qsort(stones, stonesSize, sizeof(int), incr_cmp);
        
        r = stones[last_index--];
        if (last_index >= 0){
            r -= stones[last_index];
            stones[last_index] = r;
        } else {
            break;
        }
    }
    
    return r;
}