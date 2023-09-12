/*
Link: https://leetcode.com/problems/remove-letter-to-equalize-frequency/
Problem: 2423. Remove Letter To Equalize Frequency
*/

static int checkCount(int *map, int len){
    int i, t = -1;
    
    for (i = 0; i < 26; i++){
        if (map[i] == 0 || map[i] == t){
            continue;
        }

        if (t == -1){
            t = map[i];
        } else {
            return false;
        }
    }
    
    return true;
}

bool equalFrequency(char * word){
    int map[26] = {0}, i, len = strlen(word), j;
    
    for (i = 0; i < len; i++){
        map[word[i] - 'a']++;
    }
    
    for (i = 0; i < len; i++){
        map[word[i] - 'a']--;
        
        if (checkCount(map, 26) == true){
            return true;
        }
        
        map[word[i] - 'a']++;
    }
    
    return false;

}