/*
Problem: 657. Robot Return to Origin
Link: https://leetcode.com/problems/robot-return-to-origin/
*/

bool judgeCircle(char* moves) {
    typedef enum {
        DIR_UP      = 0,
        DIR_DOWN,
        DIR_LEFT,
        DIR_RIGHT
    } directions_e;

    int dirs[4] = {0};

    while (*moves) {
        switch (*moves) {
            case 'U':
                dirs[DIR_UP]++;
                break;
            case 'D':
                dirs[DIR_DOWN]++;
                break;
            case 'L':
                dirs[DIR_LEFT]++;
                break;
            case 'R':
                dirs[DIR_RIGHT]++;
                break;
            default:
                assert(0);
        }

        moves++;
    }
    
    return dirs[DIR_UP] == dirs[DIR_DOWN] && dirs[DIR_LEFT] == dirs[DIR_RIGHT] 
        ? true : false;
}
