/*
Link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
Problem: 1502. Can Make Arithmetic Progression From Sequence
*/
static int incr_cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    int diff, i;
    
    qsort(arr, arrSize, sizeof(int), incr_cmp);
    
    diff = arr[1] - arr[0];
    
    for (i = 2; i < arrSize; i++){
        if (diff != arr[i] - arr[i - 1]){
            return false;
        }
    }
    
    return true;

}