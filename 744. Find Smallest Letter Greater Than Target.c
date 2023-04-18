/*
Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
Problem: 744. Find Smallest Letter Greater Than Target
*/

char nextGreatestLetter(char* letters, int lettersSize, char target){
    assert(letters);
    
    int i;
    char ans = letters[0];
    
    for (i = 0; i < lettersSize; i++){
        if (letters[i] > target){
            ans = letters[i];
            break;
        }
    }
    
    return ans;
}