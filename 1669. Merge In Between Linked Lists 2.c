/*
Link: https://leetcode.com/problems/merge-in-between-linked-lists/
Problem: 1669. Merge In Between Linked Lists
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *ans = calloc(1, sizeof(struct ListNode)), *p, *node;
    
    ans->val = list1->val;
    ans->next = NULL;
    p = ans;
    list1 = list1->next;
    
    int i;
    
    // Copy 'a' nodes from list1
    for (i = 1; (i < a) && list1 ; i++) {
        node = calloc(1, sizeof(struct ListNode));
        node->val = list1->val;
        node->next = NULL;
        
        p->next = node;
        p = node;
        
        list1 = list1->next;
    }
    

    // Copy list2
    while (list2) {
        node = calloc(1, sizeof(struct ListNode));
        node->val = list2->val;
        node->next = NULL;
        
        p->next = node;
        p = node;
        
        list2 = list2->next;
    }
    
    // Skip 'b' nodes from list1
    int skipCount = b - a + 1;
    while (list1 && skipCount--) {
        list1 = list1->next;
    }
    
    // Copy remaining nodes from list1
    while (list1) {
        node = calloc(1, sizeof(struct ListNode));
        node->val = list1->val;
        node->next = NULL;
        
        p->next = node;
        p = node;
        
        list1 = list1->next;
    }
    
    return ans;
}