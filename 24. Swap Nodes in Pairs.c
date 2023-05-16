/*
Link: https://leetcode.com/problems/swap-nodes-in-pairs/
Problem: 24. Swap Nodes in Pairs
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode dummy = {0, NULL}, *curr, *prev, *tmp, *nxt;
    
    curr = head;
    prev = nxt = tmp = NULL;
    
    while (curr){
        nxt = curr->next;
        if (nxt){
            tmp = nxt->next;
            
            dummy.next = dummy.next ? dummy.next : nxt;
            
            if (prev){
                prev->next = nxt;
            }
            
            nxt->next = curr;
            curr->next = tmp;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    
    return dummy.next ? dummy.next : head;

}