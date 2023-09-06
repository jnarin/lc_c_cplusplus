/*
Link: https://leetcode.com/problems/split-linked-list-in-parts/
Problem: 725. Split Linked List in Parts
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int getListLen(struct ListNode *head){
    int ans = 0;
    struct ListNode *t = head;
    
    while (t){
        ans++;
        t = t->next;
    }
    
    return ans;
}

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    struct ListNode **ans = calloc(k, sizeof(struct ListNode *));
    *returnSize = k;
    int len = getListLen(head);
    int subLen = len / k;
    int rem = len % k;
    int i, j;
    
    struct ListNode * p = NULL, *t = head;
    
    for (i = 0; i < k; i++){
        ans[i] = t;
        
        for (j = 0; j < subLen + (rem > 0); j++){
            p = t;
            t = t->next;
        }
        
        rem = rem > 0 ? rem - 1 : 0;
        
        if (p){
            p->next = NULL;
        }
    }
    
    return ans;
}