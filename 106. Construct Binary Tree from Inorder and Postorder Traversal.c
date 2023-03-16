/*
Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Problem: 106. Construct Binary Tree from Inorder and Postorder Traversal
Approach: 
Use the property of inorder & postorder traversal
That is, last element in postorder array is the root.
Locate index of root in inorder array
Recursively reconstruct the tree by locating the range for left and right sub-trees.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static int getIdx(const int *a, const int a_size, const int val){
    int i;
    
    for (i = 0; i < a_size; i++){
        if (a[i] == val){
            return i;
        }
    }
    
    assert(0);
    return -1;
}

static struct TreeNode *convert(const int *inorder, const int inorder_size, const int in_start, const int in_end, const int *postorder, const int post_start, const int post_end){
    if (in_start > in_end){
        return NULL;
    }
    
    int val = postorder[post_end], idx = getIdx(inorder, inorder_size, val), left = idx - in_start;
    
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    root->val = val;
    root->left = convert(inorder, inorder_size, in_start, idx - 1, postorder, post_start, post_start + left - 1);
    root->right = convert(inorder, inorder_size, idx + 1, in_end, postorder, post_start + left, post_end - 1);
    
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    return convert(inorder, inorderSize, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
}
