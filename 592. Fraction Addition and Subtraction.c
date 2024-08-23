/*
Problem: 592. Fraction Addition and Subtraction
Link: https://leetcode.com/problems/fraction-addition-and-subtraction/
*/
static int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

char* fractionAddition(char* expression) {
    int n = strlen(expression);
    int num = 0, den = 1;
    int i = 0;
    
    while(i < n) {

        int sign = 1;
        if(expression[i] == '-') {
            sign = -1;
            i++;
        } else if(expression[i] == '+') {
            i++;
        }

        int num2 = 0;
        while(expression[i] != '/') {
            num2 = num2 * 10 + expression[i] - '0';
            i++;
        }

        i++;
        int den2 = 0;
        while(i < n && expression[i] >= '0' && expression[i] <= '9') {
            den2 = den2 * 10 + expression[i] - '0';
            i++;
        }

        num = num * den2 + sign * num2 * den;
        den = den * den2;
        int g = gcd(abs(num), den);
        num /= g;
        den /= g;
    }
    
    char* result = calloc(100, sizeof(char));
    sprintf(result, "%d/%d", num, den);
    return result;
    
}
