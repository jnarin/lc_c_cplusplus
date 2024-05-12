/*
 * Problem: 237. Delete Node in a Linked List
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node == NULL || node->next == NULL){
        return;
    }

    struct ListNode *t = node->next;
    node->val = t->val;
    node->next = t->next;

    free(t);

    return;
}
