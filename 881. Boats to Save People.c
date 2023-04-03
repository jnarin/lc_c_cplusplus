/*
Link: https://leetcode.com/problems/boats-to-save-people/
Problem: 881. Boats to Save People
Approach: Use binary search
*/
static int incr_sort(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int numRescueBoats(int* people, int peopleSize, int limit){
    int l = 0, r = peopleSize - 1, ret = 0;
    assert(people);
    
    qsort(people, peopleSize, sizeof(int), incr_sort);
    
    while (l <= r){
        if (people[l] + people[r] <= limit){
            l++;
            r--;
        } else {
            r--;
        }
        
        ret++;
    }
    
    return ret;
}