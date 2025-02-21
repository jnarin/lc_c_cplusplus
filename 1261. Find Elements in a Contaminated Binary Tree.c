/*
Problem: 1261. Find Elements in a Contaminated Binary Tree
Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_NUMS (10000)

 typedef struct {
    struct TreeNode *root;
    int             values[MAX_NUMS];
    int             valuesSize;
 } FindElements;
 
 
static void dfs(struct TreeNode *root, int val, int *values, int *valuesSize) {
    if (root == NULL) {
        return;
    }

    root->val = val;
    values[(*valuesSize)++] = val;

    dfs(root->left, 2 * val + 1, values, valuesSize);
    dfs(root->right, 2 * val + 2, values, valuesSize);
}


 FindElements* findElementsCreate(struct TreeNode* root) {
    FindElements *obj = calloc(1, sizeof(FindElements));

    obj->root = root;
    obj->valuesSize = 0;

    dfs(obj->root, 0, obj->values, &obj->valuesSize);

    return obj;
 }
 
 bool findElementsFind(FindElements* obj, int target) {
    int i;

    for (i = 0; i < obj->valuesSize; i++) {
        if (obj->values[i] == target) {
            return true;
        }
    }
    
    return false;
 }
 
 void findElementsFree(FindElements* obj) {
    free(obj);
 }
 
 /**
  * Your FindElements struct will be instantiated and called as such:
  * FindElements* obj = findElementsCreate(root);
  * bool param_1 = findElementsFind(obj, target);
  
  * findElementsFree(obj);
 */
