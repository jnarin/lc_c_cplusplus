/*
Problem: 648. Replace Words
Link: https://leetcode.com/problems/replace-words/
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        string ans = "";
        int i = 0, len = sentence.length(), j;
        
        while (i < len) {
            string currentWord = "";
            
            while (i < len && sentence[i] != ' ') {
                currentWord += sentence[i];
                
                if(s.find(currentWord) != s.end()) {
                    while (i < len && sentence[i] != ' ') {
                        i++;
                    }
                    
                    break;
                }
                
                i++;
            }
            
            if (i < len && sentence[i] == ' ') {
                currentWord +=  " ";
            }
            
            ans += currentWord;
            
            i++;
        }
        
        return ans;        
    }
};