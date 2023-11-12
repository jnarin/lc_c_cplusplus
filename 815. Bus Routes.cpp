/*
 * Link: https://leetcode.com/problems/bus-routes/
 * Problem: 815. Bus Routes
 * */

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int ans = 0, s, i, route;

        if (source == target){
            return ans;
        }

        unordered_map<int, vector<int>> graph;
        unordered_set<int> usedBuses;
        queue<int> q;

        for (i = 0; i < routes.size(); i++){
            for (auto &it : routes[i]){
                graph[it].push_back(i);
            }
        }

        q.push(source);

        while (q.size()){
            ans++;

            s = q.size();
            while(s){
                route = q.front();
                q.pop();

                for (auto &bus : graph[route]){
                    if (usedBuses.insert(bus).second){
                        for (auto &nextRoute : routes[bus]){
                            if (nextRoute == target){
                                return ans;
                            } else {
                                q.push(nextRoute);
                            }
                        }
                    }
                }

                s--;
            }
        }

        return -1;
    }
};

