/*
Problem: 2181. Merge Nodes in Between Zeros
Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *l, *r;
    
    l = head;
    
    while (l) {
        while (l) {
            if (l->val == 0) {
                break;
            }
            
            l = l->next;
        }
        
        if (l == NULL) {
            break;
        }
        
        int sum = 0;
        
        r = l->next;
        while (r) {
            if (r->val == 0) {
                break;
            }
            
            sum += r->val;
            r->val = 0;
            r = r->next;
        }
        
        if (r == NULL) {
            break;
        }
        
        l->val = sum;
        l = r;
    }
    
    struct ListNode *p = NULL, *n = head;
    
    while (n) {
        if (n->val == 0) {
            if (p) {
                struct ListNode *t = n;
                p->next = n->next;
                n = n->next;
                free(t);
                continue;
            }
        } else {
            p = n;
        }
        
        n = n->next;
    }
    
    return head;
}
