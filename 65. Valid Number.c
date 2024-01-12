/*
 *  Link: https://leetcode.com/problems/valid-number/
 *  Problem: 65. Valid Number
 * */

static void ltrim(char *s, int len, int *i) {
    while (*i < len && isspace(s[*i])) {
        (*i)++;
    }
}

bool isNumber(char * s){
    int len = strlen(s), i;
    char dot, e, num;

    i = 0;
    ltrim(s, len, &i);
    if (i >= len) {
        return false;
    }

    dot = e = num = 0;
    for (; i < len; i++) {
        switch (s[i]) {
            case '.':
                if (dot || e) {
                    return false;
                }
                dot = 1;
                break;

            case 'e':
            case 'E':
                if (e || !num) {
                    return false;
                }

                e = 1;
                num = 0;
                break;

            case '+':
            case '-':
                if (i && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }

                num = 0;
                break;
            default:
                if (s[i] < '0' || s[i] > '9') {
                    return false;
                }
                
                num = 1;
                break;
        }
    }

    return num > 0;
}    
    
