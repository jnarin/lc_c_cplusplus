/*
Problem: 1106. Parsing A Boolean Expression
Link: https://leetcode.com/problems/parsing-a-boolean-expression/
*/

static bool parse(char *exp, int *i) {
    bool ans, isAnd;

    if (exp[*i] == 't') {
        *i += 1;
        return true;
    } 
    
    if (exp[*i] == 'f') {
        *i += 1;
        return false;
    }
    
    if (exp[*i] == '!') {
        *i += 2;
        ans = !parse(exp, i);
        *i += 1;

        return ans;
    }
    
    isAnd = exp[*i] == '&';
    ans = isAnd;

    *i += 2;

    while (exp[*i] != ')') {
        bool parsed = parse(exp, i);
        if (isAnd) {
            ans &= parsed;
        } else {
            ans |= parsed;
        }

        if (exp[*i] == ',') {
            *i += 1;
        }
    }

    *i += 1;
    return ans;
}

bool parseBoolExpr(char* expression) {
    int i = 0;

    return parse(expression, &i);
}
