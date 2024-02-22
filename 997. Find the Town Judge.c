/*
Link: https://leetcode.com/problems/find-the-town-judge/
Problem: 997. Find the Town Judge
*/

#define MAX_PEOPLE_NUM  (1001)

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int inTrust[MAX_PEOPLE_NUM] = {0}, outTrust[MAX_PEOPLE_NUM] = {0};
    int i;
    
    for (i = 0; i < trustSize; i++) {
        outTrust[trust[i][0]]++;
        inTrust[trust[i][1]]++;
    }
    
    for (i = 1; i <= n; i++) {
        if (inTrust[i] == n - 1 && outTrust[i] == 0) {
            return i;
        }
    }
    
    return -1;
}