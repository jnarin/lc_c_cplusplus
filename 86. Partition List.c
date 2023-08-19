/*
 * Link: https://leetcode.com/problems/partition-list/
 * Problem: 86. Partition List
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
static void deleteList(struct ListNode *h){
    struct ListNode *t = h, *p;
    while (t){
        p = t;
        t = t->next;
        free(p);
    }

    return;
}

struct ListNode* partition(struct ListNode* head, int x){
    
    struct ListNode small = {0, NULL}, large = {0, NULL};
    struct ListNode *t, *n, *prev_s = NULL, *prev_l = NULL;
    
    /* Create two lists, one with values larger than x and
    another with values smaller than x */
    t = head;
    while (t){
        n = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        
        n->val = t->val;
        n->next = NULL;
        
        if (t->val < x){
            if (small.next == NULL){
                small.next = n;
            } else {
                prev_s->next = n;
            }
            
            prev_s = n;
        } else {
            if (large.next == NULL){
                large.next = n;
            } else {
                prev_l->next = n;
            }
            
            prev_l = n;
        }
        
        t = t->next;
    }
    
    /* Copy values from small list into original */
    t = head;
    n = small.next;
    while (t && n){
        t->val = n->val;
        t = t->next;
        n = n->next;
    }
    
    /* Copy values from large list into original */
    n = large.next;
    while (t && n){
        t->val = n->val;
        t = t->next;
        n = n->next;
    }
    
    /* Delete both lists */
    deleteList(small.next);
    deleteList(large.next);
    
    return head;
}
