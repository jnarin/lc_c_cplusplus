/*
Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
Problem: 530. Minimum Absolute Difference in BST
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
#define MIN_VAL(a, b) \
    ({  __typeof__(a) _a = (a);\
        __typeof__(b) _b = (b);\
        _a < _b ? _a : _b; })

#define MAX_NODE_NUM    (10001)

static void inorderTraverse(struct TreeNode *root, int *arrT, int *idx){
    if (root == NULL){
        return;
    }

    inorderTraverse(root->left, arrT, idx);
    arrT[*idx] = root->val;
    *idx = *idx + 1;
    inorderTraverse(root->right, arrT, idx);
}

static int minDifference(int *arrT, int size){
    int i;
    int t = INT_MAX;

    for (i = 1; i < size; i++){
        t = MIN_VAL(t, arrT[i] - arrT[i - 1]);
    }

    return t;
}

int getMinimumDifference(struct TreeNode* root){
    int *arrT = calloc(MAX_NODE_NUM, sizeof(int));
    int i = 0;
    int ans = INT_MAX;

    inorderTraverse(root, &arrT[i], &i);

    ans = minDifference(arrT, i);
    
    free(arrT);

    return ans;
}