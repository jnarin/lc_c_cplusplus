/*
Problem: 726. Number of Atoms
Link: https://leetcode.com/problems/number-of-atoms/
*/

class Solution {
public:
    string countOfAtoms(string formula) {
        string ans;
        int i = 0;
        
        for (auto& [elem, freq] : parse(formula, i)) {
            ans += elem;
            if (freq > 1) {
                ans += to_string(freq);
            }
        }
        
        return ans;
    }

    private:
    map<string, int> parse(string& s, int &i) {
        map<string, int> count;
        
        while (i < s.length()) {
            if (s[i] == '(') {
                for (auto& [elem, freq] : parse(s, ++i)) {
                    count[elem] += freq;
                } 
            } else if (s[i] == ')') {
                int num = getNum(s, ++i);
                for (auto&& [_, freq] : count) {
                    freq *= num;
                }

                return count;
            } else {
                const string& e = getElem(s, i);
                int num = getNum(s, i);
                count[e] += num;
            }

        }
        
        return count;
    }

    string getElem(string& s, int& i) {
        int eStart = i++;
        while (i < s.length() && (s[i] >= 'a' && s[i] <= 'z')) {
            i++;
        }
        
        return s.substr(eStart, i - eStart);
    }
    
    int getNum(string& s, int& i) {
        int numStart = i;
        while (i < s.length() && (s[i] >= '0' && s[i] <= '9')) {
            i++;
        }
        
        const string& numStr = s.substr(numStart, i - numStart);
        return numStr.length() ? stoi(numStr) : 1;
    }
        
    
};
