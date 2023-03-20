/*
Link: https://leetcode.com/problems/can-place-flowers/
Problem: 605. Can Place Flowers
Approach:
Check if there exists three consecutive empty plots.
Place a flower in the middle if exists
*/

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int count, prev, next, i;
    
    count = 0;
    
    for (i = 0; i < flowerbedSize; i++){
        prev = i > 0 ? flowerbed[i - 1] : 0;
        next = i < (flowerbedSize - 1) ? flowerbed[i + 1] : 0;
        
        if (prev == 0 && flowerbed[i] == 0 && next == 0){
            flowerbed[i] = 1;
            count++;
        }
        
        if (count >= n){
            return true;
        }
    }
    
    return false;

}