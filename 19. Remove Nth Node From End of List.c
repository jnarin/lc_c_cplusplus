/*
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Problem: 19. Remove Nth Node From End of List
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast, *slow, *prev = NULL, dummy = {0, head};

    fast = slow = head;

    while (fast && n--){
        fast = fast->next;
    }

    while (fast && slow){
        prev = slow;
        fast = fast->next;
        slow = slow->next;
    }

    if (prev){
        if (slow){
            prev->next = slow->next;
            free(slow);
        } else {
            prev->next = NULL;
        }
    } else {
        // Node to be deleted is head
        slow = head;
        dummy.next = slow->next;
        free(slow);
    }

    return dummy.next;
}
