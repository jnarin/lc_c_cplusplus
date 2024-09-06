/*
Problem: 3217. Delete Nodes From Linked List Present in Array
Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_NUM_VAL (100001)

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* prev = NULL;
    struct ListNode* temp = NULL;
    int i, set[MAX_NUM_VAL] = {0};

    for (i = 0; i < numsSize; i++) {
        set[nums[i]] = 1;
    }

    while(current) {
        if(set[current->val]) {
            if(prev == NULL) {
                temp = current;
                current = current->next;
                head = current;
            } else {
                temp = current;
                current = current->next;
                prev->next = current;
            }
            
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}
