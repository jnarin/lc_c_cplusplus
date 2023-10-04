/*
Link: https://leetcode.com/problems/design-hashmap/
Problem: 706. Design HashMap
*/
class MyHashMap {
public:
    MyHashMap() {
        v_.resize(keyVal_);
    }
    
    void put(int key, int value) {
        int h = getHash(key), i;
        
        if (v_[h].size()){
            for (i= 0; i < v_[h].size(); i++){
                if (v_[h][i].first == key){
                    v_[h][i].second = value;
                    return;
                }
            }
        }
        
        v_[h].push_back({key, value});
    }
    
    int get(int key) {
        int ret = -1, h = getHash(key), i;
        
        if (v_[h].size()){
            for (i = 0; i < v_[h].size(); i++){
                if (v_[h][i].first == key){
                    ret = v_[h][i].second;
                    break;
                }
            }
        }
        
        return ret;
        
    }
    
    void remove(int key) {
        int i, h = getHash(key);
        if (v_[h].size()){
            for (i = 0; i < v_[h].size(); i++){
                if (key == v_[h][i].first){
                    v_[h].erase(v_[h].begin() + i);
                    break;
                }
            }
        }
    }
    
private:
    vector<vector<pair<int, int>>> v_;
    const int keyVal_ = 1009;
    
    int getHash(const int n){
        return n % keyVal_;
    }
    
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */