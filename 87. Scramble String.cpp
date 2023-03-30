/* 
Link: https://leetcode.com/problems/scramble-string/
Problem: 87. Scramble String
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {

		if (s1 == s2){
			return true;
		}
		
		if (s1.length() != s2.length()){
			return false;
		}
		
        	int len = s1.length();
		string s1s2 = s1 + '.' + s2;
		if (m.find(s1s2) != m.end()){
			return m[s1s2];
		}
		
		int char_count[26] = {0}, i;
        	char c1, c2;
		for (i = 0; i < len; i++){
			c1 = s1[i] - 'a';
			c2 = s2[i] - 'a';
            		assert(c1 >= 0 && c1 < 26);
            		assert(c2 >= 0 && c2 < 26);
			char_count[c1]++;
			char_count[c2]--;
		}
        
        	for (i = 0; i < 26; i++){
            		if (char_count[i] != 0){
                		m[s1s2] = false;
                		return false;
            		}
        	}
		
		for (i = 1; i < len; i++){
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
				m[s1s2] = true;
				return true;
			}
			
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))){
				m[s1s2] = true;
				return true;
			}
		}
		
		m[s1s2] = false;
		return false;
    }
private:
	unordered_map<string, bool> m;
};
