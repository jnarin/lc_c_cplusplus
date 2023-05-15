/*
Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Problem: 1721. Swapping Nodes in a Linked List
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static int countNodes(struct ListNode *head){
    int ans = 0;
    struct ListNode *t = head;
    
    while (t){
        t = t->next;
        ans++;
    }
    
    return ans;
}

static void copyList2Array(struct ListNode *head, int *arr, int size){
    struct ListNode *t = head;
    int i = 0;
    
    while (t){
        arr[i++] = t->val;
        t = t->next;
    }
    
    return;
}

static void copyArray2List(struct ListNode *head, int *arr, int size){
    struct ListNode *t = head;
    int i = 0;
    
    while (t){
        t->val = arr[i++];
        t = t->next;
    }
    
    return;
}

struct ListNode* swapNodes(struct ListNode* head, int k){
    
    int num_nodes = countNodes(head);
    
    int arr[num_nodes];
    memset(arr, 0, sizeof(arr));
    
    copyList2Array(head, arr, num_nodes);
    
    int t = arr[k - 1];
    arr[k -  1] = arr[num_nodes - k];
    arr[num_nodes - k] = t;

    copyArray2List(head, arr, num_nodes);
    
    return head;
}