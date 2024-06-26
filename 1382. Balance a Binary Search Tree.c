/*
Problem: 1382. Balance a Binary Search Tree
Link: https://leetcode.com/problems/balance-a-binary-search-tree/
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

static void countNodes(struct TreeNode *root, int *numNodes) {
    if (root) {
        *numNodes += 1;
        countNodes(root->left, numNodes);
        countNodes(root->right, numNodes);
    }
}

static void convertTreeToArray(struct TreeNode *root, int *nums, int *idx) {
    if (root) {
        convertTreeToArray(root->left, nums, idx);
        nums[*idx] = root->val;
        *idx += 1;
        convertTreeToArray(root->right, nums, idx);
    }
}

static struct TreeNode *createBSTfromSortedArray(int *nums, int l, int r) {
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

struct TreeNode* balanceBST(struct TreeNode* root) {
    int numNodes = 0;
    countNodes(root, &numNodes);
    
    int nums[numNodes], idx = 0;
    memset(nums, 0, sizeof(nums));
    
    convertTreeToArray(root, nums, &idx);
    
    return createBSTfromSortedArray(nums, 0, numNodes - 1);
}