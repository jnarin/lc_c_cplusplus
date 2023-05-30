/*
Link: https://leetcode.com/problems/design-hashset/
Problem: 705. Design HashSet
*/
#define MAX_VAL (1003)

class MyHashSet {
public:
    MyHashSet() {
        v.resize(MAX_VAL);
        
    }
    
    void add(int key) {
        if (contains(key)){
            return;
        }
        
        v[key % MAX_VAL].push_back(key);
        
        return;
    }
    
    void remove(int key) {
        int idx = key % MAX_VAL;
        auto it = find(v[idx].begin(), v[idx].end(), key);
        if (it == v[idx].end()){
            return;
        }
        
        v[idx].erase(it);
        
        return;
    }
    
    bool contains(int key) {
        int idx = key % MAX_VAL;
        
        return find(v[idx].begin(), v[idx].end(), key) == v[idx].end() ? false : true;
    }
private:
    vector<vector<int>> v;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */