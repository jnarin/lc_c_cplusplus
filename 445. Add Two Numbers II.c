/*
Link: https://leetcode.com/problems/add-two-numbers-ii/
Problem: 445. Add Two Numbers II
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX_NUM_NODES   (101)

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *t;
    int l1_arr[MAX_NUM_NODES] = {0}, l1_idx = 0;
    int l2_arr[MAX_NUM_NODES] = {0}, l2_idx = 0;
    int sum_arr[MAX_NUM_NODES] = {0}, sum_idx = 0;
    int c = 0, tmp;
    int i;
    
    t = l1;
    while (t){
        l1_arr[l1_idx++] = t->val;
        t = t->next;
    }
    
    t = l2;
    while (t){
        l2_arr[l2_idx++] = t->val;
        t = t->next;
    }
    
    while (l1_idx && l2_idx){
        tmp = l1_arr[--l1_idx] + l2_arr[--l2_idx] + c;
        if (tmp > 9){
            tmp %= 10;
            c = 1;
        } else {
            c = 0;
        }
        
        sum_arr[sum_idx++] = tmp;
    }

    while (l1_idx){
        tmp = l1_arr[--l1_idx] + c;
        if (tmp > 9){
            tmp %= 10;
            c = 1;
        } else {
            c = 0;
        }
        
        sum_arr[sum_idx++] = tmp;
    }
    
    while (l2_idx){
        tmp = l2_arr[--l2_idx] + c;
        if (tmp > 9){
            tmp %= 10;
            c = 1;
        } else {
            c = 0;
        }
        
        sum_arr[sum_idx++] = tmp;
    }

    
    if (c){
        sum_arr[sum_idx++] = c;
    }
    
    struct ListNode *p = NULL;
    for (i = 0; i < sum_idx; i++){
        t = calloc(1, sizeof(struct ListNode));
        t->val = sum_arr[i];
        t->next = p;
        
        p = t;
    }
    
    return t;
}