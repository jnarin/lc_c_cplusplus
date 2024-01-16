/*
Link: https://leetcode.com/problems/insert-delete-getrandom-o1/
Problem: 380. Insert Delete GetRandom O(1)
*/

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()){
            return false;
        }

        v.emplace_back(val);
        m[val] = v.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()){
            return false;
        }

        if (v.back() == val){
            v.pop_back();
            m.erase(val);
        } else {
            int idx = m[val];
            m.erase(val);
            v[idx] = v.back();
            v.pop_back();
            m[v[idx]] = idx;
        }

        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];        
    }

private:
    unordered_map<int, int> m;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */