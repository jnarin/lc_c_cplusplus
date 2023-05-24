/*
Link: https://leetcode.com/problems/maximum-subsequence-score/
Problem: 2542. Maximum Subsequence Score
*/

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans, sum;
        ans = sum = 0;
        
        vector<pair<int, int>> v;
        priority_queue<int, vector<int>, greater<>> pq;
        
        int i;
        
        for (i = 0; i < nums1.size(); i++){
            v.push_back({nums2[i], nums1[i]});
        }
        
        sort(v.begin(), v.end(), greater<>());
        
        for (auto &it : v){
            pq.push(it.second);
            sum += it.second;
            
            if (pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k){
                ans = max(ans, sum * it.first);
            }
        }
        
        
        return ans;
    }
};