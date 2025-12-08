/*
Problem: 1925. Count Square Sum Triples
Link: https://leetcode.com/problems/count-square-sum-triples/
*/
int countTriples(int n) {
    char *squares = calloc(n * n, sizeof(int));
    int a, b, i, ans = 0;
    
    for (i = 1; i <= n; i++) {
        squares[i * i] = 1;
    }

    for (a = 1; a <=n; a++) {
        for (b = 1; b <= n; b++) {
            ans += squares[(a * a) + (b * b)];
        }
    }

    free(squares);

    return ans;
}
