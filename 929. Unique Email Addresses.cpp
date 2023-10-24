/*
 * Link: https://leetcode.com/problems/unique-email-addresses/
 * Problem: 929. Unique Email Addresses
 * */

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;

        for (auto &e : emails){
            string t;
            int i = 0;
            bool gotLocalName = false;

            while (i < e.length()){
                // Skip . in local name
                if (e[i] == '.' && gotLocalName == false){
                    i++;
                    continue;
                }

                // Ignore all text after + till @ in local name
                if (e[i] == '+' && gotLocalName == false){
                    while (i < e.length() && e[i] != '@'){
                        i++;
                    }
                }

                if (i == e.length()){
                    break;
                }

                // Do not skip characters in domain name
                if (e[i] == '@'){
                    gotLocalName = true;
                }

                t += e[i];
                i++;
            }

            s.insert(t);
        }

        return s.size();
    }
};
