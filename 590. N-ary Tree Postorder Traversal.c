/*
Problem: 590. N-ary Tree Postorder Traversal
Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
*/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_NODES   (10000)
static void traverseTree(struct Node *root, int *ans, int *idx){
    int i;
    
    if (root){
        for (i = 0; i < root->numChildren; i++){
            traverseTree(root->children[i], ans, idx);
        }
        ans[*idx] = root->val;
        *idx += 1;
    }
}

int* postorder(struct Node* root, int* returnSize) {
    int *ans = calloc(MAX_NODES + 1, sizeof(int));
    
    *returnSize = 0;
    traverseTree(root, ans, returnSize);

    return ans;
}
