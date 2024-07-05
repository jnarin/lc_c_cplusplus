/*
Problem: 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
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
#define MINVAL(a, b) (((a) < (b)) ? (a) : (b))

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int *ans = calloc(2, sizeof(int));
    *returnSize = 2;
    
    int minDistance = INT_MAX, f, p, idx;
    f = p = -1;
    idx = 1;
    
    struct ListNode *prev, *curr;
    prev = head;
    curr = head->next;
    
    while (curr->next) {
        if ((curr->val > prev->val && curr->val > curr->next->val) 
            || (curr->val < prev->val && curr->val < curr->next->val)) {
            f = f == -1 ? idx : f;
            minDistance = p != -1 ? MINVAL(minDistance, idx - p) : minDistance;
            p = idx;
        }
        
        prev = curr;
        curr = curr->next;
        idx++;
    }
    
    if (minDistance == INT_MAX) {
        ans[0] = ans[1] = -1;
    } else {
        ans[0] = minDistance;
        ans[1] = p - f;
    }
    
    return ans;
}