/*
Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
Problem: 2130. Maximum Twin Sum of a Linked List
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
        ans++;
        t = t->next;
    }
    
    return ans;
}

static void copyList2Arr(struct ListNode *head, int *arr, int sz){
    struct ListNode *t = head;
    int idx = 0;
    
    while (t){
        arr[idx++] = t->val;
        t = t->next;
    }
}

int pairSum(struct ListNode* head){
    assert(head);
    int n = countNodes(head);
    
    int arr[n];
    memset(arr, 0, sizeof(arr));
    
    copyList2Arr(head, arr, n);
    
    int i, ans = INT_MIN, t;
    
    for (i = 0; i < n / 2; i++){
        t = arr[i] + arr[n - i - 1];
        ans = t > ans ? t : ans;
    }
    
    return ans;

}