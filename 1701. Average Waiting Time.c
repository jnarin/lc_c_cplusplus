/*
Problem: 1701. Average Waiting Time
Link: https://leetcode.com/problems/average-waiting-time/
*/

#define MAXVAL(a, b) (((a) > (b)) ? (a) : (b))

double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    double wait, curr;
    
    wait = curr = (double) 0;
    
    int *c, i;
    
    for (i = 0; i < customersSize; i++) {
        c = customers[i];
        curr = MAXVAL(curr, (double)c[0]) + c[1];
        wait += curr - c[0];
    }
    
    return (double)wait/customersSize;
    
}