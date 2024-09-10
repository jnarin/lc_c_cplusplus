/*
Problem: 2807. Insert Greatest Common Divisors in Linked List
Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int gcd(int a, int b) {
    if (a < b) {
        return gcd(b, a);
    }
    
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    struct ListNode *current = head, *newNode;
    int g;
    
    while(current != NULL && current->next != NULL){
        g = gcd(current->val, current->next->val);
        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        newNode->val = g;
        newNode->next = current->next;
        
        current->next = newNode;
        current = newNode->next;
    }
    return head;

}
