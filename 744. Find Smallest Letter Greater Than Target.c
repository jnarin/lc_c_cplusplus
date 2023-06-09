/*
Link: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
Problem: 744. Find Smallest Letter Greater Than Target
*/
char nextGreatestLetter(char* letters, int lettersSize, char target){
    int map[26] = {0}, i;
    char ans = letters[0];
    for (i = 0; i < lettersSize; i++){
        map[letters[i] - 'a']++;
    }
    
    for (i = target + 1; i <= 'z'; i++){
        if (map[i - 'a'] > 0){
            ans = i;
            break;
        }
    }
    
    return ans;

}