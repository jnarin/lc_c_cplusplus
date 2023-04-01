/*
Link: https://leetcode.com/problems/reducing-dishes/
Problem: 1402. Reducing Dishes
*/

static int decr_sort(const void *a, const void * b){
    return *(int *)b - *(int *)a;
}

int maxSatisfaction(int* satisfaction, int satisfactionSize){
    int ans, sum, i;
    
    ans = sum = 0;
    
    qsort(satisfaction, satisfactionSize, sizeof(int), decr_sort);
    
    for (i = 0; i < satisfactionSize; i++){
        sum += satisfaction[i];
        if (sum <= 0){
            return ans;
        }
        
        ans += sum;
    }
    
    return ans;
}