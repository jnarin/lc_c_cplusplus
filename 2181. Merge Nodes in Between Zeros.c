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

static int countNodes(struct ListNode *head) {
    struct ListNode *n = head;
    int c = 0;
    
    while (n) {
        c++;
        n = n->next;
    }
    
    return c;
}

static void lToA(struct ListNode *head, int *t) {
    struct ListNode *n = head;
    int idx = 0;
    
    while (n) {
        t[idx++] = n->val;
        n = n->next;
    }
}

static int getSum(int *t, int l, int r) {
    int sum = 0, i;
    
    for (i = l; i < r; i++) {
        sum += t[i];
    }
    
    return sum;
}

struct ListNode* mergeNodes(struct ListNode* head) {
    int count = countNodes(head);
    int t[count];
    memset(t, 0, sizeof(t));
    
    lToA(head, t);
    
    int l = 0, r = 0, i;
    
    while (l < count && r < count) {
        while (l < count) {
            if (t[l] == 0) {
                break;
            }
            
            l++;
        }
        
        r = l + 1;
        while (r < count) {
            if (t[r] == 0) {
                break;
            }
            
            r++;
        }
        
        int sum = getSum(t, l, r);
        t[l] = sum;
        
        for (i = l + 1; i < r && i < count; i++) {
            t[i] = 0;
        }
         
        l =  r;
    }
    
    
    struct ListNode *n = head, *p = NULL;
    for (i = 0; i < count; i++) {
        if (t[i] == 0) {
            continue;
        }
        
        p = n;
        n->val = t[i];
        n = n->next;
    }
    
    
    if (p) {
        p->next = NULL;
    }
    
    while (n) {
        p = n->next;
        free(n);
        n = p;
    }
    
    return head;
}