/*
Link: https://leetcode.com/problems/check-if-it-is-a-straight-line/
Problem: 1232. Check If It Is a Straight Line
*/
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    
    /* y = (m * x) + c, m is the slope */
    int dx, dy, i, x0, y0;
    
    x0 = coordinates[0][0];
    y0 = coordinates[0][1];
        
    dx = coordinates[1][0] - x0;
    dy = coordinates[1][1] - y0;
    
    for (i = 2; i < coordinatesSize; i++){
        if ((coordinates[i][0] - x0) * dy != (coordinates[i][1] - y0) * dx){
            return false;
        }
    }
    
    return true;

}