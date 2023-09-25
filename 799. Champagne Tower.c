/*
Link: https://leetcode.com/problems/champagne-tower/
Problem: 799. Champagne Tower
*/

double champagneTower(int poured, int query_row, int query_glass){
    double d[102][102] = {0}, flow;
    int i, j;
    
    d[0][0] = poured;
    
    for (i = 0; i < query_row; i++){
        for (j = 0; j <= i; j++){
            flow = (d[i][j] - 1)/2.0;
            if (flow > 0){
                d[i + 1][j] += flow;
                d[i + 1][j + 1] += flow;
            }
        }
    }
    
    return 1 < d[query_row][query_glass] ? 1 : d[query_row][query_glass];
}