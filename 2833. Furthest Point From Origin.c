/*
Problem: 2833. Furthest Point From Origin
Link: https://leetcode.com/problems/furthest-point-from-origin/
*/

int furthestDistanceFromOrigin(char* moves) {
    int lCount, rCount, uCount;
    lCount = rCount = uCount = 0;

    while (*moves) {
        switch (*moves) {
            case 'L':
                lCount++;
                break;
            case 'R':
                rCount++;
                break;
            case '_':
                uCount++;
                break;
        }

        moves++;
    }

    return abs(lCount - rCount) + uCount;
    
}
