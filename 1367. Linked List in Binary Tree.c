/*
Problem: 1367. Linked List in Binary Tree
Link: https://leetcode.com/problems/linked-list-in-binary-tree/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static bool isSubPathHelper(struct ListNode *head, struct TreeNode *root) {
    if (head == NULL) {
        return true;
    }
    
    if (root == NULL) {
        return false;
    }
    
    return (head->val == root->val) && (isSubPathHelper(head->next, root->left) || isSubPathHelper(head->next, root->right));
}

bool isSubPath(struct ListNode* head, struct TreeNode* root) {
    if (root == NULL) {
        return false;
    }
    
    return isSubPathHelper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}
