/*
Link: https://leetcode.com/problems/palindrome-linked-list/
Problem: 234. Palindrome Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


static struct ListNode *reverseList(struct ListNode *head){
    struct ListNode *p, *n, *c;
    p = n = NULL;
    c = head;
    
    while (c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    
    return p;
}

bool isPalindrome(struct ListNode* head){
    struct ListNode *slow, *fast;
    
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    /* Traverse to mid of list */
    slow = fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    /* Reverse list starting from mid till end */
    slow->next = reverseList(slow->next);
    slow = slow->next;
    
    /* Check if values for both halves are same */
    while (slow) {
        if (head->val != slow->val) {
            return false;
        }
        
        head = head->next;
        slow = slow->next;
    }
    
    return true;
}