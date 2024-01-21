/*
Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/
Problem: 717. 1-bit and 2-bit Characters
*/

bool isOneBitCharacter(int* bits, int bitsSize){
    int i = 0;
    
    while (i < bitsSize) {
        if (i == bitsSize - 1 && bits[i] == 0) {
            return true;
        }
        
        if (bits[i] == 0) {
            i++;
        } else {
            i += 2;
        }
    }
    
    return false;

}