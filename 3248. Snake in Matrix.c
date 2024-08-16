/*
Problem: 3248. Snake in Matrix
Link: https://leetcode.com/problems/snake-in-matrix/
*/

int finalPositionOfSnake(int n, char** commands, int commandsSize) {
    int matrix[n][n], i, j, v = 0, r, c;
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = v++;
        }
    }
    
    r = c = 0;
    for (i = 0; i < commandsSize; i++) {
        switch(commands[i][0]) {
            case 'U':
                r--;
                break;
            case 'R':
                c++;
                break;
            case 'D':
                r++;
                break;
            case 'L':
                c--;
                break;
            default:
                assert(0);
        }
    }
    
    return matrix[r][c];
}
