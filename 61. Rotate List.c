/*
Problem: 61. Rotate List
Link: https://leetcode.com/problems/rotate-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode *t, *p = NULL;
    int c = 1;


    if (k == 0 || head == NULL || head->next == NULL){
        return head;
    }

    assert(head);

    t = head;
    while (t && t->next){
        t = t->next;
        c++;
    }

    if (k % c == 0){
        return head;
    }

    assert(c);
    assert(t->next == NULL);

    t->next = head;

    k = k > c ? k % c : k;
    k = c - k;


    t = head;
    while (t && k--){
        p = t;
        t = t->next;
    }

    if (p){
        p->next = NULL;
    }

    return t;
}
