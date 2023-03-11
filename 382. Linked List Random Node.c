/* 
Link: https://leetcode.com/problems/linked-list-random-node/ 
Problem: 382. Linked List Random Node 
Approach:
1. Make a copy of head for reference
2. Initialize PRNG
3. Iterate through list and get a random node
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


typedef struct {
    struct ListNode *head;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution *obj = calloc(1, sizeof(Solution));
    obj->head = head;
    srand(time(NULL));
    
    return obj;
}

int solutionGetRandom(Solution* obj) {
    struct ListNode *t = obj->head;
    int ans = 0, n;
    if (t){
        ans = t->val;
        for (n = 0; t; n++){
            ans = ((rand() % (n + 1)) == n) ? t->val : ans;
            
            t = t->next;
        }
    }
    
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);    
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
