/*
Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
Problem: 1305. All Elements in Two Binary Search Trees
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int countNodes(struct TreeNode *root){
    if (root == NULL){
        return 0;
    }
    
    int l = countNodes(root->left), r = countNodes(root->right);
    return 1 + l  + r;
}

static void inorderTraverse(struct TreeNode *root, int *v, int *i){
    if (root == NULL){
        return;
    }
    
    inorderTraverse(root->left, v, i);
    v[*i] = root->val;
    *i = *i + 1;
    inorderTraverse(root->right, v, i);
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    assert(returnSize);
    int numT1 = countNodes(root1), numT2 = countNodes(root2);
    
    int *v1, *v2, i, j;
    v1 = v2 = NULL;
    if (numT1){
        v1 = calloc(numT1, sizeof(int));
        assert(v1);
    }
    
    if (numT2){
        v2 = calloc(numT2, sizeof(int));
        assert(v2);
    }
    
    i = 0;
    inorderTraverse(root1, v1, &i);
    i = 0;
    inorderTraverse(root2, v2, &i);
    
    int *ans = calloc(numT1 + numT2, sizeof(int)), k;
    assert(ans);
    
    *returnSize = numT1 + numT2;
    
    i = j = k = 0;
    
    while (i < numT1 && j < numT2){
        if (v1[i] <= v2[j]){
            ans[k] = v1[i++];
        } else {
            ans[k] = v2[j++];
        }
        
        k++;
    }
    
    while (i < numT1){
        ans[k++] = v1[i++];
    }
    
    while (j < numT2){
        ans[k++] = v2[j++];
    }
    
    return ans;
}