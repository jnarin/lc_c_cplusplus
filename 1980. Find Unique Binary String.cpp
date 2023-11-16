/*
Link: https://leetcode.com/problems/find-unique-binary-string/
Problem: 1980. Find Unique Binary String
Note: "1980. Find Unique Binary String.c" has a better approach than this method.

*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
		if (nums.size() == 0) {
			return "";
		}
		
        for (auto it : nums){
			m_[it]++;
		}
		
		char set[] = {'0', '1'};
		int n = 2;
		int k = nums[0].length();		
		generate_all_values(set, "", n, k);
		
		for (auto it : s_){
			if (m_.find(it) == m_.end()) {
				return it;
			}
		}
		
		return "";
    }
	
private:

	unordered_map<string, int> m_;
	vector<string> s_;
	void generate_all_values(char set[], string prefix,
                                    int n, int k)
	{
		 
		// Base case: k is 0,
		// print prefix
		if (k == 0)
		{
			s_.push_back(prefix);
			return;
		}
	 
		// One by one add all characters
		// from set and recursively
		// call for k equals to k-1
		for (int i = 0; i < n; i++)
		{
			string newPrefix;
			 
			// Next character of input added
			newPrefix = prefix + set[i];
			 
			// k is decreased, because
			// we have added a new character
			generate_all_values(set, newPrefix, n, k - 1);
		}
	 
	}

	
};