/*
Problem: 1028. Recover a Tree From Preorder Traversal
Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recoverFromPreorder(char* traversal) {
    struct TreeNode* stack[1000];
    int stackDepth = 0;
    int val = 0;
    int depth = 0;
    int i = 0;

    while(traversal[i] != '\0') {
        if(traversal[i] == '-') {
            depth++;
            i++;
        } else {
            val = 0;

            while(traversal[i] != '-' && traversal[i] != '\0') {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            struct TreeNode* node = calloc(1, sizeof(struct TreeNode));
            node->val = val;
            node->left = NULL;
            node->right = NULL;

            if(stackDepth == 0) {
                stack[stackDepth++] = node;
            } else {
                while(stackDepth > depth) {
                    stackDepth--;
                }

                if(stack[stackDepth - 1]->left == NULL) {
                    stack[stackDepth - 1]->left = node;
                } else {
                    stack[stackDepth - 1]->right = node;
                }

                stack[stackDepth++] = node;
            }
            
            depth = 0;
        }
    }

    return stack[0];
}
