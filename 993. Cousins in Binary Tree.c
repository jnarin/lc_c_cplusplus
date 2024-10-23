/*
Problem: 993. Cousins in Binary Tree
Link: https://leetcode.com/problems/cousins-in-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isCousins(struct TreeNode* root, int x, int y) {
    if(root == NULL){
        return false;
    } 

    struct TreeNode *parentX = NULL, *parentY = NULL, *parent = NULL;
    int depthX = -1, depthY = -1, depth = 0;

    struct TreeNode* queue[101], *node;
    int front = 0, rear = 0;

    int i, size;

    queue[rear++] = root;

    while(front < rear) {
        size = rear - front;

        for(i = 0; i < size; i++) {
            node = queue[front++];
            if(node->left != NULL) {
                queue[rear++] = node->left;
                if(node->left->val == x) {
                    parentX = node;
                    depthX = depth + 1;
                }
                if(node->left->val == y) {
                    parentY = node;
                    depthY = depth + 1;
                }
            }

            if(node->right != NULL) {
                queue[rear++] = node->right;
                if(node->right->val == x) {
                    parentX = node;
                    depthX = depth + 1;
                }
                if(node->right->val == y) {
                    parentY = node;
                    depthY = depth + 1;
                }
            }
        }
        depth++;
    }

    return parentX != NULL && parentY != NULL && parentX != parentY && depthX == depthY;
}
