/*
Problem: 8. String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/
*/

int myAtoi(char* s) {
    int i = 0;
    int s_len = strlen(s);
    int r = 0;
    bool sign = false;

    /* Trim leading spaces */
    while (i < s_len && s[i] == ' ') i++;

    if (i >= s_len){
        return r;
    }

    /* Check sign */
    if (s[i] == '-'){
        sign = true;
        i++;
    } else if (s[i] == '+'){
        i++;
    }

    for(; i < s_len; i++){
        char c = s[i];

        if (c == '.'){
            return sign ? (-1 * r) : r;
        }

        if (c >= '0' && c<= '9'){
            /* Check bounds */
            if (sign){
                if (((-1 * r) == INT_MIN/10) && (c > '7') || (-1 * r) < INT_MIN/10){
                    return INT_MIN;
                }
            } else {
                if ((r == INT_MAX/10) && (c > '6') || r > INT_MAX/10){
                    return INT_MAX;
                }
            }

            r = (r * 10) + (c - '0');
        } else {
            return sign ? (-1 * r) : r;
        }
    }

    return sign ? (-1 * r) : r;
}
