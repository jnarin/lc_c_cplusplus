/*
Problem: 2326. Spiral Matrix IV
Link: https://leetcode.com/problems/spiral-matrix-iv/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(m * sizeof(int *)), i, j,
        x = 0, y = 0, dx = 0, dy = 1, temp;
    struct ListNode *node = head;

    *returnColumnSizes = malloc(m * sizeof(int));

    for(i = 0; i < m; i++) {
        ans[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        
        memset(ans[i], 0xFF, n * sizeof(int));
    }

    while (node) {
        ans[x][y] = node->val;
        node = node->next;
        if(x + dx == m || y + dy == n 
            || x + dx < 0 || y + dy < 0 
            || ans[x + dx][y + dy] != -1) {
            temp = dx;
            dx = dy;
            dy = -temp;
        }
        x += dx;
        y += dy;
    }

    *returnSize = m;
    return ans;
}
