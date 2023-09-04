/*
Link: https://leetcode.com/problems/linked-list-cycle/
Problem: 141. Linked List Cycle
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    bool ret = false;
    fast = slow = head;
    
    while (slow && fast){
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
        if (slow == fast && slow != NULL){
            ret = true;
            break;
        }
    }
    
    return ret;
}