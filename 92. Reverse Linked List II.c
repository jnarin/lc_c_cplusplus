/*
Link: https://leetcode.com/problems/reverse-linked-list-ii/
Problem: 92. Reverse Linked List II
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode d = {0, head}, *p = &d, *c, *t;
    int i = 0;
    
    while (i++ < left - 1){
        p = p->next;
    }
    
    c = p->next;
    
    i = 0;
    while (i++ < right - left){
        t = p->next;
        p->next = c->next;
        c->next = c->next->next;
        p->next->next = t;
    }
    
    return d.next;
}