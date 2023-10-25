/*
 * Link: https://leetcode.com/problems/k-th-symbol-in-grammar/
 * Problem: 779. K-th Symbol in Grammar
 * */
int kthGrammar(int n, int k){
    if (n == 1 && k == 1){
        return 0;
    }

    return (k & 1)
        ? kthGrammar(n - 1, (k + 1) >> 1)
        : !kthGrammar(n - 1, k >> 1);
}
