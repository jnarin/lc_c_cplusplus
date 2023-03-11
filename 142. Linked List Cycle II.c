/* 
Link: https://leetcode.com/problems/linked-list-cycle-ii/
Problem: 142. Linked List Cycle II
Approach:
1. Two-pointer approach to determine if there is a cycle (fast and slow)
2. When cycle is detected, increment both pointers at same interval to determine solution
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *a, *b;
    a = b = head;
    while (a && a->next && b){
        a = a->next->next;
        b = b->next;
        if (a == b){
            b = head;
            while (a != b){
                a = a->next;
                b = b->next;
            }
            
            return b;
        }
    }
    return NULL;
}

