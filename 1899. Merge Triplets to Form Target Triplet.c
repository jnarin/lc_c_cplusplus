/*
Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
Problem: 1899. Merge Triplets to Form Target Triplet
Approach:
Go through the triplets array and check if we can get a solution that will 
match the target, given the constraints.
*/

bool mergeTriplets(int** triplets, int tripletsSize, int* tripletsColSize, int* target, int targetSize){
    bool t0, t1, t2;
    int i;
    int *t;
    
    t0 = t1 = t2 = false;
    
    for (i = 0; i < tripletsSize; i++){
        assert(tripletsColSize[i] == targetSize);
        t = triplets[i];
        if (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]){
            t0 = true;
        }
        
        if (t[1] == target[1] && t[0] <= target[0] && t[2] <= target[2]){
            t1 = true;
        }
        
        if (t[2] == target[2] && t[0] <= target[0] && t[1] <= target[1]){
            t2 = true;
        }
        
    }
    
    return t0 && t1 && t2;
}
