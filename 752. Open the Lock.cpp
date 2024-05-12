/*
 * Problem: 752. Open the Lock
 * Link: https://leetcode.com/problems/open-the-lock/
 * */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }

        unordered_set<string> s;

        for(auto &it : deadends) {
            if (it == "0000") {
                return -1;
            }

            s.insert(it);
        }

        int ans = 0;
        queue<string> q;
        q.push("0000");

        while (q.size()) {
            ans++;

            for (int sz = q.size(); sz > 0; sz--){
                auto w = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    char c = w[i];

                    w[i] = w[i]== '9' ? '0' : w[i] + 1;

                    if (w == target) {
                        return ans;
                    }

                    if (s.count(w) == 0) {
                        q.push(w);
                        s.insert(w);
                    }

                    w[i] = c;

                    w[i] = w[i] == '0' ? '9' : w[i] - 1;

                    if (w == target) {
                        return ans;
                    }

                    if (s.count(w) == 0) {
                        q.push(w);
                        s.insert(w);
                    }

                    w[i] = c;
                }
            }
        }

        return -1;
    }
};
