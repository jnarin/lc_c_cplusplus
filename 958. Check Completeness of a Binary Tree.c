/*
Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
Problem: 958. Check Completeness of a Binary Tree
Approach:
Use DFS to get total number of nodes in the tree
Perform DFS again, assign indices to each of the nodes and check if it matches where it is supposed to be
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static int getNumNodes(struct TreeNode *root){
    return root == NULL ? 0 : 1 + getNumNodes(root->left) + getNumNodes(root->right);
}

static bool checkTree(struct TreeNode *root, int idx, const int numNodes){
    if (root == NULL){
        return true;
    }
    
    if (idx > numNodes){
        return false;
    }
    
    return checkTree(root->left, idx * 2, numNodes) && checkTree(root->right, idx * 2 + 1, numNodes);
}

bool isCompleteTree(struct TreeNode* root){
    int numNodes = getNumNodes(root);
    return checkTree(root, 1, numNodes);
}
