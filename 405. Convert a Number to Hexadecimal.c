/*
Problem: 405. Convert a Number to Hexadecimal
Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
*/

static void reverse(char *s, int len) {
    int i;
    char t;
    
    for (i = 0; i < len / 2; i++) {
        t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
}

char* toHex(int num) {
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', 
                  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char *ans = calloc(8 + 1, sizeof(char));
    int i;
    
    if (num == 0) {
        ans[0] = hex[num];
    } else {
        for (i = 0; num && (i < 8); i++) {
            ans[i] = hex[num & 0xf];
            num >>= 4;
        }
        
        reverse(ans, i);
    }
    
    return ans;
}
