/*
Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
Problem: 108. Convert Sorted Array to Binary Search Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MIDVAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

static struct TreeNode *createBSTfromSortedArray(int *nums, int l, int r){
    if (l > r){
        return NULL;
    }
    
    int mid = MIDVAL(l, r);
    
    struct TreeNode *node = calloc(1, sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = createBSTfromSortedArray(nums, l, mid - 1);
    node->right = createBSTfromSortedArray(nums, mid + 1, r);
    
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return createBSTfromSortedArray(nums, 0, numsSize - 1);
}