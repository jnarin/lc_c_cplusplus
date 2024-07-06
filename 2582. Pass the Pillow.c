/*
Link: https://leetcode.com/problems/pass-the-pillow/
Problem: 2582. Pass the Pillow
*/
int passThePillow(int n, int time){
    int incr = 1, i = 1;
    
    while (time) {
        i += incr;
        
        if (i >= n) {
            incr = -1;
        } else if (i <= 1) {
            incr = 1;
            i = 1;
        }
        
        time--;
    }

    return i;
}
