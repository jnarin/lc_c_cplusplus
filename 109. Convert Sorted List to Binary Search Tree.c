/* 
Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
Problem: 109. Convert Sorted List to Binary Search Tree
Approach:
1. Count number of nodes in sorted list
2. Copy list into temporary array
3. Convert array into BST (using recursion)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MID_VAL(a, b) (((a) & (b)) + (((a) ^ (b)) >> 1))

static struct TreeNode *arrayToBST(int *nums, int numsSize, int l, int r){
    int mid;
    
    if (l > r){
        return NULL;
    }
    
    mid = MID_VAL(l, r);
    assert(mid < numsSize);
    
    struct TreeNode *node = calloc(1, sizeof(struct TreeNode));
    assert(node);
    
    node->val = nums[mid];
    node->left = arrayToBST(nums, numsSize, l, mid - 1);
    node->right = arrayToBST(nums, numsSize, mid + 1, r);
    
    return node;
}

static void convertListToArray(struct ListNode *node, int *nums, int numsSize){
    struct ListNode *t = node;
    int i = 0;
    
    while (t){
        assert(i < numsSize);
        nums[i++] = t->val;
        t = t->next;
    }
}

static int countNodes(struct ListNode * node){
    struct ListNode *t = node;
    int c = 0;
    while (t){
        c++;
        t = t->next;
    }

    return c;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    /* 1. Count number of nodes in sorted list */
    int nodeCount = countNodes(head);
    if (head == NULL || nodeCount < 1){
        return NULL;
    }
    
    /* 2. Copy list into temporary array */
    int tempArr[nodeCount];
    convertListToArray(head, tempArr, nodeCount);
    
    /* 3. Convert array into BST (using recursion) */    
    return arrayToBST(tempArr, nodeCount, 0, nodeCount - 1);
}
