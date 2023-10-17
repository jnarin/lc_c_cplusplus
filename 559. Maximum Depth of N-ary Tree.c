/*
Link: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
Problem: 559. Maximum Depth of N-ary Tree
*/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
#define MAXVAL(a, b)\
({  __typeof__(a) _a = (a);\
    __typeof__(b) _b = (b);\
    _a > _b ? _a : _b;  })

int maxDepth(struct Node* root) {
    int i, ans = 0;
    
    if (root != NULL){
        for (i = 0; i < root->numChildren; i++){
            ans = MAXVAL(ans, maxDepth(root->children[i]));
        }
        
        ans += 1;
    }
    
    return ans;
}