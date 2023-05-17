/*
Link: https://leetcode.com/problems/pass-the-pillow/
Problem: 2582. Pass the Pillow
*/
typedef enum{
    e_back      = -1,
    e_forward   = 1,
}dir_e;

int passThePillow(int n, int time){
    dir_e direction = e_forward;
    int i = 1;
    
    while (time){
        switch (direction){
            case e_forward:
                i++;
                break;
            case e_back:
                i--;
                break;
        }
        
        if (i >= n){
            direction = e_back;
            i = n;
        } else if (i <= 1){
            direction = e_forward;
            i = 1;
        }
        
        time--;
    }
    
    
   
    return i;

}