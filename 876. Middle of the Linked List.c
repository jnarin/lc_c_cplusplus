/*
Link: https://leetcode.com/problems/middle-of-the-linked-list/
Problem: 876. Middle of the Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow, *fast;
    slow = fast = head;
    
    while (slow && fast) {
        if (fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            break;
        }
    }
    
    return slow;
}