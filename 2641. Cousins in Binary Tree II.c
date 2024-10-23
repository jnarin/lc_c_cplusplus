/*
Problem: 2641. Cousins in Binary Tree II
Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int countTreeNodes(struct TreeNode* root) {
    return root ? 1 + countTreeNodes(root->left) + countTreeNodes(root->right) : 0;
}

static void getNodeSum(struct TreeNode* root, int* nodeSum, int index) {
    if (root == NULL) {
        return;
    }
 
    nodeSum[index] += root->val;
    getNodeSum(root->left, nodeSum, index + 1);
    getNodeSum(root->right, nodeSum, index + 1);
    
    return;
}

static void replaceNodes(struct TreeNode* root, int* nodeSum, int index) {
    if (root == NULL) {
        return;
    }

    int l = root->left ? root->left->val : 0, r = root->right ? root->right->val : 0;
    int diff = l + r;

    index++;
    
    if (root->left) {
        root->left->val = nodeSum[index] - diff;
        replaceNodes(root->left, nodeSum, index);
    }

    if (root->right) {
        root->right->val = nodeSum[index] - diff;
        replaceNodes(root->right, nodeSum, index);
    }
}

struct TreeNode* replaceValueInTree(struct TreeNode* root) {
    int nodeCount = countTreeNodes(root);
    int nodeSum[nodeCount];
    memset(nodeSum, 0, sizeof(nodeSum));

    getNodeSum(root, nodeSum, 0);

    root->val = 0;

    replaceNodes(root, nodeSum, 0);

    return root;
}
