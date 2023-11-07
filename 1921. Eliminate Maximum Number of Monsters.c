/*
Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
Problem: 1921. Eliminate Maximum Number of Monsters
*/

static int incrCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
    int time[distSize], i;
    
    for (i = 0; i < distSize; i++){
        time[i] = (dist[i] - 1) / speed[i];
    }
    
    qsort(time, distSize, sizeof(int), incrCmp);
    
    for (i = 0; i < distSize; i++){
        if (i > time[i]){
            break;
        }
    }
    
    return i;
}