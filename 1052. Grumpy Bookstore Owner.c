/*
Problem: 1052. Grumpy Bookstore Owner
Link: https://leetcode.com/problems/grumpy-bookstore-owner/
*/

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int u = 0, i;
    
    for (i = 0; i < minutes; i++) {
        u += (customers[i] * grumpy[i]);
    }
    
    int m = u;
    
    for (i = minutes; i < customersSize; i++) {
        u += (customers[i] * grumpy[i]);
        u -= (customers[i - minutes] * grumpy[i - minutes]);
        
        m = u > m ? u : m;
    }
    
    int ans = m;
    for (i = 0; i < customersSize; i++) {
        ans += customers[i] * (1 - grumpy[i]);
    }
    
    return ans;
}