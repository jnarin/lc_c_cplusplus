/*
Link: https://leetcode.com/problems/reverse-linked-list/
Problem: 206. Reverse Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *c, *p, *n;
    c = head;
    p = NULL;
    
    while (c) {
        n = c->next;
        c->next = p;
        
        p = c;
        c = n;
    }
    
    return p;
}