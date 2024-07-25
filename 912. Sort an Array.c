/*
Problem: 912. Sort an Array
Link: https://leetcode.com/problems/sort-an-array/
*/

static void merge(int *nums, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++){
        L[i] = nums[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = nums[m + 1 + j];
    }

    i = j = 0;
    k = l;

    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        nums[k++] = L[i++];
    }

    while (j < n2){
        nums[k++] = R[j++];
    }

}
static void mergeSort(int *nums, int l, int r){
    int m = (l & r) + ((l ^ r) >> 1);
    if (l < r){

        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);

        merge(nums, l, m, r);

    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    int l = 0, r = numsSize - 1;

    *returnSize = numsSize;

    mergeSort(nums, l, r);

    return nums;

}
