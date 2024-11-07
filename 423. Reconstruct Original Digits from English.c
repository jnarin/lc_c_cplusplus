/*
Problem: 423. Reconstruct Original Digits from English
Link: https://leetcode.com/problems/reconstruct-original-digits-from-english/
*/

char* originalDigits(char* s) {
    int count[26] = {0}, num[10] = {0};
    
    while (*s) {
        count[*s - 'a']++;
        s++;
    }

    num[0] = count['z' - 'a'];
    num[2] = count['w' - 'a'];
    num[4] = count['u' - 'a'];
    num[6] = count['x' - 'a'];
    num[8] = count['g' - 'a'];
    num[3] = count['h' - 'a'] - num[8];
    num[5] = count['f' - 'a'] - num[4];
    num[7] = count['s' - 'a'] - num[6];
    num[9] = count['i' - 'a'] - num[5] - num[6] - num[8];
    num[1] = count['n' - 'a'] - num[7] - 2 * num[9];

    char* result = malloc(100000);
    int index = 0, i, j;

    for(i = 0; i < 10; i++) {
        for(j = 0; j < num[i]; j++) {
            result[index++] = i + '0';
        }
    }
    result[index] = '\0';

    return result;
}
